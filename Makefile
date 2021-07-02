CC=g++
LDFLAGS=-lcurl
GTEST_FLAGS=-lgtest -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

SRC_FILES=RingBuffer.cpp
TEST_FILES=TestRingBuffer.cpp
CPP_FLAGS+= -DFULL_FLAG_IMPLEMENTATION

.PHONY: test coverage check

all: test coverage check

test:
	$(CC) $(SRC_FILES) $(TEST_FILES) $(LDFLAGS) $(GTEST_FLAGS) $(CPP_FLAGS) -o gtest

coverage:
		$(CC) $(SRC_FILES) $(TEST_FILES) $(LDFLAGS) $(GTEST_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) -o gtest
		./gtest
		gcov $(SRC_FILES)
		lcov -c --directory . --output-file main_coverage.info
		genhtml main_coverage.info --output-directory out
		firefox out/index.html &

check:
	cppcheck --enable=all $(SRC_FILES)
