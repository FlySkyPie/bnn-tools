#include <cstdlib>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <boost/program_options.hpp>

#include "Chromosome.h"
#include "Decoder.h"
#include "StringDecoder.h"

using namespace std;
namespace po = boost::program_options;

/**
 * To randomly generate chromosome as original species.
 */
int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("input-file", po::value<string>(), "the chromosome file")
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

    try {
        //read file
        string filePath = vm["input-file"].as<string>();
        ifstream file;
        file.open(filePath);
        string chromosomString((istreambuf_iterator<char>(file)),
                istreambuf_iterator<char>());
        file.close();

        //decode to chromosome from string
        StringDecoder stringDecoder;
        Decoder decoder;
        Chromosome * chromosome = stringDecoder.decode(chromosomString);

        //decode to json from chromosome
        string result = decoder.convertToJson(chromosome);
        cout << result;
        delete chromosome;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

