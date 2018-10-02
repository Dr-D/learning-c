DEPS=mserver.c main.c mclient.c properties.c trim.c
OBJS=mserver.o main.o mclient.o properties.o trim.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -pthread -o main $(OBJS) -lpthread

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
