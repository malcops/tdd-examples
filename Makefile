CC=g++
LDFLAGS=-lcurl
GTEST_FLAGS=-lgtest -lpthread

.PHONY: test example timelapse

all: test example timelapse

test:
	$(CC) RingBuffer.cpp TestRingBuffer.cpp $(LDFLAGS) $(GTEST_FLAGS) -o gtest

example:
	$(CC) main.cpp RingBuffer.cpp $(LDFLAGS) -o example 

