#$NBody: Makefile 2015/06/06
#----------------------------------------------------------------------------
#<jygchen@gmail.com> wrote this file.  As long as you retain this notice you
#can do whatever you want with this stuff. If we meet some day, and you think
#this stuff is worth it, you can buy me some swiss, chedder or brie cheese in
#return (and maybe a bottle of wine too).   Junying Chen
#----------------------------------------------------------------------------

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR := $(dir $(lastword $(MKFILE_PATH)))
CC = clang
CFLAGS = -I/usr/X11R6/include -I/usr/local/include
HEADER = -lm -lGL -lGLU -lGLEW -lglut
LIBS = -L/usr/lib -L/usr/X11R6/lib -L/usr/local/lib

ODIR = $(ROOT_DIR)obj

DEPS = main.h

_OBJ = auxillary.o draw.o main.o mass.o mechanics.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

nbody: $(OBJ)
	$(CC) -g -o $@ $^ $(HEADER) $(LIBS) $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ROOT_DIR)*core $(ODIR)/*.o
