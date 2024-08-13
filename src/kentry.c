#include "sys/mem.h"
#include "sys/term.h"
#include "sys/abort.h"
#include "cpu/interrupts/idt.h"
#include "cpu/gdt/gdt.h"

extern void kernel_main(void) {
    gdt_assemble();
    idt_init();
    term_init();
    term_write("sosig", 5);
    for (;;) {}
}
