cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_SYSTEM_NAME "Generic" CACHE STRING "Target system.")
project(os)

include(vars.cmake)

add_executable(kernel.bin "src/kentry.c" ${LIB_SRC_FILES})
set_target_properties(kernel.bin PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})

add_subdirectory(test)
