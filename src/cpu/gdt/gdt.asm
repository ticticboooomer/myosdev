global _gdt_flush     ; Allows the C code to link to this
extern _gdtr            ; Says that '_gp' is in another file
_gdt_flush:
    lgdt [_gdtr]        ; Load the GDT with our '_gp' which is a special pointer
    ;mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    ;mov ss, ax
    jmp 0x08:flush2   ; 0x08 is the offset to our code segment: Far jump!
flush2:
    ret