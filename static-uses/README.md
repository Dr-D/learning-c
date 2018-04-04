# Static

There look to be three common usages of static in c.

## Static function
When static is used on a function it makes that function only available to be called by code within the same file.

## Static variable - file
When static is used on a variable that variable is only visible to functions within the same file.
So instead of being a global variable it becomes 'file local'. 

## Static variable - within a function
This is a more interesting usage of static where a variable within a function is set as static. That variable then retains its value on each call to that function. The usual example is as a counter where an int is incremented by one each time the method is called.

---
## When to use
I can think that the first two are useful to hide code that should not be available to code outside that file. For example helper methods that are specific to the code in that file and are not designed to be used else where.
