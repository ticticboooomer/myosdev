cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_SYSTEM_NAME "Generic" CACHE STRING "Target system.")

project(os)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
enable_language(ASM_NASM)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/src/linker.ld")
set(CMAKE_C_FLAGS "-m32 -ffreestanding -nostdinc -fno-builtin -nostdlib -nodefaultlibs")
set(CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} -nostdlib")

add_executable(kernel.bin "src/kentry.c" "src/sys/mem.c" "src/boot.asm" "src/sys/term.c")
set_target_properties(kernel.bin PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
