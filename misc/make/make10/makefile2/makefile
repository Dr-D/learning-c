CC=cc
OBJDIR=obj
_OBJS=main.o mymath.o myprint.o myrand.o
OBJS=$(patsubst %,$(OBJDIR)/%,$(_OBJS))

HEADDIR=include
_HEAD=mymath.h myprint.h myrand.h
HEAD=$(pathsubst %,$(HEADDIR)/%,$(_HEAD))

SRCDIR=src
BINDIR=bin

CFLAGS=-Wall -I$(HEADDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	$(CC) -c -o $@ $< $(CFLAGS) $(CCOPTS)

$(BINDIR)/main: $(OBJS) $(HEAD)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(CCOPTS)

.PHONY: clean
clean:
	$(RM) $(BINDIR)/main $(OBJDIR)/*.o

