%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
<<EOF>> {return END_OF_FILE;}
"if" {return IF;}
"while" {return WHILE;}
"for" {return FOR;}
"in" {return IN;}
"begin_function" {return BGIN_FUNC;}
"end_function" {return END_FUNC;}
"begin_if" {return BGIN_IF;}
"begin_else" {return BGIN_ELSE;}
"end_if" {return END_IF;}
"begin_while" {return BGIN_WHILE;}
"end_while" {return END_WHILE;}
"begin_for" {return BGIN_FOR;}
"end_for" {return END_FOR;}
"int"|"float"|"char"|"string" {return TIP;}
"const" {return CONST;}
":=" {return ASSIGN;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
([1-9][0-9]*)|"0" {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
