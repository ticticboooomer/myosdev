cmake_minimum_required(VERSION 3.20)

set(CMAKE_SYSTEM_NAME "Generic" CACHE STRING "Target system.")
project(os_memory_tests)
include(${CMAKE_SOURCE_DIR}/vars.cmake)

add_executable(test_mallocA.bin ${LIB_SRC_FILES} "kentry_mallocA.c")

set_target_properties(test_mallocA.bin PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})

