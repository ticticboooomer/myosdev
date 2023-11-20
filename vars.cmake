set(LIB_SRC_FILES 
  "${CMAKE_SOURCE_DIR}/src/sys/mem.c"
  "${CMAKE_SOURCE_DIR}/src/sys/term.c"
  "${CMAKE_SOURCE_DIR}/src/boot.asm"
)

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf32)
enable_language(ASM_NASM)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/src/linker.ld")
set(CMAKE_C_FLAGS "-m32 -ffreestanding -nostdinc -fno-builtin -nostdlib -nodefaultlibs")
set(CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} -nostdlib")

include_directories(${CMAKE_SOURCE_DIR}/src/)
