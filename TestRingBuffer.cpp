#include "RingBuffer.hpp"
#include "gtest/gtest.h"


TEST(TestRingBuffer, initialize){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
    ASSERT_EQ(rb.getHeadIdx(), 0);
    ASSERT_EQ(rb.getTailIdx(), 0);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.maxCapacity(), 5);
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert1Value){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
    unsigned x = 1;
    rb.insert(x);
    ASSERT_EQ(rb.getBufferAt(0), x);
    ASSERT_EQ(rb.getHeadIdx(), 0);
    ASSERT_EQ(rb.getTailIdx(), 1);
    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 1);
}

TEST(TestRingBuffer, insert5Values){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
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
    ASSERT_EQ(rb.getBufferAt(0), x);
    ASSERT_EQ(rb.getBufferAt(1), y);
    ASSERT_EQ(rb.getBufferAt(2), z);
    ASSERT_EQ(rb.getBufferAt(3), j);
    ASSERT_EQ(rb.getBufferAt(4), k);
    ASSERT_EQ(rb.getHeadIdx(), 0);
    ASSERT_EQ(rb.getTailIdx(), 0);
    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_TRUE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 5);
}

TEST(TestRingBuffer, insert1ValuePop1Value){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
    unsigned x = 1;
    rb.insert(x);
    ASSERT_EQ(rb.pop(), x);
    ASSERT_EQ(rb.getHeadIdx(), 1);
    ASSERT_EQ(rb.getTailIdx(), 1);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert5ValuesPop5Values){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
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
    ASSERT_EQ(rb.getHeadIdx(), 1);
    ASSERT_EQ(rb.getTailIdx(), 0);
    ASSERT_FALSE(rb.bufferFull());

    ASSERT_EQ(rb.pop(), y);
    ASSERT_EQ(rb.pop(), z);
    ASSERT_EQ(rb.pop(), j);
    ASSERT_EQ(rb.pop(), k);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBuffer, insert5ValuesAndReset){
    RingBuffer<unsigned> rb = RingBuffer<unsigned>(5);
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
    ASSERT_EQ(rb.getHeadIdx(), 0);
    ASSERT_EQ(rb.getTailIdx(), 0);
    ASSERT_TRUE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.maxCapacity(), 5);
    ASSERT_EQ(rb.numberOfElements(), 0);
}

TEST(TestRingBufferFloat, insert1Value){
    RingBuffer<float> rb = RingBuffer<float>(5);
    float x = 1.2;
    rb.insert(x);
    ASSERT_EQ(rb.getBufferAt(0), x);
    ASSERT_EQ(rb.getHeadIdx(), 0);
    ASSERT_EQ(rb.getTailIdx(), 1);
    ASSERT_FALSE(rb.bufferEmpty());
    ASSERT_FALSE(rb.bufferFull());
    ASSERT_EQ(rb.numberOfElements(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
