cmake_minimum_required(VERSION 3.2)
project(mmd-tools)

set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH lib)

set(LIB_TARGET mmd-tools)
set(EXAMPLE_TARGET example)

aux_source_directory(src SRCS)
aux_source_directory(src/pmx SRCS)
aux_source_directory(example EXAMPLE_SRC)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -fvisibility=hidden")

add_library(${LIB_TARGET} SHARED ${SRCS})
add_executable(${EXAMPLE_TARGET} ${EXAMPLE_SRC})
target_link_libraries(${EXAMPLE_TARGET} ${LIB_TARGET})
