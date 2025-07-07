Ring Buffer Library
Thread-safe ring buffer implementation in C++ with C API.
Structure
RingBuffer/
├── CMakeLists.txt
├── README.md
├── src/
│   └── ringbuffer.cpp
├── include/
│   └── ringbuffer.h
├── test/
│   └── test_ringbuffer.cpp
└── main.cpp
Build
bashmkdir build
cd build
cmake ..
make
Run
bash# Run demo
./main

# Run tests
./test_ringbuffer
