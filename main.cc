#include <iostream>
#include <fstream>
#include <sstream>

#include "parser.hh"
#include "lexer.hh"

using namespace std;

int main()
{
  string main_list;
  // stringstream ss;
  AnASM::Lexer lexer(&cin);
  AnASM::Parser parser(lexer);
  AnASM::Parser gimme();
  ofstream myfile;
  myfile.open("test.coe");
  myfile << "memory_initialization_radix = 16;" <<std::endl;
  myfile << "memory_initialization_vector = ";
  int result = parser.parse();
main_list=gimme();
  myfile << main_list;
  std << "|" <<  main_list << "|" <<std::endl;
  myfile.close();

  // AnASM::Xever loading();

  // Un-comment the following line for parser debugging
  // parser.set_debug_level(1);


  // cout << loading() << endl;

  exit(EXIT_SUCCESS);
}
