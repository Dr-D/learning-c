# memory mapped file

Simple example of using memory mapped file.

Open the file

```
man 2 open
```

Use posix_fallocate or similar to make sure file it big enough. Was giving a Segmentation fault and then  Bus Error if the file size was not big enough.

Do the mapping with mmap, make sure PROT_WRITE is used if you want to do a write.

```
man mmap
```

The example program opens a file that already has text in. So if the file is set as read only the file is mapped to memory and would allow fast access to data. In this case we are also writing to the mapped memory.
