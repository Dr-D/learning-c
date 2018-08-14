DEPS=server.c client.c
OBJS=server.o client.o
CFLAGS=-Wall

server: client
	cc $(CFLAGS) -pthread -o server server.o -lpthread

client: $(OBJS)
	cc $(CFLAGS) -pthread -o client client.o -lpthread

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm server client $(OBJS)
