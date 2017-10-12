cmake_minimum_required(VERSION 3.8)
project(AUD_1)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-fsanitize=address -fsanitize-address-use-after-scope -O1 -fno-omit-frame-pointer")

set(SOURCE_FILES main.c single_linked_list.c single_linked_list.h single_linked_list_tests.c single_linked_list_tests.h)
add_executable(AUD_1 ${SOURCE_FILES})