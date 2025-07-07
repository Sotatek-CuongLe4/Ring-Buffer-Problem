``` bash
# Project Structure
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
# Build
mkdir build
cd build
cmake ..
make
# Run demo
./main
# Run tests
./test_ringbuffer