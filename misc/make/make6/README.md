# make4

## makefile1
A HEAD variable has been added that contains a list of the header files.

The '$^'' symbol cannot be used as it used everything on the right of the :
So if we try to call make using this in the recipe we get an error
```bash
cc -c -o main.o main.c mymath.h
cc: fatal error: cannot specify -o with -c, -S or -E with multiple files
```

What we can use instead is '$<' which means use the first value on the right of the :
```bash
 $(CC) -c -o $@ $<
```

Why do we want to add the header files to the recipe for creating the object files?
If a header file is now updated then the object files will also be recompiled.

## makefile2

In this second file we have added a compiler option -Wall, this gets the compiler to show warnings.
I have added a variable to the main.c that is set to value 0 but is never used any where else.

```bash
main.c: In function ‘main’:
main.c:7:7: warning: unused variable ‘unusedInteger’ [-Wunused-variable]
   int unusedInteger = 0;
       ^~~~~~~~~~~~~
```

When the make file is executed the recipes still work but we now get a warning about the unused variable.

The other thing is a commented out line
```bash
#CFLAGS=
```

This is similar to comments in a bash script file.
CFLAGS is usually a fairly standard variable that stands for compiler flags.

#Things to do
The -Wall is repeated so it is left to just uncomment the CFLAGS variable and set it with correct value and use it in the recipes.
