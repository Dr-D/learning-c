# make1

## make without makefile
A handy feature of make that I read when learing about it is that you can use it without a makefile being present.

Create a source file main.c in your directory.
```
make main
```
You will see make automagically runs 'cc     main.c   -o main', that is it will create an executbale with the same name as the source file without you having to type anythin else in.

## first make file
Another useful thing to know when learning make is that it is not dependent on a c/c++ compiler. So when practicing creating a target and output files you can use touch or other bash commands that create files.
```
a:
        touch a
```
The target 'a:' must be on a line with no spaces/tabs before it.

