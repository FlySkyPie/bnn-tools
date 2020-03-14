#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

/**
 * 
 */
int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("address", po::value<int>()->default_value(10), "length of addressing space")
            ("gene", po::value<int>(), "how many genes will generated")
            ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("address")) {
        cout << "Compression level was set to "
                << vm["address"].as<int>() << ".\n";
    } else {
        cout << "Compression level was not set.\n";
    }
    return 0;
}

