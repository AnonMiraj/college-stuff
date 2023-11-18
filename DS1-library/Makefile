CC = g++
CFLAGS = -std=c++11
OBJS = book.o catalog.o main.o 
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# DynamicContainer.o: DynamicContainer.cpp DynamicContainer.h
	# $(CC) $(CFLAGS) -c DynamicContainer.cpp

book.o: book.cpp book.h
	$(CC) $(CFLAGS) -c book.cpp

catalog.o: catalog.cpp catalog.h
	$(CC) $(CFLAGS) -c catalog.cpp

main.o: main.cpp DynamicContainer.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(EXEC)

