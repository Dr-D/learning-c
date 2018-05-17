DEPS=main.c
OBJS=main.o
CFLAGS=-Wall
LDFLAGS=-lssl -lcrypto

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS) $(LDFLAGS)

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
