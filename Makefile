CC=g++
LDFLAGS=-lcurl

SRC_FILES=RingBuffer.cpp
TEST_FILES=TestRingBuffer.cpp

GTEST_FLAGS=-lgtest -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
.PHONY: test check

all: test

test:
	$(CC) $(SRC_FILES) $(TEST_FILES) $(LDFLAGS) $(GTEST_FLAGS)  -o gtest

coverage:
	$(CC) $(SRC_FILES) $(TEST_FILES) $(LDFLAGS) $(GTEST_FLAGS) $(GCOV_FLAGS) -o gtest
	./gtest
	gcov $(SRC_FILES)
	lcov -c --directory . --output-file main_coverage.info
	genhtml main_coverage.info --output-directory out
	firefox out/index.html &

check:
	cppcheck --enable=all $(SRC_FILES) $(TEST_FILES)

