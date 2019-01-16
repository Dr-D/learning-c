# make5

## makefile1
The makefile has now been updated to use a variable similar to how bash variables work.
First we set the variable which it at the top of the file.

```bash
CC=cc
```

The CC variable is then used in the recipes
```bash
 $(CC) -c -o $@ $^
```

#Things to try
If you have gcc installed then try swapping the compiler CC=gcc.
Now we only have to make the change in one place and it will update the compiler in both places.

## makefile2

As seen using variables is useful when there is repetition as per the compiler above.

In the second makefile we create a variable with a list of the object files we are creating.
The list is space separated and basically looks exactly like it was written in the previous files.

The main target could be replaced with a varaiable but it is unlikely that main will be used anywhere else so at the moment will be left as it is.
