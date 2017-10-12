main: main.o mymath.o
	cc main.o mymath.o -o main

main.o: main.c mymath.h
	cc -c main.c -o main.o

mymath.o: mymath.c
	cc -c mymath.c -o mymath.o

clean:
	rm *.o main
