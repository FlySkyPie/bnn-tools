
add_executable( test_mutator testMutator.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_mutator ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_mutator COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_mutator)

add_executable( test_linker_mutator testLinkerMutator.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_linker_mutator  ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_linker_mutator  COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_linker_mutator )

add_executable( test_header_decoder testHeaderDecoder.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_header_decoder ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_header_decoder COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_header_decoder)

add_executable( test_string_decoder testStringDecoder.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_string_decoder ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_string_decoder COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_string_decoder)

add_executable( test_string_encoder testStringEncoder.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_string_encoder ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_string_encoder COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_string_encoder)

add_executable( test_bernoulli_jude testBernoulliJudge.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_bernoulli_jude ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_bernoulli_jude COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_bernoulli_jude)

add_executable( test_chromosome testChromosome.cpp  ${UTIL_SOURCES})
target_link_libraries( test_chromosome ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_chromosome COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_chromosome)

add_executable( test_generator testGenerator.cpp  ${UTIL_SOURCES} ${RANDOM_GENERATOR_SOURCES})
target_link_libraries( test_generator ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_generator COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_generator)

add_executable( test_decoder testDecoder.cpp  ${UTIL_SOURCES} ${DECODER_SOURCES})
target_link_libraries( test_decoder ${GTEST_BOTH_LIBRARIES} nlohmann_json::nlohmann_json)
add_test(NAME test_decoder COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_decoder)

add_executable( test_link_gene testLinkGene.cpp ${MUTATOR_SOURCES} ${UTIL_SOURCES})
target_link_libraries( test_link_gene  ${GTEST_BOTH_LIBRARIES})
add_test(NAME test_link_gene  COMMAND ${CMAKE_SOURCE_DIR}/build/test/test_link_gene )