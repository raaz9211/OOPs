cmake_minimum_required(VERSION 3.10)
project(BookMyShow)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Gather all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Build the main executable
add_executable(book_my_show ${SOURCES} main.cpp)
