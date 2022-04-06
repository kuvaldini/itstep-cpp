cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 facebook.cpp)
add_compile_options(-Wall)


add_executable(main_stack main_stack.cpp)
add_compile_options(-Wall)


add_executable(addrbookvector AddrBookVector.cpp AddressBookInterface.h)
add_compile_options(-Wall -Werror)

add_executable(matrix-1d matrix-1d.cpp)

add_executable(binat binat.cpp )

add_executable(multi_table multi_table.cpp)
