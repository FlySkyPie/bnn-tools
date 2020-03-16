#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <boost/program_options.hpp>

#include "Mutator.h"
#include "StringDecoder.h"
#include "StringEncoder.h"

using namespace std;
namespace po = boost::program_options;

Chromosome* readFileToChromosome(string filePath) {
    //read file
    ifstream file;
    file.open(filePath);
    string chromosomString((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
    file.close();

    //decode to chromosome from binary string
    StringDecoder stringDecoder;
    return stringDecoder.decode(chromosomString);
}

/**
 * Read first 1 byte as addressing length from head of chromosome.
 * 
 * @param chromosome
 * @return 
 */
uint8_t readAddressLength(Chromosome* chromosome) {
    uint8_t value = 0;
    for (uint8_t i = 0; i < 8; i++) {
        bool gene;
        if (!chromosome->getGene(gene)) {
            throw "Parse addressing length error occurred.";
        }
        value = (value << 1) | gene;
    }
    return value;
}

int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("input-file", po::value<string>(), "the chromosome file")
            ("mutated-rate", po::value<float>(), "probability of mutate happened.")
            ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    if (!vm.count("input-file")) {
        cout << "Input file was not set.\n";
        return 1;
    }

    if (!vm.count("mutated-rate")) {
        cout << "Mutated rate was not set.\n";
        return 1;
    }

    try {
        string filePath = vm["input-file"].as<string>();
        Chromosome * chromosome = readFileToChromosome(filePath);

        uint8_t addressLength = readAddressLength(chromosome);
        float successRate = (1 - vm["mutated-rate"].as<float>());
        
        //cout << "[test]: " << to_string(addressLength) << "\n";

        BernoulliJudge mutationJudge(successRate);
        BernoulliJudge extensionJudge(0.5);
        Mutator mutator;
        StringEncoder encoder;

        mutator.setAddressLength(addressLength)
                ->setInverseJudge(&mutationJudge)
                ->setVaryJudge(&extensionJudge)
                ->setChromosome(chromosome);

        string result = encoder.encode(mutator.getChild());
        cout << result;
        delete chromosome;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}