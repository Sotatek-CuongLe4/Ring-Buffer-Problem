#include "ringbuffer.h"
#include <mutex>
#include <cstring>
#include <stdexcept>

#define RINGBUFFER_MAX_CAPACITY 128

// C++-only variables
static int buffer[RINGBUFFER_MAX_CAPACITY];
static int head = 0;
static int tail = 0;
static int count = 0;
static int capacity = 0;
static std::mutex mtx;

// API functions need extern "C"
extern "C" {
void ringbuffer_init(int size) {
    std::lock_guard<std::mutex> lock(mtx);
    if (size <= 0 || size > RINGBUFFER_MAX_CAPACITY)
        throw std::invalid_argument("Invalid buffer size");
    head = tail = count = 0;
    capacity = size;
    std::memset(buffer, 0, sizeof(buffer));
}

int ringbuffer_add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (count == capacity)
        return -1;
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    ++count;
    return 0;
}

int ringbuffer_remove(int* value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (count == 0)
        return -1;
    *value = buffer[head];
    head = (head + 1) % capacity;
    --count;
    return 0;
}

int ringbuffer_is_full() {
    std::lock_guard<std::mutex> lock(mtx);
    return count == capacity;
}

int ringbuffer_is_empty() {
    std::lock_guard<std::mutex> lock(mtx);
    return count == 0;
}

int ringbuffer_size() {
    std::lock_guard<std::mutex> lock(mtx);
    return count;
}

}  // extern "C"