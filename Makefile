CC=g++
LDFLAGS=-lcurl
GTEST_FLAGS=-lgtest -lpthread

.PHONY: test check

all: test

test:
	$(CC) RingBuffer.cpp TestRingBuffer.cpp $(LDFLAGS) $(GTEST_FLAGS) -o rbtest
	$(CC) GolfHandicap.cpp TestGolfHandicap.cpp $(LDFLAGS) $(GTEST_FLAGS) -o golftest

check:
	cppcheck --enable=all  RingBuffer.cpp TestRingBuffer.cpp

