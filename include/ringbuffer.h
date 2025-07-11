#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

void ringbuffer_init(int size);
int ringbuffer_add(int value);
int ringbuffer_remove(int* value);
int ringbuffer_is_full();
int ringbuffer_is_empty();
int ringbuffer_size();

#ifdef __cplusplus
}
#endif

#endif