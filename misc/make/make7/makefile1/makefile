CC=cc
OBJS=main.o mymath.o myprint.o myrand.o
HEAD=mymath.h myprint.h myrand.h
CFLAGS=-Wall

%.o: %.c $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

.PHONY: clean
clean:
	-rm *.o main
