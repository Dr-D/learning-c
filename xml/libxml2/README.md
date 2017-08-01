# libxml2
Simple example of using libxml2 to create an XML document. Has a parent node with content which is also the root node and child node with content.

Install the libxml2 libraries for ubuntu
```
sudo apt-get install libxml2-dev
```

Installs /usr/inlcude/libxml2/*.h header files
Installs libxml2.so.x.x.x library with symbolic links libxml2.so  libxml2.so.2

## makefile
Updated the make file to include the libxml2 headers when creating the object and uses the library when creating the executable.
```
main: $(OBJS)
        cc $(CFLAGS) -o main $(OBJS) -lxml2

$(OBJS): $(DEPS)
        cc $(CFLAGS) -c $(DEPS) -I /usr/include/libxml2
```
