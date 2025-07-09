cmake_minimum_required(VERSION 3.10)
project(BookMyShow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files
include_directories(include)


# Gather all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(book_my_show ${SOURCES} main.cpp)