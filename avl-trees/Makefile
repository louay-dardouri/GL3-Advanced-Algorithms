# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g -I.

# Target names
TARGET = avl_demo
TEST_TARGET = avl_test

# Source files
# We separate the core logic from the main/tester programs
SRCS = avl.c
OBJS = $(SRCS:.c=.o)

# Default rule (runs when you just type 'make')
all: $(TARGET)

# Rule to link the demo program
$(TARGET): main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) main.o $(OBJS)

# Rule to link the test program
# This allows you to have a separate file just for unit tests
$(TEST_TARGET): test_avl.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) test_avl.o $(OBJS)

# Pattern rule to compile .c files into .o files
%.o: %.c avl.h
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target to run the demo
run: all
	./$(TARGET)

# Phony target to build and run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Phony target to clean up the directory
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

.PHONY: all clean test run
