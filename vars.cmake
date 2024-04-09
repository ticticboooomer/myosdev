set(LIB_SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/sys/mem.c"
        "${CMAKE_SOURCE_DIR}/src/sys/term.c"
        "${CMAKE_SOURCE_DIR}/src/boot.asm"
        "${CMAKE_SOURCE_DIR}/src/sys/abort.c"
        "${CMAKE_SOURCE_DIR}/src/cpu/interrupts/idt.c"
        "${CMAKE_SOURCE_DIR}/src/cpu/interrupts/isr.asm"
        "${CMAKE_SOURCE_DIR}/src/cpu/gdt/gdt.c"
)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
enable_language(ASM_NASM)

set(CMAKE_C_COMPILER /home/kyleb/opt/cross/bin/i386-elf-gcc)
set(CMAKE_CXX_COMPILER /home/kyleb/opt/cross/bini386-elf-g++)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/src/linker.ld")
set(CMAKE_C_FLAGS "-m32 -ffreestanding -nostdinc -fno-builtin -nostdlib -nodefaultlibs")
set(CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} -nostdlib")
set(CMAKE_ASM_NASM_FLAGS " -f elf")

include_directories(${CMAKE_SOURCE_DIR}/src/)
