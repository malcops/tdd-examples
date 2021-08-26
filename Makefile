CC=g++
CFLAGS=-std=c++11
LDFLAGS=-lcurl
GTEST_FLAGS=-lgtest -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

.PHONY: golf ringbuffer
all: golf ringbuffer

golf:
	$(CC) GolfHandicap.cpp TestGolfHandicap.cpp $(CFLAGS) $(LDFLAGS) $(GTEST_FLAGS) -o gtest

ringbuffer:
	$(CC) RingBuffer.cpp TestRingBuffer.cpp $(LDFLAGS) $(GTEST_FLAGS) -DFULL_FLAG_IMPLEMENTATION -o gtest


# coverage:
# 		$(CC) $(SRC_FILES) $(TEST_FILES) $(LDFLAGS) $(GTEST_FLAGS) $(CPP_FLAGS) $(GCOV_FLAGS) -o gtest
# 		./gtest
# 		gcov $(SRC_FILES)
# 		lcov -c --directory . --output-file main_coverage.info
# 		genhtml main_coverage.info --output-directory out
# 		firefox out/index.html &

# check:
# 	cppcheck --enable=all $(SRC_FILES)
