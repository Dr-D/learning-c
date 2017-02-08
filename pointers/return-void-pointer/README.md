#Return Void Pointer

This is slighlty more complicated in that we have a method that takes a void* and also returns a void*.

We are using int value of 97 because it is the value of char 'a'. Both get_int and get_char are returning a void*. This return values are set as int* and char* pointers and the values are used in printf.

```
man 3 pthread_create

#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

```

The third parameter is a pointer to a function that returns a void* and takes a single void* parameter.
The fourth parameter is a void pointer that is passed into the start_routine function.



