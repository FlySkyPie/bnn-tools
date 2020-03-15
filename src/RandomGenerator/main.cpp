#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>

#include "Generator.h"
#include "StringEncoder.h"

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
            ("address", po::value<unsigned>(), "length of addressing space")
            ("gene", po::value<uint32_t>(), "how many genes will generated")
            ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    if (!vm.count("address")) {
        cout << "Length of address was not set.\n";
        return 1;
    }

    if (!vm.count("gene")) {
        cout << "Amount of genes was not set.\n";
        return 1;
    }

    try {
        Generator generator(vm["address"].as< unsigned>(), vm["gene"].as<uint32_t>());
        StringEncoder encoder;
        string result = encoder.encode(generator.getChromosome());
        cout << result;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

