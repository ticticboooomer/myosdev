#include "idt.h"
#include "sys/term.h"

__attribute__((aligned(0x10)))
static idt_entry_t idt[256];

static idtr_t idtr;

void exception_handler() {
  term_write("crashed", 7);
  asm volatile("cli; hlt");
}

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];
 
    descriptor->isr_low        = (uint32_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08; // this value can be whatever offset your kernel code selector is in your GDT
    descriptor->attributes     = flags;
    descriptor->isr_high       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}

extern void* isr_stub_table[];

void idt_init() {
  idtr.base = (uint32_t)&idt[0];
  idtr.limit = (uint16_t)sizeof(idt_entry_t) * 256 - 1;

  for (uint8_t vector = 0; vector < 32; vector ++) {
    idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
  }

  asm volatile("lidt %0" : : "m"(idtr));
  asm volatile("sti");
}
