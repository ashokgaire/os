#ifndef KHEAP_H
#define KHEAP_H

#include <stdint.h>
#include <stddef.h>

void kheap_init();
void kfeee(void* ptr);
void* kmalloc(size_t size);
#endif