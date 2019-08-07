IDIR =inc
CC=gcc
CFLAGS=-I$(IDIR) -O2

ODIR=obj

SRCDIR=src

BINDIR=bin

LIBS=-lm

_DEPS = matrix.h tiled.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o tiled.o matrix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -std=c11 -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -std=c11 -o $(BINDIR)/main $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o  $(BINDIR)/*
