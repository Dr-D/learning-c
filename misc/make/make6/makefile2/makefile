CC=cc
OBJS=main.o mymath.o
HEAD=mymath.h
#CFLAGS=

%.o: %.c $(HEAD)
	$(CC) -c -o $@ $< -Wall

main: $(OBJS)
	$(CC) -o $@ $(OBJS) -Wall

.PHONY: clean
clean:
	-rm *.o main
