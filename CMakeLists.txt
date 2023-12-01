cmake_minimum_required(VERSION 3.27)

project(AdventOfCode VERSION 0.01)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

add_executable(AdventOfCode ${SOURCE_FILES} ${HEADER_FILES})

