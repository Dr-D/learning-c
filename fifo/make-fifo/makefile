CFLAGS=-Wall

all: writer mkfifo

writer: writer.c
	cc $(CFLAGS) -o writer writer.c

mkfifo: mkfifo.c
	cc $(CFLAGS) -o mkfifo mkfifo.c

.PHONY: clean
clean:
	-rm writer mkfifo
