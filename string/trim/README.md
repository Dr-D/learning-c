# string trim

An example of trimming a string, this is my implementaion using a bit of trial and error. I am sure there are better ways to do this.

Uses the isspace() we could probably do this check ourselves or create our own isspace method
```
man isspace
```

The trim function takes a source and destination value. If we passed a string on the heap i.e. a malloced string we could manipulate it in place but this would not work with a string const.

The code is commented to be fairly self explantory, I have left in the  printf statements so that you can see what the strings look like at each point.

We essentially move the pointer of the source string forwards if it starts with spaces.
We will then be at the first non space character or the end of the string.
If we are not at the end of src we must have non-space characters. We copy the rest of src to the destination string.
If we have an empty string at this point just return.
We are now at the end of the string i.e. the '\0' char. We move backwards if we have space characters and as we know we do not have an empty string it is safe to move the pointer back. If this was an empty string we would be moving into unknown territory.

The main issue is if the string is all space chars which will return an empty string, we just need to be careful where the pointers are. We do not want to be trying to compare values that are not in the string.

## Examples
There are a few scenarios to try to make sure you are happy the trim function is working
correctly.
