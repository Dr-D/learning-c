# make8

## makefile1
From previous file we are now using predifined $(RM) for removing files in the clean recipe.

We have added a $(CCOPTS) at the end of the lines that compile the code.

We can use this to add optional c compiler flags on the command line:
```bash
CCOPTS=-g make
cc -c -o main.o main.c -Wall -g
cc -c -o mymath.o mymath.c -Wall -g
cc -c -o myprint.o myprint.c -Wall -g
cc -c -o myrand.o myrand.c -Wall -g
cc -o main main.o mymath.o myprint.o myrand.o -Wall -g
```

Instead of just using make we have added a the compiler flag -g, as you can see the c compiler compiles successfully. The '-g' option produces debugging information which makes debugging work better in GDB.

You could add '-O' or '-O2' etc for code optimisation but not use the -g at same time as may cause the debugger to behave strangely. 

## makefile2
There is a minor change in this file that causes the first target %.o: %.c (HEAD) to stop running,
something similar happened when I was practicing using make.

The compiler still compiles main and appears to be working normally. You can probably work out what the issue is but I have added in some echo commands to show that the fist recipe is not executing.

```bash
cc -Wall   -c -o main.o main.c
cc -Wall   -c -o mymath.o mymath.c
cc -Wall   -c -o myprint.o myprint.c
cc -Wall   -c -o myrand.o myrand.c
echo recipe2
recipe2
cc -o main main.o mymath.o myprint.o myrand.o -Wall 
```

The echo executes correctly in the second recipe. Try using '@echo recipe2' instead.
You will see that it no longer echos the actual line in the recipe.

The actual issue can be seen is we add $(HEAD) to the second target.
'main: $(OBJS) $(HEAD)'

When make is now run and error message is seen:
```bash
make: *** No rule to make target 'myran.o', needed by 'main.o'.
```

The 'myrand.o' has been mistyped as 'myran.o' and the compiler can find no targets that can make this file so now fails.

Make files can get a lot more complicated than the one we have created so it is useful to be able to add @echo lines to recipes and you can echo variables to make sure they are what you are expecting.





