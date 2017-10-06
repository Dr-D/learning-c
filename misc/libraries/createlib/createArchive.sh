#!/bin/bash

printf "Creating the archive file libmymath.a\n"
ar -cr libmymath.a add.o subtract.o product.o

printf "Using ranlib to index the archive.\n"
ranlib libmymath.a

printf "Examining the archive created:\n"

ar -tv libmymath.a

printf "Creating main.o\n"
cc -c -o main.o main.c

printf "Creating mainlib executable\n"
cc -o mainlib main.o -L. -lmymath
