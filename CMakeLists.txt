cmake_minimum_required (VERSION 3.1)

project (Chromosome_Mutator)

file(GLOB SOURCES
    src/*.h
    src/*.cpp
)
add_executable(mutator ${SOURCES})
