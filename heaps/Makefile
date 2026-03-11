CC = gcc
CFLAGS = -Wall -Wextra -g -I.

TARGET = heap_demo
TEST_TARGET = heap_test

SRCS = heap.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): main.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) main.o $(OBJS)

$(TEST_TARGET): test_heap.o $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) test_heap.o $(OBJS)

%.o: %.c heap.h
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

.PHONY: all clean test run
