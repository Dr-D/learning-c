# make8

## makefile1
Header files have been moved to the include directory.

A new variable HEADDIR has been added that is set as include.
The patsubst function is used to update the HEAD files.

The only other change is that we need to let the compiler know where to find the header files.
```bash
CFLAGS=-Wall -I$(HEADDIR)
```

When we substitue the HEADDIR it looks like CFLAGS=-Wall -Iinclude

## Things to do
The last thing to do is move the '*.c' files into a src directory.

## makefile2
The '*.c' files have been moved to the src directory.

The 'main' executable file is now put in bin directory.
