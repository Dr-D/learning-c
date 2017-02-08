#Write array to file

Write an array of structs to file and read them back again.

After you have run the executable try to view the contents of the file.

```
cat test.bin
```

You should find that the file contains the text information but does not show all the information for the struct. Try using something like emacs to open the file and you should see other information in the file not seen using cat.

```
man 3 fwrite
```

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

This method takes a pointer, when using arrays the variable name of the array is basically a pointer to the start of the array.

Improve things - could use and array of pointers rather than array of structs, need to free the memory used on the heap.