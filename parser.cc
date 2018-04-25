// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 43 "parser.yy" // lalr1.cc:398

#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.hh"

using namespace std;

// TODO: Construct a symbol hash map

#undef yylex
#define yylex lexer.yylex


// string list;


#line 54 "parser.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 68 "parser.cc" // lalr1.cc:406


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "parser.yy" // lalr1.cc:473
namespace AnASM {
#line 154 "parser.cc" // lalr1.cc:473

  /// Build a parser object.
  Parser::Parser (Lexer &lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.copy< int > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.copy< int > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.template destroy< int > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.move< int > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);

  }

  Parser::symbol_type
  Parser::make_NEWLINE (const location_type& l)
  {
    return symbol_type (token::NEWLINE, l);

  }

  Parser::symbol_type
  Parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);

  }

  Parser::symbol_type
  Parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);

  }

  Parser::symbol_type
  Parser::make_IDENTIFIER (const location_type& l)
  {
    return symbol_type (token::IDENTIFIER, l);

  }

  Parser::symbol_type
  Parser::make_REGISTER (const int& v, const location_type& l)
  {
    return symbol_type (token::REGISTER, v, l);

  }

  Parser::symbol_type
  Parser::make_INTEGER (const int& v, const location_type& l)
  {
    return symbol_type (token::INTEGER, v, l);

  }

  Parser::symbol_type
  Parser::make_LOAD (const location_type& l)
  {
    return symbol_type (token::LOAD, l);

  }

  Parser::symbol_type
  Parser::make_ADD (const location_type& l)
  {
    return symbol_type (token::ADD, l);

  }

  Parser::symbol_type
  Parser::make_SUB (const location_type& l)
  {
    return symbol_type (token::SUB, l);

  }

  Parser::symbol_type
  Parser::make_OR (const location_type& l)
  {
    return symbol_type (token::OR, l);

  }

  Parser::symbol_type
  Parser::make_XOR (const location_type& l)
  {
    return symbol_type (token::XOR, l);

  }

  Parser::symbol_type
  Parser::make_BRA (const location_type& l)
  {
    return symbol_type (token::BRA, l);

  }

  Parser::symbol_type
  Parser::make_BRAZ (const location_type& l)
  {
    return symbol_type (token::BRAZ, l);

  }

  Parser::symbol_type
  Parser::make_BRAL (const location_type& l)
  {
    return symbol_type (token::BRAL, l);

  }

  Parser::symbol_type
  Parser::make_BRALZ (const location_type& l)
  {
    return symbol_type (token::BRALZ, l);

  }

  Parser::symbol_type
  Parser::make_CALL (const location_type& l)
  {
    return symbol_type (token::CALL, l);

  }

  Parser::symbol_type
  Parser::make_HALT (const location_type& l)
  {
    return symbol_type (token::HALT, l);

  }

  Parser::symbol_type
  Parser::make_IN (const location_type& l)
  {
    return symbol_type (token::IN, l);

  }

  Parser::symbol_type
  Parser::make_OUT (const location_type& l)
  {
    return symbol_type (token::OUT, l);

  }



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 7: // REGISTER
      case 8: // INTEGER
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 7: // REGISTER

#line 71 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< int > (); }
#line 568 "parser.cc" // lalr1.cc:616
        break;

      case 8: // INTEGER

#line 71 "parser.yy" // lalr1.cc:616
        { yyoutput << yysym.value.template as< int > (); }
#line 575 "parser.cc" // lalr1.cc:616
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* Variants are always initialized to an empty instance of the
       correct type. The default $$=$1 action is NOT applied when using
       variants.  */
      switch (yyr1_[yyn])
    {
      case 7: // REGISTER
      case 8: // INTEGER
        yylhs.value.build< int > ();
        break;

      default:
        break;
    }


    // Compute the default @$.
    {
      slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
      YYLLOC_DEFAULT (yylhs.location, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 6:
#line 89 "parser.yy" // lalr1.cc:846
    {
             if(yystack_[0].value.as< int > () < 10)
             {
             //   list = "Hello Wolrd";
             // std::cout << list<<std::endl;
                std::cout << "10" << yystack_[0].value.as< int > () << yystack_[2].value.as< int > () << ", " ;

             }
             else if(yystack_[0].value.as< int > () == 10)
                std::cout << "10A" << yystack_[2].value.as< int > () << ", " ;
             else if(yystack_[0].value.as< int > () == 11)
                std::cout << "10B" << yystack_[2].value.as< int > () << ", " ;
             else if(yystack_[0].value.as< int > () == 12)
                std::cout << "10C" << yystack_[2].value.as< int > () << ", " ;
             else if(yystack_[0].value.as< int > () == 13)
                std::cout << "10D" << yystack_[2].value.as< int > () << ", " ;
             else if(yystack_[0].value.as< int > () == 14)
                std::cout << "10E" << yystack_[2].value.as< int > () << ", " ;
             else if(yystack_[0].value.as< int > () == 15)
                std::cout << "10F" << yystack_[2].value.as< int > () << ", ";
             else
                std::cout << "Error of INTEGER!!" ;
           }
#line 828 "parser.cc" // lalr1.cc:846
    break;

  case 7:
#line 113 "parser.yy" // lalr1.cc:846
    {
             std::cout << "4" << yystack_[4].value.as< int > () << yystack_[2].value.as< int > () << yystack_[0].value.as< int > () << ", ";}
#line 835 "parser.cc" // lalr1.cc:846
    break;

  case 8:
#line 117 "parser.yy" // lalr1.cc:846
    {
             std::cout << "5" << yystack_[4].value.as< int > () << yystack_[2].value.as< int > () << yystack_[0].value.as< int > () << ", ";}
#line 842 "parser.cc" // lalr1.cc:846
    break;

  case 9:
#line 121 "parser.yy" // lalr1.cc:846
    {
             std::cout << "6" << yystack_[4].value.as< int > () << yystack_[2].value.as< int > () << yystack_[0].value.as< int > () << ", " ;}
#line 849 "parser.cc" // lalr1.cc:846
    break;

  case 10:
#line 125 "parser.yy" // lalr1.cc:846
    {
             std::cout << "7" << yystack_[4].value.as< int > () << yystack_[2].value.as< int > () << yystack_[0].value.as< int > () << ", " ;}
#line 856 "parser.cc" // lalr1.cc:846
    break;

  case 11:
#line 129 "parser.yy" // lalr1.cc:846
    {
             std::cout << "8" << yystack_[0].value.as< int > () << "00" << ", " ;}
#line 863 "parser.cc" // lalr1.cc:846
    break;

  case 12:
#line 132 "parser.yy" // lalr1.cc:846
    {
              std::cout << "9" << yystack_[0].value.as< int > () << "00" << ", " ;}
#line 870 "parser.cc" // lalr1.cc:846
    break;

  case 13:
#line 135 "parser.yy" // lalr1.cc:846
    {
            std::cout << "A" << yystack_[0].value.as< int > () << "00" << ", ";}
#line 877 "parser.cc" // lalr1.cc:846
    break;

  case 14:
#line 138 "parser.yy" // lalr1.cc:846
    {
              std::cout << "B" << yystack_[0].value.as< int > () << "00" << ", " ;}
#line 884 "parser.cc" // lalr1.cc:846
    break;

  case 15:
#line 141 "parser.yy" // lalr1.cc:846
    {
            std::cout << "C0" << yystack_[0].value.as< int > () << yystack_[2].value.as< int > () << ", " ;}
#line 891 "parser.cc" // lalr1.cc:846
    break;

  case 16:
#line 144 "parser.yy" // lalr1.cc:846
    {
            std::cout << "D0" << yystack_[0].value.as< int > () << ", ";}
#line 898 "parser.cc" // lalr1.cc:846
    break;

  case 17:
#line 147 "parser.yy" // lalr1.cc:846
    {
             std::cout << "F" << yystack_[0].value.as< int > () << "00" << ", " ;}
#line 905 "parser.cc" // lalr1.cc:846
    break;

  case 18:
#line 150 "parser.yy" // lalr1.cc:846
    { std::cout << "E000;" ;}
#line 911 "parser.cc" // lalr1.cc:846
    break;


#line 915 "parser.cc" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* $$ was initialized before running the user action.  */
    YY_SYMBOL_PRINT ("Error: discarding", yylhs);
    yylhs.~stack_symbol_type();
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -7;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       0,    -7,    -7,    -6,    -5,    -3,    -2,    -1,     1,    16,
      17,    19,    20,    -7,    21,    23,     7,    22,    -7,    25,
      40,    41,    42,    43,    -7,    -7,    -7,    -7,    44,    -7,
      -7,    -7,    -7,    -7,    45,    47,    48,    49,    50,    51,
      -7,    46,    55,    56,    57,    -7,    58,    59,    60,    61,
      -7,    -7,    -7,    -7
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     2,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,    11,    12,    13,    14,     0,    16,
      17,     1,     3,     5,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       7,     8,     9,    10
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -7,    -7,    -7,    32
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    16,    17,    18
  };

  const unsigned char
  Parser::yytable_[] =
  {
       1,    19,    20,     2,    21,    22,    23,    31,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    32,    25,    26,     2,    27,    28,    29,    34,
      30,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    35,    36,    37,    38,    39,    33,
      46,     0,     0,    40,    41,    42,    43,    44,    45,    47,
      48,    49,     0,     0,     0,    50,    51,    52,    53
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     7,     7,     3,     7,     7,     7,     0,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     7,     7,     3,     7,     7,     7,     4,
       7,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     4,     4,     4,     4,     4,    17,
       4,    -1,    -1,     8,     7,     7,     7,     7,     7,     4,
       4,     4,    -1,    -1,    -1,     7,     7,     7,     7
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     0,     3,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    23,    24,    25,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     0,     0,    25,     4,     4,     4,     4,     4,     4,
       8,     7,     7,     7,     7,     7,     4,     4,     4,     4,
       7,     7,     7,     7
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    22,    23,    23,    24,    24,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     4,     6,     6,     6,
       6,     2,     2,     2,     2,     4,     2,     2,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NEWLINE", "COMMA", "COLON",
  "IDENTIFIER", "REGISTER", "INTEGER", "LOAD", "ADD", "SUB", "OR", "XOR",
  "BRA", "BRAZ", "BRAL", "BRALZ", "CALL", "HALT", "IN", "OUT", "$accept",
  "program", "line", "statement", YY_NULL
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    81,    81,    82,    85,    86,    89,   113,   117,   121,
     125,   129,   132,   135,   138,   141,   144,   147,   150,   151
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
    };
    const unsigned int user_token_number_max_ = 276;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "parser.yy" // lalr1.cc:1156
} // AnASM
#line 1272 "parser.cc" // lalr1.cc:1156
#line 155 "parser.yy" // lalr1.cc:1157


void AnASM::Parser::error(const location_type &l, const std::string &m)
{
  std::cerr << l << ": " << m << std::endl;
}
