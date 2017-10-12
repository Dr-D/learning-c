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

Directly moving the command line above into a makefile and giving it a target will work
```
main:
	cc main.c -o main
```

