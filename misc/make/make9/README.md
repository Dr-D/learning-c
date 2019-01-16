# make8

## makefile1
From the previous file the echo line has been removed from the first recipes.
The main target has $(HEAD) added to make sure we are compiling correctly.

Note that a new folder obj has been created.

The OBJS variable has now changed and is using $(patsubs ...).
This is a make function that does pattern matching with substitution.

If we break down what is happening in this line OBJS=$(patsubst %, obj/%,$(_OBJS)):
To call a make methid we have to use this syntax $(functionName p1,p2,...,pn).
So we use the function name first then a list of comma separated parameters.

For the patsubst function the first parameter is the pattern we want to find, which is determined by the % sign. Here we are pattern matching the complete/unchanges value of the list item i.e. 'main.o'

This value is then used in the second parameter and we are adding 'obj/' in front of it.
So we end up for the first value with 'obj/main'.

The last parameter is the list we want the pattern substition to work on which is '_OBJS'.
When make is run:

```bash
cc -c -o obj/main.o main.c -Wall 
cc -c -o obj/mymath.o mymath.c -Wall 
cc -c -o obj/myprint.o myprint.c -Wall 
cc -c -o obj/myrand.o myrand.c -Wall 
OBJS: [obj/main.o obj/mymath.o obj/myprint.o obj/myrand.o]
cc -o main  obj/main.o  obj/mymath.o  obj/myprint.o  obj/myrand.o -Wall
```
The echo in main target recipe shows that the files are now all in 'obj/'.

The first target has had to be updated with 'obj/' in front of the '%.o'.
The clean target has also been update to make sure we are cleaning the correct files.

### Pattern matching explained a bit more 
All the object files are '*.o' files so a pattern like '%.o' could be used to use all items in the provided list that end in '.o'. i.e. OBJS=$(patsubst %.o,obj/%,$(_OBJS)). This will not work as shown here.

If we just use % then the whole value is used in the second parameter.
The first value in the list is main.o when using '%' we pattern match 'main.o'.

if we use '%.o' then the pattern match is just on the part before the '.o'
The first value in the list is main.o when using '%.o' we pattern match 'main' only.

As long as you understand this then we can update the OBJS variable:
OBJS=$(patsubst %,obj/%.o,$(_OBJS))

So for main.o the second parameter now is main we prefix it with 'obj/' and add '.o' to the end, to end up with 'obj/main.o'.

## Things to do
The object directory is used in three places so is reasonable to use a variable for this.
Update the makefile to use an object directory variable.

## makefile2
The makefile has been update to use a variable for the object directory.

When I want to see changes to files in a directory and sub directories I use the bash 'tree' command.
This can be install in ubuntu with:
```bash
sudo apt-get install tree
```

Do a 'make clean' initially and then run 'tree' on the command line.
```bash
$make clean
rm main obj/*.o
$tree
.
├── main.c
├── makefile
├── mymath.c
├── mymath.h
├── myprint.c
├── myprint.h
├── myrand.c
├── myrand.h
└── obj

1 directory, 8 files
$
```

You can see that the files in the current directory and the obj directory is empty.
Now run 'make' and then 'tree' on the command line.

```bash
$make
... # removed lines for brevity
cc -o main obj/main.o obj/mymath.o obj/myprint.o obj/myrand.o -Wall 
$tree
.
├── main
├── ... #removed lines for brevity
└── obj
    ├── main.o
    ├── mymath.o
    ├── myprint.o
    └── myrand.o

1 directory, 13 files
```

The obj directory now contains the object files and when we run the 'clean' target they are removed.

## Things to do
The source files are usually in a directory named 'src'.
The header files are usually in a directory named 'include'.

You will need to create these directories then move the '*.c' files into src and the '*.h' files into include.
Then try to update the makefile to use these directories, it will be very similar to what has already been done with the object/'*.o' files.










