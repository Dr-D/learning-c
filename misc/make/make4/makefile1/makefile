%.o: %.c
	cc -c -o $@ $^

main: main.o mymath.o
	cc main.o mymath.o -o main

.PHONY: clean
clean:
	-rm *.o main
