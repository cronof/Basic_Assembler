#ifndef __LEXER_HH__
#define __LEXER_HH__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.hh"
#include "location.hh"

namespace AnASM
{
  class Lexer : public yyFlexLexer
  {
    public:
      Lexer(std::istream *in) : yyFlexLexer(in) { };
      virtual ~Lexer() { };

      using FlexLexer::yylex;

      virtual int yylex(AnASM::Parser::semantic_type *lval, AnASM::Parser::location_type *loc);

    private:
      AnASM::Parser::semantic_type *yylval = nullptr;
  };
}

#endif
