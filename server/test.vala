class AsyncDemo {

    private MainLoop loop;

    public AsyncDemo (MainLoop loop) {
        this.loop = loop;
    }

    public async void request () throws Error {
        try {            
            var resolver = Resolver.get_default ();
            var addresses = yield resolver.lookup_by_name_async ("localhost");
            var address = addresses.nth_data (0);
            
            var socket_address = new InetSocketAddress (address, 65200);
            var client = new SocketClient ();
            var conn = yield client.connect_async (socket_address);            
            uint8[] data = { 0x01,                                  // Pack ID 
                             0x00, 0x00, 0x00, 0x0A,                // Data len
                             0x02, 0x55,                            // U8 0x01 
                             0x01,                                  // Array
                             0x06,                                  // Len
                             0x33, 0x34, 0x35, 0x37, 0x45, 0x34 };  // Data

            yield conn.output_stream.write_async (data, Priority.DEFAULT);            
            conn.socket.set_blocking (true);

            var input = new DataInputStream (conn.input_stream);
            var message = input.read_line (null).strip ();
            print ("(async) received status line: %s\n", message);
        } catch (Error e) {
            stderr.printf ("%s\n", e.message);
        }

        this.loop.quit ();
    }
}

void main () {
    var loop = new MainLoop ();
    var demo = new AsyncDemo (loop);
    demo.request.begin ();
    loop.run ();
}
