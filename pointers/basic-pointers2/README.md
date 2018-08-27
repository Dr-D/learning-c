# Basic Pointers2 - point struct

Simple example of passing variables by pointer.

Here we create a sinmple point struct that has an x and y value.
The variable is created on the heap using malloc.

We then pass the point by reference to each function in the point.h.

From doing a bit more c prgramming the libraries often use a convention of 'name_<function>' or 'name<function>'.
For example pthread_create, pthread_join in the posix thread library.
The string library uses strcpy, strdup, strtok.
Usually best to use one and stick with it but be prepared to change is you a working on someone else library.





