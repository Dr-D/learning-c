# linker - ld

The c compiler (cc) does a lot of work for you when creating an executable.

## makefile1
The linker is used to create the final executable file. It is called by the c compiler but can be called manually.

Attempt one to create a main file, but does not find where to start.
```
ld -lc main.o -o main
```

Attempt two after some searching. But trying to run the exectuable shows a message that a file cannot be found but no indication which file.
```
ld -lc main.o  mymath.o -o main --entry main
```

Using readelf on the non working file 
```
readelf -l main
```
Shows this line however these is no such file.
[Requesting program interpreter: /lib/ld64.so.1]

Attempt three works 
```
ld -lc main.o --dynamic-linker /lib64/ld-linux-x86-64.so.2 mymath.o -o main --entry main
```

However there are other object files that may be required.
/usr/lib/crt1.o /usr/lib/crti.o /usr/lib/crtn.o
