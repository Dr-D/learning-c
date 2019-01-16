CC=cc
OBJS=main.o mymath.o

%.o: %.c
	$(CC) -c -o $@ $^

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.PHONY: clean
clean:
	-rm *.o main
