# make1

## make without makefile
A handy feature of make that I read when learing about it is that you can use it without a makefile being present.

Create a source file main.c in your directory.
```
make main
```
You will see make automagically runs 'cc     main.c   -o main', that is it will create an executbale with the same name as the source file without you having to type anythin else in.

## First makefile
Another useful thing to know when learning make is that it is not dependent on a c/c++ compiler. So when practicing creating a target and output files you can use touch or other bash commands that create files.
```
a:
        touch a
```
The target 'a:' must be on a line with no spaces/tabs before it.
The second line 'touch a' is the **recipe** for this target. A recipe can have one or more commands that a processed for a particular target.

You can use make to process the make file by just using
```
make
```
On the command line.

## Second makefile
The first line in this file is a comment line, as your files get more complex you will definitely want to use comments.

This makefile shows multiple targets, 'a:', 'b:' and 'c:'.

```
## Second makefile
a:
        touch a

b:
        echo "File b" >> b

c:
        touch a
```

Try using just:
```
make
```
You will see that it does 'touch a' which will create a file named a. If you have multiple targets in a makefile make will process the first target in the file. To run the other targets use:
```
make b
make c
```
Of course you can also run target 'a:' by using 'make a' as well but why go to the extra effort.

### File target 
Try running make or 'make a' twice you should see: 
```
make: `a' is up to date.
```

Try running 'make c' twice
```
make c
touch a
make c
touch a
```

Make is treating the target 'a:' as a file target. Make checks to see if there is a file named 'a'
and on finding the file does not need to process the recipe.
The target 'c:' on the other hand makes a file named 'a' and as it never finds a file named 'c' it will always process the recipe.
