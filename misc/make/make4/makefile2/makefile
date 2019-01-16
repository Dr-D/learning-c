%.o: %.c
	cc -c -o $@ $^

main: main.o mymath.o
	cc -o $@ $^

.PHONY: clean
clean:
	-rm *.o main
