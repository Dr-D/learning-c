DEPS=mserver.c client.c main.c
OBJS=mserver.o client.o main.o
CFLAGS=-Wall

main: mserver.o
	cc $(CFLAGS) -pthread -o main main.o mserver.o -lpthread

client: $(OBJS)
	cc $(CFLAGS) -pthread -o client client.o -lpthread

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main client $(OBJS)
