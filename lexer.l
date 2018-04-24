%{

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "lexer.hh"

using namespace std;

// Prevent using unistd.h
#define YY_NO_UNISTD_H

// Re-define YY_DECL
#undef YY_DECL
#define YY_DECL int AnASM::Lexer::yylex(AnASM::Parser::semantic_type *lval, AnASM::Parser::location_type *loc)

// Shorter alias for token type
using token = AnASM::Parser::token;

// define yyterminate() to return END token
#define yyterminate() return(token::END)

// Update location
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option yyclass="AnASM::Lexer"
%option c++
%option noyywrap nounput batch debug noinput

delimiter  [ \t]
whitespace {delimiter}+
digit      [0-9]
alpha      [a-zA-Z]
alphanum   [a-zA-Z0-9]
integer    [-]?[1-9]{digit}*
register   [rR]{digit}+
identifier [a-zA-Z_][a-zA-Z0-9_]*

%%

{register}  { lval->build<int>() = atoi(YYText() + 1) ; return token::REGISTER; }
{integer}   { lval->build<int>() = atoi(YYText()); return token::INTEGER; }

\n        { return token::NEWLINE; }
,         { return token::COMMA; }
:         { return token::COLON; }

"LOAD"    { return token::LOAD; }
"ADD"     { return token::ADD; }
"SUB"     { return token::SUB; }
"OR"      { return token::OR; }
"XOR"     { return token::XOR; }
"BRA"     { return token::BRA; }
"BRAZ"    { return token::BRAZ; }
"BRAL"    { return token::BRAL; }
"BRALZ"   { return token::BRALZ; }
"CALL"    { return token::CALL; }
"IN"      { return token::IN; }
"OUT"     { return token::OUT; }
"HALT"    { return token::HALT; }


{whitespace} { /* Do noting */ }

%%
