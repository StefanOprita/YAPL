%{
#include <stdio.h>
#include "y.tab.h"

extern int classFunctIncoming;
%}
%option noyywrap
%%
<<EOF>> {return END_OF_FILE;}
["][^"]+["] {
    char *p = strdup(yytext);
    p[strlen(p) - 1] = 0;

    yylval.strval = p + 1;
    return STRING_CONST;
    }
['].['] {yylval.chrval = yytext[0];return CHAR_CONST;}
"begin_class" { symbolTable_pushScope("class"); ;return BGIN_CLASS;}
"end_class" {; return END_CLASS;}
"begin_members" {return BGIN_MEMBRS;}
"end_members" {return END_MEMBRS;}
"begin_functions" {return BGIN_FUNCS;}
"end_functions" {return END_FUNCS;}
"class" { classFunctIncoming = 1;;return CLASS;}
"function" {classFunctIncoming = 1;;return FUNCTION;}
"if" {; return IF;}
"while" { return WHILE;}
"for" {; return FOR;}
"in" {;;return IN;}
"begin_function" {symbolTable_pushScope("function");symbolTable_InsertMember("void", "return");return BGIN_FUNC;}
"end_function" {;return END_FUNC;}
"begin_if" {symbolTable_pushScope("if");;return BGIN_IF;}
"begin_else" {return BGIN_ELSE;}
"end_if" {;return END_IF;}
"begin_while" {symbolTable_pushScope("while");;return BGIN_WHILE;}
"end_while" {;;return END_WHILE;}
"begin_for" {symbolTable_pushScope("for");return BGIN_FOR;}
"end_for" {;;return END_FOR;}
"int"|"float"|"char"|"string" {yylval.strval = strdup(yytext); return TIP;}
"const" {return CONST;}
"&&" {return AND;}
"||" {return OR;}
"->" {return SAGETICA;};
":=" {return ASSIGN;}
">=" {return GE;}
"<=" {return LE;}
"==" {return EQ;}
"!=" {return NE;}
">" {return GT;}
"<" {return LT;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULT;}
"/" {return DIV;}
([_a-zA-Z][_a-zA-Z0-9]*) {yylval.strval = strdup(yytext); symbolTable_CheckClassOrFunc(yytext); return ID; }
([1-9][0-9]*)|"0" {yylval.strval = strdup(yytext);return INTREG;}
(([1-9][0-9]*)|"0")"."[0-9]* {yylval.strval = strdup(yytext);return REAL;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
