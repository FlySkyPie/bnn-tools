cd ../src

g++ ./../test/testHeaderDecoder.cpp Chromosome.cpp HeaderDecoder.cpp -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test

g++ ./../test/testBernoulliJudge.cpp BernoulliJudge.cpp -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test

g++ ./../test/testLinkerMutator.cpp BernoulliJudge.cpp Chromosome.cpp HeaderDecoder.cpp LinkerMutator.cpp  -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test

g++ ./../test/testStringDecoder.cpp Chromosome.cpp StringDecoder.cpp -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test

g++ ./../test/testStringEncoder.cpp Chromosome.cpp StringEncoder.cpp -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test

g++ ./../test/testMutator.cpp Chromosome.cpp StringDecoder.cpp HeaderDecoder.cpp BernoulliJudge.cpp LinkerMutator.cpp Mutator.cpp -o ./../test/test -lgtest -I.
./../test/test
rm ./../test/test