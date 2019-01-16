CC=cc
OBJDIR=obj
_OBJS=main.o mymath.o myprint.o myrand.o
OBJS=$(patsubst %,$(OBJDIR)/%,$(_OBJS))

HEAD=mymath.h myprint.h myrand.h
CFLAGS=-Wall

$(OBJDIR)/%.o: %.c $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS) $(CCOPTS)

main: $(OBJS) $(HEAD)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(CCOPTS)

.PHONY: clean
clean:
	$(RM) main $(OBJDIR)/*.o

