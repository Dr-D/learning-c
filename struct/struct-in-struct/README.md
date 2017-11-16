# basic struct

Example of a struct within a struct.

Here the information for a persons address is kept in a different struct 'Address' but is associated with a `Person`.

## instances of struct
We can easily create multiple instances of `int` variables.
```c
int a, b, c;
``` 

The same can be done for structs.
```c
struct Person person, person2;
```

So person and person2 are actual 'instances' of struct Person like a, b, c are different integer variables.

## accessing a struct within a struct
The 'person' instance of Struct Person now has a struct Address available.
Setting the address is easy we can use `person.address = address;`.

We now want to get the value to print to the screen.`person.address` will get the address for person and then we want to get the number for that address.

This could be written as `(person.address).number` which is done for person.

It can be written as `person2.address.number` as shown for person2.

So if we wanted we could create another struct and use this withing struct Person
```c
struct Address {
  int number;
  char street[20];
  char town[20];

};

struct Contact {
  struct Address address;
  char home_phone[20];
  char home_phone[20];
};

struct Person {
  int age;
  char name[20];
  struct Contact contact;
};
```

So now we can use person.contact.address to get the address details i.e. we can nest structs within structs within structs ...
