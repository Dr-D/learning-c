# make2

View the man entry for make
```
man make
```
Couple of things to note:
make expects a file called GNUmakefile, makefile or Makefile. This can be changed by using the -f <filename>

make updates a target if it depends on prerequisite files that have been modified since the target was last modified, or if the target does not exist.
	      
This last is why make is so useful when compiling many files and you have changed only one or two files. Make will only recompile those files that have changed and any files that depend on those files.

## Command line

A simple example of compiling on the command line
```
cc main.c -o main
```
You can then edit your main.c file and recompile by brining back the previous command (ctrl+p or up arrow).

## makefile1

Directly putting the command line above into a makefile and giving it a target will work:
```
main:
	cc main.c -o main
```

## makefile2

We now have a slightly more complex situation where we have two files.
In main.c we see
```
include "mymath.h".
```
My math.h has a prototype function that allows main.c to compile.
The compiled version of main.c now requires an implementation of the function called add.
When the mymath.c file is compiled it will provide this implementation.

We can compile these two files on the command line:
```
cc main.c mymath.c -o main
```
And again we can just put this in a makefile add a target and it will also work.
What we don't see is that the compiler is doing a lot of work for us that allows the executable to be created.

## makefile3
The man cc page is very long with **a lot ** of options. One of the most common options to use is:
```
-c  Compile or assemble the source files, but do not link.
```

Out new makefile shows a simple use of this compile but don't link option:
```
main: main.c mymath.o
        cc main.c mymath.o -o main

mymath.o: mymath.c
        cc -c mymath.c -o mymath.o
```

The main target now has a prerequisite the mymath.o file. This format is the most typical use of a target in a makefile
```
target: prerequisite
	recipe...
```

The main: target is now indicates it requires the main.c file which already exists and the mymath.o **object** file which does not exist yet. However make can see there is a target called mymath.o. so when you run make you will see:
```
cc -c mymath.c -o mymath.o
cc main.c mymath.o -o main
```
So make knows it must process the mymath.o: target first and then run the main: target.
The easiest way to show why this is useful is to delete the executable main file. Now run make again:
```
cc main.c mymath.o -o main 
```
So the above shows make is not having to process the mymath.o: target. The file is already present and from what we know previously it will not process a target if the file is already present.

The second situation to look at is when we change a file. Open main.c and delete the comment line 'delete this line and recompile'. Run make again and you will see the same thing that happened above only the main: target is processed. Here one of the prerequistes for main: target in this case 'main.c' has a timestamp that is newer than the target main: file. 

There is a bash command 'touch' that will change a files timestamp. Without chaning anything run make again to make sure it shows:
```
make: 'main' is up to date.
```
Then on the command line:
```
touch main
```
Then run make again and you will see only target main: is processed. 