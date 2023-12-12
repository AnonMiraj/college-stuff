CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Werror
OBJS = book.o catalog.o main.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)



clean:
	rm -f $(OBJS) $(EXEC)

