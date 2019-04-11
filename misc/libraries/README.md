# libraries

The header files are e.g. stdio.h (/usr/include/stdio.h) contain the prototype methods. The compiled code is held within libraries e.g  /lib/x86_64-linux-gnu/libc.so.6 (symbolic link to libc-2.23.so).

These usually end in .so = Shared Object or .a = Archive. The archive type libraries end up statically linked to your program. That is the code is actually embedded into your final executable. Shared object libraries are referenced by your final executable, this means your final code is smaller but may depend on a specific version of the library.

As for the libc.so.6 the number is the major version number and there will often be a symbolic link that has no number that links to the versions library.

To create an archive user ar
```
man ar
ar -cr libmymath.a add.o subtract.o product.o
```

c - Create archive
r - Insert the files

Will create archive libmylib.a.

Then use ranlib to generate index to archive
```
man ranlib
ranlib libmymath.a
```

To view the files from an archvie in a 'table' with v modifier.
```
ar -t libmymath.a
ar -tv libmymath.a
```

When compling the location to look for libraries can be added and for headers use -I.
```
cc -o mainlib main.o -L. -lmymath
```

Finding installed libraries, you can use ldconfig the -p prints list of directories and libraries in the current cache. 
```
man ldconfig
ldconfig -p
ldconfig -p | grep libc.so
```

Where can libraries be installed. ldconfig as above -v shows directories without a leading tab and the libraries in the directories have a leading tab. 
```
ldconfig -v | grep -v $'\t'
```

When executing the application it will need the shared object library to be available.
One way to do this is to export LD_LIBARY_PATH=/path/to/sharedobject/dir:$LD_LIBRARY_PATH.

Try doing: objdump -p main
This shows the private headers for an executable file
Should show this section: 
Dynamic Section:<br>
  NEEDED               libmy.so <br>
  NEEDED               libc.so.6 <br>
