DEPS=main.c properties.c  trim.c
OBJS=main.o properties.o  trim.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS)

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
