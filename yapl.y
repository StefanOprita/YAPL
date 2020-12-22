%{
    #include <stdio.h>
    #include <string.h>


    #define RED   "\x1B[31m"
    #define GRN   "\x1B[32m"
    #define YEL   "\x1B[33m"
    #define BLU   "\x1B[34m"
    #define MAG   "\x1B[35m"
    #define CYN   "\x1B[36m"
    #define WHT   "\x1B[37m"
    #define RESET "\x1B[0m"

    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno; 
%}

%token ID TIP ASSIGN NR AUX END_OF_FILE CONST IN
%token BGIN_FUNC END_FUNC BGIN_IF END_IF BGIN_ELSE
%token BGIN_WHILE END_WHILE BGIN_FOR END_FOR
%token IF WHILE FOR
%start program

%%
program : declaratii  END_OF_FILE {printf("program corect sintactic\n");}
        ;
declaratii : declaratie_variabila declaratii {printf("uau ce magie\n");}
           | declaratie_functie declaratii {printf("sunt aici\n");}
           | instructiune declaratii
           | declaratie_variabila
           | declaratie_functie
           | instructiune
           ;

instructiune : IF conditie_logica bloc_if
             | WHILE conditie_logica bloc_while
             | FOR ID IN range_for bloc_for
             | ID ASSIGN ID
             ;
conditie_logica : '@';

bloc_if : BGIN_IF declaratii END_IF
        | BGIN_IF declaratii BGIN_ELSE declaratii END_IF

bloc_while : BGIN_WHILE declaratii END_WHILE;

range_for : '('NR ',' NR ')';

bloc_for : BGIN_FOR declaratii END_FOR;

/*<functii>*/
declaratie_functie : ID'('lista_parametrii')' '-''>' declaratie_tip bloc_functie
                   | ID'(' ')' '-''>' declaratie_tip
                   ;

bloc_functie : BGIN_FUNC declaratii END_FUNC;

lista_parametrii :  lista_parametrii ',' declaratie_parametru
                 | declaratie_parametru
                 ;

declaratie_parametru : declaratie_tip ID
                     ;
/*</functii>*/

/*<variabile>*/
declaratie_variabila : declaratie_tip declaratie_ids
                     ;
declaratie_ids : ID ',' declaratie_ids
               | ID ASSIGN ID ',' declaratie_ids
               | ID
               | ID ASSIGN ID
               ;
/*</variabile>*/
declaratie_tip : TIP 
              | CONST TIP
              | TIP'['NR']'
              ;
%%
void yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
}
void PrintError(const char *message)
{
    char redMessage[strlen(message) + 15];
    sprintf(redMessage, "%s%s%s\n", RED, message, RESET);
    printf(redMessage);
    fflush(stdout);
}   


int main(int argc,  char** argv)
{
    if(argc < 2)
    {
        PrintError("Nu-i bini, trebuie macar un argument");       
    }
    yyin = fopen(argv[1], "r");
    yyparse();
}