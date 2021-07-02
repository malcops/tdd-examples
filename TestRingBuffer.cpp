#include "RingBuffer.hpp"
#include "gtest/gtest.h"

TEST(TestRingBuffer, initialize){
    RingBuffer rb = RingBuffer(5);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.maxCapacity(), 5);
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert1Value){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    rb.insert(x);
    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 1);
}

TEST(TestRingBuffer, insert5Values){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    unsigned y = 2;
    unsigned z = 3;
    unsigned j = 4;
    unsigned k = 5;
    rb.insert(x);
    rb.insert(y);
    rb.insert(z);
    rb.insert(j);
    rb.insert(k);
    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_TRUE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 5);
}

TEST(TestRingBuffer, insert1ValuePop1Value){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    rb.insert(x);
    ASSERT_EQ(rb.pop(), x);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert5ValuesPop5Values){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    unsigned y = 2;
    unsigned z = 3;
    unsigned j = 4;
    unsigned k = 5;
    rb.insert(x);
    rb.insert(y);
    rb.insert(z);
    rb.insert(j);
    rb.insert(k);

    ASSERT_EQ(rb.pop(), x);
    ASSERT_FALSE(rb.bufferFull());

    ASSERT_EQ(rb.pop(), y);
    ASSERT_EQ(rb.pop(), z);
    ASSERT_EQ(rb.pop(), j);
    ASSERT_EQ(rb.pop(), k);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert5ValuesAndReset){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    unsigned y = 2;
    unsigned z = 3;
    unsigned j = 4;
    unsigned k = 5;
    rb.insert(x);
    rb.insert(y);
    rb.insert(z);
    rb.insert(j);
    rb.insert(k);

    rb.resetBuffer();
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.maxCapacity(), 5);
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert1ValuePop1ValueInsert5Values){
    RingBuffer rb = RingBuffer(5);
    unsigned x = 1;
    unsigned y = 2;
    unsigned z = 3;
    unsigned j = 4;
    unsigned k = 5;
    unsigned p = 6;
    rb.insert(x);
    rb.pop();
    rb.insert(y);
    rb.insert(z);
    rb.insert(j);
    rb.insert(k);
    rb.insert(p);

    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_TRUE(rb.bufferFull());
    ASSERT_EQ(rb.maxCapacity(), 5);
    ASSERT_EQ(rb.numberOfElements(), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
