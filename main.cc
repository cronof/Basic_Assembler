#include <iostream>
#include <fstream>
#include "parser.hh"
#include "lexer.hh"

using namespace std;

int main()
{
  ofstream myfile;
  myfile.open("test.coe");
  myfile << "memory_initialization_radix = 16;" <<std::endl;
  myfile << "memory_initialization_vector = ";
  myfile << list;

  AnASM::Lexer lexer(&cin);
  AnASM::Parser parser(lexer);


  // Un-comment the following line for parser debugging
  // parser.set_debug_level(1);

  int result = parser.parse();

myfile.close();



  exit(EXIT_SUCCESS);
}
