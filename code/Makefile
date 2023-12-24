CC = gcc
CFLAGS = -Wall -fsanitize=address
LIBFLAGS = -L. -l:lib.a
DOCFLAGS =

SRCDIR = src
OBJDIR = obj
DOCDIR = doc

SRCS = $(filter-out main.c, $(wildcard $(SRCDIR)/*.c))
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: program lib.a


program: main.o lib.a
	$(CC) $(CFLAGS) -o $@ main.o $(LIBFLAGS)


lib.a: $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : execute
.PHONY : documentation
.PHONY : clean

execute: program
	./program

documentation : 
	mkdir -p $(DOCDIR) 
	doxygen $(DOCFLAGS) Doxyfile


clean:
	rm -rf $(OBJS) $(OBJDIR) program lib.a doc main.o 
