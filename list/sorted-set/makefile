DEPS=main.c node.c
OBJS=main.o node.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS)

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
