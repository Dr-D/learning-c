# make4

## makefile1
The makefile has been updated with pattern recognition. When we run make the first target in the file
%.o: %.c executes first. 

```bash
make

cc -c -o main.o main.c
cc -c -o mymath.o mymath.c
cc main.o mymath.o -o main
```

The recipe iterates through the files in the folder ending with '.c' and creates files ending with '.o'.

This line as previously
```c
cc -c -o $@ $^
```
determines what is compiled and what is output. So for main.c we have pattern matched
main.o: main.c as the target and dependencies.

The '$@' tells the recipe to use what is on the left of the : i.e. main.c.
The '$^' tells the recipe to use everything on the left of the : i.e. main.o
So the line being executed is cc -c -o main.o main.c

The recipe then moves onto the next file mymath.o: mymath.c and finally the main target executes.

## makefile2

We apply the same changes to the main target recipe
```bash
main: main.o mymath.o
        cc -o $@ $^
```

The '$@' uses what is on the left of the : i.e. main
The '$^' uses everything on the right of : i.e. main.o mymath.o
So the line being executed is cc -o main main.o mymath.o

The make file is now much tidier than previously and will also now be much more versatile as we will see.
