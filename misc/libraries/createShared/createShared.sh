#!/bin/bash

printf "Creating PIC(position independent code) object files\n"
gcc -c -fPIC add.c -o add.o
gcc -c -fPIC subtract.c -o subtract.o
gcc -c -fPIC product.c -o product.o

printf "Creating the shared object file libmymath.so\n"
gcc add.o subtract.o product.o -shared -o libmath.so

printf "Examining the .so file nm\n"
nm -D libmath.so

printf "Examining the .so file objdump\n"
objdump -T libmath.so

printf "Copying libmath to '/usr/lib/'\n"
cp libmath.so /usr/lib

printf "Creating mainshared executable\n"
gcc -o mainshared main.c -lmath

printf "Examining mainshared executable with ldd\n"
ldd mainshared

printf "Running mainshared executable\n"
./mainshared

printf "Deleting libmath.so from '/usr/lib/'\n"
rm /usr/lib/libmath.so
