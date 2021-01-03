%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
<<EOF>> {return END_OF_FILE;}
["].+["] {return STRING_CONST;}
['].['] {return CHAR_CONST;}
"begin_class" { return BGIN_CLASS;}
"end_class" {; return END_CLASS;}
"begin_members" {return BGIN_MEMBRS;}
"end_members" {return END_MEMBRS;}
"begin_functions" {return BGIN_FUNCS;}
"end_functions" {return END_FUNCS;}
"class" {symbolTable_pushScope("class"); return CLASS;}
"function" {symbolTable_pushScope("function");return FUNCTION;}
"if" {; return IF;}
"while" { return WHILE;}
"for" {; return FOR;}
"in" {return IN;}
"begin_function" {;return BGIN_FUNC;}
"end_function" {;return END_FUNC;}
"begin_if" {symbolTable_pushScope("if");return BGIN_IF;}
"begin_else" {return BGIN_ELSE;}
"end_if" {;return END_IF;}
"begin_while" {symbolTable_pushScope("while");;return BGIN_WHILE;}
"end_while" {;;return END_WHILE;}
"begin_for" {symbolTable_pushScope("for");return BGIN_FOR;}
"end_for" {;;return END_FOR;}
"int"|"float"|"char"|"string" {yylval.strval = strdup(yytext); return TIP;}
"const" {return CONST;}
":=" {return ASSIGN;}
([_a-zA-Z][_a-zA-Z0-9]*) {yylval.strval = strdup(yytext); symbolTable_CheckClassOrFunc(yytext); return ID; }
([1-9][0-9]*)|"0" {yylval.strval = strdup(yytext);return INTREG;}
(([1-9][0-9]*)|"0")"."[0-9]* {return REAL;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
