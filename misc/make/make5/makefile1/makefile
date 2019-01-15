CC=cc

%.o: %.c
	$(CC) -c -o $@ $^

main: main.o mymath.o
	$(CC) -o $@ $^

.PHONY: clean
clean:
	-rm *.o main
