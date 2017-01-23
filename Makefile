# Makefile -- Makefile for roman calculator library. 
# Copyright (C) 2017 Sunil <sunhick@gmail.com>
#
# This software may be modified and distributed under the terms
# of the MIT license.  See the LICENSE file for details.

# Commands
# Make file for roman calculator library
# make all : builds all (library + test)
# make clean : gets rid of all unwanted files from the system
# make tags : generate the etag file for code navigation
# make run: compile and run the test cases

IDIR = src/headers/
CC = gcc
CFLAGS = -I $(IDIR) -g

LIBS =
ODIR = obj
LDIR =
SRC = src/

_DEPS = rmcalc.h rmresult.h rmconv.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = rmcalc.o rmconv.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(OBJ)
	ar rcs librc.a $<


test:

run:

$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

#update/generate the etags file for easier code navigation
tags:
	find . \( -name "*.[ch]" -o -name "*.[ch]pp" \) -type f -print | etags -

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~