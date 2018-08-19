DEPS=mserver.c main.c
OBJS=mserver.o main.o
CFLAGS=-Wall

main: mserver.o
	cc $(CFLAGS) -pthread -o main main.o mserver.o -lpthread

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
