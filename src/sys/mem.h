#pragma once
#include "types.h"


void* kmalloc(size_t size);
void kmemset(char* start, size_t size, char ch);
void kfree(void* ptr);
