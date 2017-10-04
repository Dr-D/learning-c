# libraries

The header files are e.g. stdio.h (/usr/include/stdio.h) contain the prototype methods. The compiled code is held within libraries e.g  /lib/x86_64-linux-gnu/libc.so.6 (symbolic link to libc-2.23.so).
These usually end in .so or .a. As for the libc.so.6 the number is the major version number and there will often be a symbolic link that has no number that links to the versions library.

To create an archive user ar
```
man ar
ar -cr libmymath.a add.o subtract.o product.o
```

c - Create archive
r - Insert the files

Will create archive libmylib.a.

Then use  ranlib to generate index to archive
```
man ranlib
ranlib libmymath.a
```

To view the files from an archvie in a 'table' with v modifier.
```
ar -t libmymath.a
ar -tv libmymath.a
```

When compling the location to look for libraries can be added
```
cc -o main.o -L. -lmymath main.c
```

