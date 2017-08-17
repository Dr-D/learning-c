# Basic Void Pointers

Passing values to a method that takes void*.

We are using int value of 97 because it is the value of char 'a'.

Pointers are all the same size, which is why we can have functions that use void*.

The get_int(...) function is doing a cast to an int pointer.

The get_char(...) function does not do a direct cast, but as pointers are all the same size the void pointer can be any type of pointer.

Another example of where this is used is using malloc to reserve memory on the heap.
```
char *pchar1 = (char*)malloc(sizeof(char));
char *pchar2 = malloc(sizeof(char));
```

Both do the same thing. Check the manual
```
man 3 malloc

void *malloc(size_t size); 
```
we can see that malloc returns a void*.



