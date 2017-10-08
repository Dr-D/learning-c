# Create Shared Object file

A shared object file (.so) is a type of library file. Shared object files are libraries that are used are runtime as opposed to archive(.a) libraries which are statically imported into an executable.

Run the createShared.sh bash script file using sudo to create the .so library.
```
sudo ./createShared.sh
```

The object files are created using gcc with -fPIC flag = postion independent code
The shared library is created using gcc with -shared flag.

Use nm or objdump to examine the shared object file.

Copy the shared object file to /usr/lib. This is one of the directories used by the linker to look for library files.

Create the executable using your shared object file.

Examine the executable with ldd. This shows a list of the shared object files being used by the executable. Should show your shared object in use.
```
libmath.so => /usr/lib/libmath.so (0x00007fd2a3370000)
```

Run the executable to make sure it is working.

Finally delete your library.

Try to run your executable again
```
./mainshared
```
Should now show an error that it cannot find your library file as we deleted it at the end of the shell script.
./mainshared: error while loading shared libraries: libmath.so: cannot open shared object file: No such file or directory
