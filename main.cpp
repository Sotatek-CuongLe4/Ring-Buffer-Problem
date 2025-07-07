#include <iostream>
#include "ringbuffer.h"

int main() {
    ringbuffer_init(5);

    ringbuffer_add(10);
    ringbuffer_add(20);

    int value;
    if (ringbuffer_remove(&value) == 0) {
        std::cout << "Removed: " << value << std::endl;
    }

    return 0;
}