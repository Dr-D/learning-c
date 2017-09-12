# memory mapped file

Simple example of using memory mapped file.

Open the file

```
man 2 open
```

Use posix_fallocate or similar to make sure file it big enough. Was giving a Bus Error is the file size was not big enough.

Do the mapping with mmap, make sure PROT_WRITE is used if you want to do a write.

```
man mmap
```
