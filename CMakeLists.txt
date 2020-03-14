cmake_minimum_required (VERSION 3.1)

project (Chromosome_Mutator)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_BUILD_TYPE Debug)
#set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# utility stuff
file(GLOB UTIL_SOURCES
    src/Util/*.cpp
)
include_directories(src/Util)

# mutator stuff
set(MUTATOR_DIR ${CMAKE_SOURCE_DIR}/src/Mutator)
set(MUTATOR_SOURCES
    ${MUTATOR_DIR}/BernoulliJudge.cpp
    ${MUTATOR_DIR}/HeaderDecoder.cpp
    ${MUTATOR_DIR}/LinkerMutator.cpp
    ${MUTATOR_DIR}/Mutator.cpp
)
include_directories(src/Mutator)

add_executable(mutator ${MUTATOR_DIR}/main.cpp ${UTIL_SOURCES} ${MUTATOR_SOURCES} )

# random generator stuff
file(GLOB RANDOM_GENERATOR_SOURCES
    src/RandomGenerator/*.cpp
)
include_directories(src/RandomGenerator)

add_executable(generator ${RANDOM_GENERATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( generator LINK_PUBLIC ${Boost_LIBRARIES} )

# GTest stuff
enable_testing()
add_subdirectory(test)

