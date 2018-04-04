# Static Variable in Function

This is an example of using a static variable in a function.

st_int is declared and initialised with value 0;
Then is incremented on each call to the function so that the output is 0 to 9.
If the static modifier is removed then st_int will always be 0 when it is printed.

The second function shows a string being used as the static variable.
It also shows that a pointer to the static variable can be used to obtain the contents of that static variable and set the contents.

str was allocated memory on the heap and is now pointing to the static variable so we can no longer free the original memory allocated on the heap, hence the commented out line.

We could 'return text' to give a pointer to the static variable thus avoiding the free issue above, but still seems like bad use of this static variable.