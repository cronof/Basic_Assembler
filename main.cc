#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.hh"
#include "lexer.hh"

using namespace std;

int main()
{
  // stringstream ss;
  AnASM::Lexer lexer(&cin);
  AnASM::Parser parser(lexer);
  ofstream myfile;
  myfile.open("test.coe");
  myfile << "memory_initialization_radix = 16;" <<std::endl;
  myfile << "memory_initialization_vector = ";
  int result = parser.parse();
  // myfile << list;
  myfile.close();

  // AnASM::Xever loading();

  // Un-comment the following line for parser debugging
  // parser.set_debug_level(1);


  // cout << loading() << endl;

  exit(EXIT_SUCCESS);
}
