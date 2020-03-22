cmake_minimum_required (VERSION 3.1)

project (Chromosome_Mutator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
#find_package(Threads REQUIRED)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# utility stuff
file(GLOB UTIL_SOURCES
    src/Util/*.cpp
)
include_directories(src/Util)

# mutator stuff
set(MUTATOR_DIR ${CMAKE_SOURCE_DIR}/src/Mutator)
set(MUTATOR_SOURCES
    ${MUTATOR_DIR}/HeaderDecoder.cpp
    ${MUTATOR_DIR}/LinkerMutator.cpp
    ${MUTATOR_DIR}/Mutator.cpp
    ${MUTATOR_DIR}/LinkGene.cpp
)
include_directories(src/Mutator)

add_executable(mutator ${MUTATOR_DIR}/main.cpp ${UTIL_SOURCES} ${MUTATOR_SOURCES} )
target_link_libraries( mutator LINK_PUBLIC ${Boost_LIBRARIES} )

# random generator stuff
set(GEMERATOR_DIR ${CMAKE_SOURCE_DIR}/src/RandomGenerator)
file(GLOB RANDOM_GENERATOR_SOURCES
    ${GEMERATOR_DIR}/Generator.cpp
)
include_directories(src/RandomGenerator)

add_executable(generator ${GEMERATOR_DIR}/main.cpp ${RANDOM_GENERATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( generator LINK_PUBLIC ${Boost_LIBRARIES} )

# Decoder stuff
set(DECODER_DIR ${CMAKE_SOURCE_DIR}/src/Decoder)
file(GLOB DECODER_SOURCES
    ${DECODER_DIR}/Decoder.cpp
)
include_directories(src/Decoder)

add_executable( decoder ${DECODER_DIR}/main.cpp ${DECODER_SOURCES} ${UTIL_SOURCES})
target_link_libraries( decoder LINK_PUBLIC ${Boost_LIBRARIES} )

# Network stuff
set(NETWORK_DIR ${CMAKE_SOURCE_DIR}/src/Network)
file(GLOB NETWORK_SOURCES
    ${NETWORK_DIR}/Neuron.cpp
    ${NETWORK_DIR}/NeuralChamber.cpp
    ${NETWORK_DIR}/NeuralLinkContainer.cpp
)
include_directories(src/Network)


# GTest stuff
enable_testing()
add_subdirectory(test)

