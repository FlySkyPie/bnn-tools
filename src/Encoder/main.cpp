#include <cstdlib>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <boost/program_options.hpp>
#include "rapidjson/document.h"
#include <stdexcept>

using namespace rapidjson;
using namespace std;
namespace po = boost::program_options;

struct LinkGene
{
    uint32_t from;
    uint32_t to;
    bool weight;
};


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
 * To randomly generate chromosome as original species.
 */
int main(int argc, char** argv)
{
    string line;
    
    //read header
    getline(cin, line);
    unsigned char scale = parseHeader(line);



    while (getline(cin, line))
    {
        Document document;
        document.Parse(line.c_str());


        // process pair (a,b)
    }


    return 0;
}
