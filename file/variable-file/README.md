# Write variable to file

Write an variable in this case integer to file and read it back again.

After you have run the executable try to view the contents of the file.

```
cat text.bin
```

You should find that the file looks empty i.e. there is no text visible, the number has been written to the file using a binary stream.

Look at the manual for the methods that do the write and reading to file.

```
man 3 fwrite
```

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

This method takes a pointer, the size of the item being pointed to, the number of items (used when passing in an array) and a file descriptor.