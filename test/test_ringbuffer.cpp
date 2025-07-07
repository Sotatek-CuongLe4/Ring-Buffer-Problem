#include <gtest/gtest.h>
extern "C" {
    #include "ringbuffer.h"
}

TEST(RingBufferTest, AddAndRemove) {
    ringbuffer_init(3);
    EXPECT_EQ(ringbuffer_add(1), 0);
    EXPECT_EQ(ringbuffer_add(2), 0);
    int value;
    EXPECT_EQ(ringbuffer_remove(&value), 0);
    EXPECT_EQ(value, 2);
}
