DEPS=main.c
OBJS=main.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS) $(shell mysql_config --libs)

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
