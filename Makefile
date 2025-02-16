# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Executable name
TARGET = bin/main

# Object files
OBJECTS = bin/main.o bin/convert.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ -lm

bin/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

bin/convert.o: src/convert.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)