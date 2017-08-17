# My Single link list2

Having seen a bit more c this is more inline with how c lists work.
A struct cannot contain a concrete instance of itself i.e. you cannot do this
```
struct Node {
       char text[20];
       struct Node link;
};
```

You have to do this 
```
struct Node {
       char text[20];
       struct Node *link; /*This is a pointer to a struct*/
};
```
