cmake_minimum_required (VERSION 3.1)

project (Chromosome_Mutator)

file(GLOB MUTATOR_SOURCES
    src/Mutator/*.h
    src/Mutator/*.cpp
)
add_executable(mutator ${MUTATOR_SOURCES})
