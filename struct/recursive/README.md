# recursive struct

Simple example of a recursive struct.

In this case the struct `Person` holds a char name[20] and a pointer link to a person.

## Cannot use the same struct within a struct 
Here we create struct Person tnat 

```c
struct Person {
  char name[20];
  struct Person link;
};
```
When we try to compile this:
```
main.c:7:17: error: field ‘link’ has incomplete type
   struct Person link;
                 ^
make: *** [main.o] Error 1

So we cannot just put a struct Person within struct Person.

## Reference to same struct

First we create three instances of a struct `struct Person mickey, minnie, donal;` and set the name for each of these.

We then set the link for minnie to point to the instance donald.
We then set the link for mickey to point to the instance minnie.
If we then print out the values for mickey we can see that minnie is accessible from the link in mickey. The link for minnie is also accessible from mickey and in this case is donald.

The link for donald has not been set so should no be used as will point to an invalid reference.

This is essentially how a singly linked list works in c, the first value in the list mickey has a reference to the next value in the list minnie and then minnie has a reference to the next value in the list donald and so on ...

## Reference to same struct instance
Next we make mickey link to mickey so that we we get the the link name and the link->link name it will always be the same.