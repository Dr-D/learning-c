# Basic Thread

Simple example of posix thread.

```
man 3 pthread_create

#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

Compile and link with -pthread.
```

Creating a thread the first parameter is a pointer to a pthread_t variable.

The second parameter pthread_attr * is set to NULL in this case.

The third parameter is harder to work out. Returns a void* and takes a single parameter (void *). The (*start_routine) is a pointer to a function. Which in c is just the name of the function.

The forth(last) parameter is void * i.e. a void pointer which means it can take a pointer of any type. This the value that is passed into the *start_routine, we have set this to NULL in this case. But as it can take a pointer to any type a struct can be passed through.

The library -pthread is required to create the executable, view the makefile to see where this is used.
A simple command line compile without make would be ```cc -pthread main.c```.


