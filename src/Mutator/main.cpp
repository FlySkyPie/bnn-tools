#include "Mutator.h"
#include "StringEncoder.h"
#include <string>
#include <iostream>

using namespace std;

string readString(int length) {
  string str = "";

  for (int i = 0; i < length; i++) {
    str += cin.get();
  }
  return str;
}

int main(int arg, char * args[]) {
  int length = atoi(args[1]);
  string geneString = readString(length);
  Mutator mutator(geneString);
  StringEncoder encoder;
  string result = encoder.encode(mutator.getChild());
  cout << result;
  return 0;
}