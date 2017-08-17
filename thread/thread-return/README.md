# Thread with Message

Simple example of posix thread that returns a struct.

```
man 3 pthread_join

#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);

Compile and link with -pthread.
```

The return value is a void pointer to a pointer, in the code:
```
void *void_return;
pthread_join(thread, &void_return);
```
We create a void pointer and pass it through by reference and the return value is then cast to a struct Thread_Return. 

Improvements the Thread_Message and Thread_Return can be same struct. Free heap memory.