DEPS=main.c
OBJS=main.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -o main $(OBJS) -lmysql

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
