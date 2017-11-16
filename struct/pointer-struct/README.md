# pointer to struct

Simple example of a struct pointer.

In this case the struct `Person` holds an int age and char name[20] for a person.

First we create an instance of a struct `struct Person person`.

We then show the size of each of the parts of the struct and the size of the whole struct. From this we can see how a pointer knows how to store and access the parts of a struct.
The struct is made up of an integer value and a string value with a fixed length, an instance of a struct Person will always have the same size i.e. the same amount of memory is always reserved for a an instance of struct Person.

## pointer
A pointer to an integer can be created like so:
```c
int i;
int *pi = &i;
```

So exactly the same thing can be done for a struct.

## de-referencing
If we want to get the actual value for the integer pointer pi above we can use:
```c
printf("val: '%d'\n", *pi);
```

So the same can be done for a struct `*p_person` and in this case we use '(*p_person).name'.
There is a neater way to dereference a struct pointer and get information from the struct value.
So when we print the age we use `p_person->age` which does the de-reference and returns the age.   