#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>
#include <sstream>  //stringstream
#include <rapidjson/document.h>

#include "GeneMutator.h"

using namespace rapidjson;
using namespace std;
namespace po = boost::program_options;

typedef unsigned char uchar;

unsigned char parseHeader(string headerLine) {
    Document document;
    document.Parse(headerLine.c_str());

    if (!document.IsObject()) {
        cerr << "header error: It's not a JSON object.\n";
        exit(1);
    }
    if (!document.HasMember("type")) {
        cerr << "header error: It doesn't containing the key of \"type\".\n";
        exit(1);
    }
    if (!document.HasMember("scale")) {
        cerr << "header error: It doesn't containing the key of \"scale\".\n";
        exit(1);
    }
    if (string(document["type"].GetString()) != string("head")) {
        cerr << "header error: The type is not \"head\".\n";
        exit(1);
    }
    if (!document["scale"].IsInt()) {
        cerr << "header error: The scale is not integer.\n";
        exit(1);
    }

    unsigned char scale = document["scale"].GetInt();
    if (!(scale >= 1 && scale <= 32)) {
        cerr << "scale error: It should between 1~32.\n";
        exit(1);
    }

    return scale;
}


/**
 * Mutate bits in gene.
 */
int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("mutated-rate", po::value<float>(), "probability of mutate happened.");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cerr << desc << "\n";
        return 1;
    }
    if (!vm.count("mutated-rate")) {
        std::cerr << "Mutated rate was not set.\n";
        return 1;
    }

    string line;

    //read header
    getline(cin, line);
    cout << line << "\n";
    uint32_t scale = parseHeader(line);

    GeneMutator mutator(scale, vm["mutated-rate"].as<float>());

    while (getline(cin, line)) {
        cout << mutator.mutateGeneJsonl(line);
    }

    return 0;
}