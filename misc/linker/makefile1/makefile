main: main.o mymath.o
	ld -lc main.o --dynamic-linker /lib64/ld-linux-x86-64.so.2 mymath.o -o main --entry main

main.o: main.c mymath.h
	cc -c main.c -o main.o

mymath.o: mymath.c
	cc -c mymath.c -o mymath.o

.PHONY: clean
clean:
	-rm *.o main
