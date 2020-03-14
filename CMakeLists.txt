cmake_minimum_required (VERSION 3.1)

project (Chromosome_Mutator)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

file(GLOB UTIL_SOURCES
    src/Util/*.cpp
)

file(GLOB MUTATOR_SOURCES
    src/Mutator/*.h
    src/Mutator/*.cpp
)
add_executable(mutator ${UTIL_SOURCES} ${MUTATOR_SOURCES} )
target_include_directories(mutator PRIVATE src/Util)

file(GLOB RANDOM_GENERATOR_SOURCES
    src/RandomGenerator/*.h
    src/RandomGenerator/*.cpp
)
add_executable(generator ${RANDOM_GENERATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( generator LINK_PUBLIC ${Boost_LIBRARIES} )
