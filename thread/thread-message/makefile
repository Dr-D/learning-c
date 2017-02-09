DEPS=main.c Thread_Message.c
OBJS=main.o Thread_Message.o
CFLAGS=-Wall

main: $(OBJS)
	cc $(CFLAGS) -pthread -o main $(OBJS)

$(OBJS): $(DEPS)
	cc $(CFLAGS) -c $(DEPS)

.PHONY: clean
clean:
	-rm main $(OBJS)
