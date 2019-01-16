CC=cc
_OBJS=main.o mymath.o myprint.o myrand.o
OBJS=$(patsubst %,obj/%,$(_OBJS))

HEAD=mymath.h myprint.h myrand.o
CFLAGS=-Wall

obj/%.o: %.c $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS) $(CCOPTS)

main: $(OBJS) $(HEAD)
	@echo OBJS: [$(OBJS)]
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(CCOPTS)

.PHONY: clean
clean:
	$(RM) main obj/*.o

