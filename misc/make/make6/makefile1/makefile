CC=cc
OBJS=main.o mymath.o
HEAD=mymath.h

%.o: %.c $(HEAD)
	$(CC) -c -o $@ $<

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.PHONY: clean
clean:
	-rm *.o main
