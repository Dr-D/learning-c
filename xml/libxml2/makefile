DEPS=main.c
OBJS=main.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS) -lxml2

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS) -I /usr/include/libxml2

.PHONY: clean
clean:
	-rm main $(OBJS)
