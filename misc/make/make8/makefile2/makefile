CC=cc
OBJS=main.o mymath.o myprint.o myrand.o
HEAD=mymath.h myprint.h myran.o
CFLAGS=-Wall

%.o: %.c $(HEAD)
	@echo recipe1
	$(CC) -c -o $@ $< $(CFLAGS) $(CCOPTS)

main: $(OBJS)
	echo recipe2 #try prefixing echo with an '@'
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(CCOPTS)

.PHONY: clean
clean:
	$(RM) main *.o

