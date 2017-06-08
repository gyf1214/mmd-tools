cmake_minimum_required(VERSION 3.2)
project(mmd-tools)

set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH lib)

set(LIB_TARGET mmd-tools)

aux_source_directory(src SRCS)
aux_source_directory(src/pmx SRCS)
aux_source_directory(src/vmd SRCS)
set(EXAMPLE_SRC example)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -DMMDShared")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(subst ${CMAKE_SOURCE_DIR}/src/,,$(abspath $<))\"'")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -fvisibility=hidden")

add_library(${LIB_TARGET} SHARED ${SRCS})
add_executable(test_pmx ${EXAMPLE_SRC}/pmx.cc)
add_executable(test_vmd ${EXAMPLE_SRC}/vmd.cc)

find_library(ICONV_LIB iconv)
target_link_libraries(${LIB_TARGET} ${ICONV_LIB})
target_link_libraries(test_pmx ${LIB_TARGET})
target_link_libraries(test_vmd ${LIB_TARGET})

if (WIN32)
add_custom_command(TARGET test_pmx POST_BUILD
             COMMAND ${CMAKE_COMMAND} -E copy_if_different
             $<TARGET_FILE:${LIB_TARGET}> $<TARGET_FILE_DIR:test_pmx>)

add_custom_command(TARGET test_pmx POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:${LIB_TARGET}> $<TARGET_FILE_DIR:test_pmx>)
endif(WIN32)
