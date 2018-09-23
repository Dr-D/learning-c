# Configuration File

So you need a configuration file to hold some changeable values.
This is a simple implementation of how to read a space separated configration file.
Each line contains a single 'Property' which must be of this format:
```
<name> <value>
```

Note the maximum line size is #define as 255, as per the comment in the exmaple config file edit the long line of number to be bigger than 255 and watch it fail.

There is an example configuration file 'config** that has a few examples and was useful to try and test things, there are probably situtations I have not thought of.

#Thoughts
This turned out to be a lot bigger than I thought so is under Projects. I think it is a relativley simple first project to try. It uses a lot of the things learned in the examples:
* File - open and read it. Try updating it to pass a file name.
* structs - Single struct Property
* String - replace char and string trim - see examples of how to implement
* Pointers - to struct
* linked list - initially thought returning an array would be most useful but there are an unknown number of properties in a file so a linked list can be expanded easily.

* Maybe return number of properties in the linked list in properties_create() function as we can count them as they are created then properties_get(** to return the linked list?

* Decide when you want the configuration to fail. At the moment it is only when a line is too long. I think a name with no value may also be worth failing on because it is an invalid format, but you can decide.
