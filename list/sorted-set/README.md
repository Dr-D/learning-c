# Sorted Set

Wanted this for a project. Basically need to add/remove strings into a list but the list must be sorted and not contain any duplicates.

Keeping this as a single linked list so struct Node remains the same.

```
struct Node {
       char text[20];
       struct Node *link;
};

```

The logic for the adding to the list is within void add(char ** text) function.
Removing is simpler as we just have to swap a link from the object being removed to the nxt one in the list.

#Thoughts
This works but adding or removing nodes would take a long time if there is a large number of elements in the set.
A binary tree that can work as set would be faster.
