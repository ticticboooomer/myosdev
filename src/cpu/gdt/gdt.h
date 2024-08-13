#pragma once

#include "sys/types.h"

typedef struct {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
}  __attribute__((packed)) gdt_entry_t;

typedef struct {
    unsigned short limit;
    unsigned int base;
}  __attribute__((packed)) gdtr_t;

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

void gdt_assemble();


