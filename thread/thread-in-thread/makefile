DEPS=main.c
OBJS=main.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -pthread -o main $(OBJS) -lpthread

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
