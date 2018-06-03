# string copy

An example of how to copy a string.

The first part of main shows how to copy using copies of pointers so that we do not move the original pointers.

strcopy uses a while loop.

strcopy2 is exactly the same just put into a for loop.
We already have copies of the string pointers so do not need to initialise any variables as we have to do in the non-method version at the start of main.
The loop ends when we get to the string terminator character '\0'.
The character is copied and we move to the next position in the strings. 

These simle methods are good examples of:
* Method parameters are copies of what is passed to them.
** When we print the final src & src2 strings the pointers are still at the start of the strings
* Pointer arithmetic - we are starting at the first character of the string and incrementing by one
** Each character is copied from the src to the destination.
