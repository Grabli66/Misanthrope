#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define DEVICE_NAME "/dev/video0"
#define ERROR_CODE -1
#define BUFFER_COUNT 4
#define SELECT_TIMEOUT 0
#define CAMERA_WIDTH 640
#define CAMERA_HEIGHT 480

typedef struct memory_buffer {
	void *buffer;
	size_t length;
} memory_buffer;

int camera_d = -1;
int frame_number = 0;
memory_buffer *buffers;

// Server address
struct sockaddr_in saddress;
int client_socket;

// Exit with error
void error_exit (const char *text)
{
	printf (text);
	exit (EXIT_FAILURE);
}

// Init socket for send data
void init_client_socket () {
    client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (client_socket == ERROR_CODE) error_exit ("Cant create client socket");
}

// Sends data to server
void send_data (unsigned char *data, size_t len) {
    
}

// Extended ioctl
int xioctl(int fh, int request, void *arg)
{
	int r;
	do {
		r = ioctl(fh, request, arg);
	} while (-1 == r && EINTR == errno);
	return r;
}

// Convert YUV 8 bit to RGB 24 bit
void YUV422toRGB888(int width, int height, unsigned char *src, unsigned char *dst)
{
	int line, column;
	unsigned char *py, *pu, *pv;
	unsigned char *tmp = dst;

	/* In this format each four bytes is two pixels. Each four bytes is two Y's, a Cb and a Cr.
	   Each Y goes to one of the pixels, and the Cb and Cr belong to both pixels. */
	py = src;
	pu = src + 1;
	pv = src + 3;

#define CLIP(x) ( (x)>=0xFF ? 0xFF : ( (x) <= 0x00 ? 0x00 : (x) ) )

	for (line = 0; line < height; ++line) {
		for (column = 0; column < width; ++column) {
			*tmp++ = CLIP((double)*py + 1.402*((double)*pv-128.0));
			*tmp++ = CLIP((double)*py - 0.344*((double)*pu-128.0) - 0.714*((double)*pv-128.0));
			*tmp++ = CLIP((double)*py + 1.772*((double)*pu-128.0));

			// increase py every time
			py += 2;
			// increase pu,pv every second time
			if ((column & 1)==1) {
				pu += 4;
				pv += 4;
			}
		}
	}
}

// Init memory mapping
void init_mmap ()
{
	struct v4l2_requestbuffers req;
	CLEAR(req);

	req.count = BUFFER_COUNT;
	req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory = V4L2_MEMORY_MMAP;

	if (xioctl (camera_d, VIDIOC_REQBUFS, &req) == ERROR_CODE) error_exit ("Cant init buffer");
	if (req.count < BUFFER_COUNT) error_exit ("Insuffient memory");

	buffers = calloc(req.count, sizeof(*buffers));
	if (!buffers) error_exit ("Insuffient memory");

	int i = 0;
	for (i = 0; i < BUFFER_COUNT; i++) {
		struct v4l2_buffer buf;
		CLEAR(buf);

		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		if (xioctl (camera_d, VIDIOC_QUERYBUF, &buf) == ERROR_CODE) error_exit ("Cant query buffer 1");
		buffers[i].buffer = mmap(NULL,
		                         buf.length,
		                         PROT_READ | PROT_WRITE,
		                         MAP_SHARED,
		                         camera_d, buf.m.offset);
		buffers[i].length = buf.length;

		if (buffers[i].buffer == MAP_FAILED) error_exit ("Cant init memory map");
	}
}

// Inititalize camera
void init_device ()
{
	// Open device
	camera_d = open (DEVICE_NAME, O_RDWR | O_NONBLOCK, 0);
	if (camera_d == ERROR_CODE) {
		printf ("Cant get camera device");
		exit (EXIT_FAILURE);
	}

	// Get camera capability
	struct v4l2_capability cap;
	if (xioctl (camera_d, VIDIOC_QUERYCAP, &cap) == ERROR_CODE) error_exit ("Cant get camera capabilities \n");
	printf ("Driver name: %s\n", cap.driver);

	if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) error_exit ("Device cant capture\n");

	struct v4l2_format fmt;
	CLEAR(fmt);
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width       = CAMERA_WIDTH; //replace
	fmt.fmt.pix.height      = CAMERA_HEIGHT; //replace
	//fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB24; //replace
	fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; //replace
	fmt.fmt.pix.field       = V4L2_FIELD_ANY;
	if (xioctl (camera_d, VIDIOC_S_FMT, &fmt) == ERROR_CODE) error_exit ("Cant apply capture format");
}

// Process image
void process_image(const void *dat, int size)
{
    frame_number++;
	unsigned char *src = (unsigned char*)dat;
	unsigned char *dst = malloc(CAMERA_WIDTH*CAMERA_HEIGHT*3*sizeof(char));
	YUV422toRGB888(CAMERA_WIDTH, CAMERA_HEIGHT, src, dst);

	int quality = 30;
    char filename[15];
    sprintf(filename, "frame-%d.jpg", frame_number);
	FILE *fd = fopen (filename, "wb");

	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

	jpeg_stdio_dest(&cinfo, fd);

	cinfo.image_width = CAMERA_WIDTH;
	cinfo.image_height = CAMERA_HEIGHT;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);
	jpeg_start_compress(&cinfo, TRUE);

	JSAMPROW row_pointer[1];
	int row_stride;
	row_stride = cinfo.image_width * 3;

	while(cinfo.next_scanline < cinfo.image_height) {
		row_pointer[0] = (JSAMPLE*)(dst + cinfo.next_scanline * row_stride);
		jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}

	jpeg_finish_compress(&cinfo);
	jpeg_destroy_compress(&cinfo);

	//free(scr);
	fclose (fd);

}

// Capture frame
void capture_frame ()
{
    struct v4l2_buffer buf;
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    
	for (int i = 0; i < BUFFER_COUNT; i++) {		
		CLEAR(buf);
		buf.type = type;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		if (xioctl (camera_d, VIDIOC_QBUF, &buf) == ERROR_CODE) error_exit ("Cant query buffer 2");
	}
	    
	if (xioctl (camera_d, VIDIOC_STREAMON, &(type)) == ERROR_CODE) error_exit("Cant open stream");

	int count = 20;

	while (count-- > 0) {
		fd_set fds;
		struct timeval tv;
		int r;

		FD_ZERO (&fds);
		FD_SET (camera_d, &fds);

		/* Timeout. */
		tv.tv_sec = 2;
		tv.tv_usec = 0;

		r = select(camera_d + 1, &fds, NULL, NULL, &tv);
		if (r == ERROR_CODE) error_exit ("Cant select descriptor");
		if (r == SELECT_TIMEOUT) error_exit ("Cant select descriptor");
        
		CLEAR(buf);
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		if (xioctl (camera_d, VIDIOC_DQBUF, &buf) == ERROR_CODE) error_exit ("Cant query buffer 3");

		process_image (buffers[buf.index].buffer, buffers[buf.index].length);

		if (xioctl (camera_d, VIDIOC_QBUF, &buf) == ERROR_CODE) error_exit ("Cant query buffer 4");
	}
}

// Close device
void close_device ()
{
	if (close (camera_d) == ERROR_CODE) {
		exit(EXIT_FAILURE);
	}
	camera_d = ERROR_CODE;

	for (int i = 0; i < BUFFER_COUNT; i++) {
		munmap (buffers[i].buffer, buffers[i].length);
	}

	free (buffers);
}

int main(int argc, char** argv)
{
	init_device ();
	init_mmap ();
	capture_frame ();
	close_device ();
	return EXIT_SUCCESS;
}
