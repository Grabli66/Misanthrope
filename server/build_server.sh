if [ ! -d "build" ]; then
  mkdir build
fi

cd build
valac -C ../src/Main.vala ../src/Database/Database.vala --pkg=libgda-6.0
gcc Main.c Database.c \
    -I/usr/include/glib-2.0 \
    -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
    -I/usr/include/libgda-6.0 \
    -I/usr/include/libxml2 \
    -I/usr/include/libgda-6.0/libgda \
    -lglib-2.0 -lgobject-2.0 -lgda-6.0 \
    -o Main
