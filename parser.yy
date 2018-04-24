%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define api.namespace {AnASM}
%define parser_class_name {Parser}

/* Debugging */
%verbose
%define parse.trace

%parse-param { Lexer &lexer }
/* %parse-param { Driver &driver } */

%define api.value.type variant
/* %define parse.assert */

%locations

%code requires{
  namespace AnASM {
    // class Driver;
    class Lexer;
  }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%{
#include <iostream>
#include <fstream>
#include <string>
#include "lexer.hh"

// TODO: Construct a symbol hash map

#undef yylex
#define yylex lexer.yylex

%}

/* General Tokens */
%token END 0 "end of file"
%token NEWLINE COMMA COLON IDENTIFIER
%token <int> REGISTER
%token <int> INTEGER

/* CPU Mnemonic Tokens */
%token LOAD ADD SUB OR XOR BRA BRAZ BRAL BRALZ CALL HALT IN OUT

%printer { yyoutput << $$; } <*>;
%union {
	char list[50];
}
%%

%start program;

program: END
       | line END
       ;

line: statement
    | line statement
    ;
/* must be hex to output for use by Project*/
statement: LOAD REGISTER COMMA INTEGER {


             if($4 < 10)
                std::cout << "10" << $4 << $2 << ", " ;
                list[] = {"10", $4, $2,','};
             else if($4 == 10)
                std::cout << "10A" << $2 << ", " ;
             else if($4 == 11)
                std::cout << "10B" << $2 << ", " ;
             else if($4 == 12)
                std::cout << "10C" << $2 << ", " ;
             else if($4 == 13)
                std::cout << "10D" << $2 << ", " ;
             else if($4 == 14)
                std::cout << "10E" << $2 << ", " ;
             else if($4 == 15)
                std::cout << "10F" << $2 << ", ";
             else
                std::cout << "Error of INTEGER!!" ;
           }
             //std::cout << "R" << $2 << " <- " << $4 << std::endl; }
         | ADD REGISTER COMMA REGISTER COMMA REGISTER {
             std::cout << "4" << $2 << $4 << $6 << ", ";}
             //std::cout << "R" << $2 << " <- " <<
             //             "R" << $4 << " + R" << $6 << std::endl; }
         | SUB REGISTER COMMA REGISTER COMMA REGISTER {
             std::cout << "5" << $2 << $4 << $6 << ", ";}
             //std::cout << "R" << $2 << " <- " <<
             //            "R" << $4 << " - R" << $6 << std::endl; }
         | OR REGISTER COMMA REGISTER COMMA REGISTER {
             std::cout << "6" << $2 << $4 << $6 << ", " ;}
             //std::cout << "R" << $2 << " <- " <<
             //            "R" << $4 << " OR R" << $6 << std::endl; }
         | XOR REGISTER COMMA REGISTER COMMA REGISTER {
             std::cout << "7" << $2 << $4 << $6 << ", " ;}
             //std::cout << "R" << $2 << " <- " <<
             //            "R" << $4 << " XOR R" << $6 << std::endl; }
         | BRA REGISTER {
             std::cout << "8" << $2 << "00" << ", " ;}
             //std::cout << "BRA R" << $2 << std::endl; }
         | BRAZ REGISTER{
              std::cout << "9" << $2 << "00" << ", " ;}
             //std::cout << "BRAZ R" << $2 << std::endl; }
         | BRAL REGISTER  {
            std::cout << "A" << $2 << "00" << ", ";}
            //std::cout << "BRAL R" << $2 << std::endl; }
         | BRALZ REGISTER{
              std::cout << "B" << $2 << "00" << ", " ;}
            //std::cout << "BRALZ R" << $2 << std::endl; }
         | CALL REGISTER COMMA REGISTER {
            std::cout << "C0" << $4 << $2 << ", " ;}
            //std::cout << "CALL R" << $2 << std::endl; }
         | IN REGISTER {
            std::cout << "D0" << $2 << ", ";}
            //std::cout << "R" << $2 << " <- " << $4 << std::endl; }
         | OUT REGISTER {
             std::cout << "F" << $2 << "00" << ", " ;}
             //std::cout << "OUT R" << $2 << std::endl; }
         | HALT { std::cout << "E000;" ;}
         | NEWLINE
         ;


%%

void AnASM::Parser::error(const location_type &l, const std::string &m)
{
  std::cerr << l << ": " << m << std::endl;
}
