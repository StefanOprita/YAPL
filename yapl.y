%{
    #include <stdio.h>
    #include <string.h>
    #include "hashTable.h"
    #include "stiva.h"
    #include "scope.h"
    #include "symbolTable.h"
    #include "errorHandling.h"


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
    extern struct stiva_nod *top;
    extern char * currentTypeDeclared;
%}

%union{
    char* strval;
}

%type<strval> declaratie_tip_return declaratie_tip_functie declaratie_parametru lista_parametrii
%token<strval> ID TIP CONST INTREG
%token ASSIGN AUX END_OF_FILE IN
%token REAL STRING_CONST CHAR_CONST
%token FUNCTION 
%token BGIN_FUNC END_FUNC BGIN_IF END_IF BGIN_ELSE
%token BGIN_MEMBRS END_MEMBRS BGIN_FUNCS END_FUNCS BGIN_CLASS END_CLASS
%token CLASS 
%token BGIN_WHILE END_WHILE BGIN_FOR END_FOR
%token IF WHILE FOR
%start program

%%
program : declaratii  END_OF_FILE {spuneCevaFrumos();}
        ;
declaratii : declaratie_variabila declaratii {printf("declar o variabila\n");}
           | declaratie_functie declaratii {printf("declar o functie\n");}
           | declaratie_clasa declaratii {printf("declar o clasa\n");}
           | instructiune declaratii
           | declaratie_variabila {symbolTable_popScope();}
           | declaratie_functie {symbolTable_popScope();}
           | declaratie_clasa {symbolTable_popScope();}
           | instructiune {symbolTable_popScope();}
           ;

declaratie_clasa : CLASS ID BGIN_CLASS  BGIN_MEMBRS membrii_clasa END_MEMBRS  BGIN_FUNCS functii_clasa END_FUNCS END_CLASS {symbolTable_popScope();};

membrii_clasa : declaratie_variabila membrii_clasa | declaratie_variabila;

functii_clasa : declaratie_functie functii_clasa  | declaratie_functie ;


instructiune : IF conditie_logica bloc_if {}
             | WHILE conditie_logica bloc_while {}
             | FOR ID IN range_for bloc_for {}
             | ID ASSIGN ID {
                 if(!symbolTable_Lookup($1))
                 {
                    handleError(NOT_DEFINED, $1);
                 }
                 if(!symbolTable_Lookup($3))
                 {
                    handleError(NOT_DEFINED, $3);
                 }
                 if(strcmp(symbolTable_GetTypeOfMember($1),symbolTable_GetTypeOfMember($3)) != 0)
                 {
                     handleError(NOT_THE_SAME_TYPE, "?");
                 }
                }
             ;
conditie_logica : '@';

bloc_if : BGIN_IF declaratii END_IF
        | BGIN_IF declaratii BGIN_ELSE declaratii END_IF

bloc_while : BGIN_WHILE declaratii END_WHILE;

range_for : '('INTREG ',' INTREG ')';

bloc_for : BGIN_FOR declaratii END_FOR;

/*<functii>*/
declaratie_functie : FUNCTION ID'('lista_parametrii')' '-''>' declaratie_tip_return bloc_functie {
                        //printf("functie magica\n");
                        //printf("Pam %s si pam %s", $4, $8);
                        char s1[3000], s[3000];
                        //sprintf(s, "%s %s", $4, $8);
                        char copieMagica[3000];
                        strcpy(s1, $8);
                        strcpy(s, $4);
                        strcpy(copieMagica, s);
                        char aux[10000];
                        int scris = 0;
                        int lungime = strlen(s);
                        for(int i = 0 ; i < strlen(s); ++i)
                        {
                            if(s[i] == ' ') --lungime;
                        }
                        int auxLungime = 0;
                        char *p = strtok(s, " ");
                        while(p)
                        {
                            auxLungime += strlen(p);
                            if(p[strlen(p) - 1] == ',')
                            {
                                strcat(aux,",");
                            }
                            else
                            {
                                //printf("token:%s\n", p);
                                if(!scris){
                                    strcpy(aux, p);
                                    scris = 1;
                                }
                                else
                                {
                                    if(auxLungime != lungime)
                                        strcat(aux,p);
                                    
                                }
                                   

                            }
                            p = strtok(NULL, " ");
                        }
                        //strcpy(s, aux);
                       // printf("uite asta a iesit: %s\n", aux);
                        strcat(aux, " -> ");
                        strcat(aux, s1);

                       // printf("Ce e in varf? %s\n", top->info);
                        symbolTable_InsertMember(aux, $2);
                   
                   
                        
                        //char type[300];
                        //sprintf(type, "function (%s) -> %s", $4, $8);
                        //symbolTable_InsertMember(type, $2);
                    }
                   | FUNCTION ID'(' ')' '-''>' declaratie_tip_return bloc_functie
                   ;

declaratie_tip_return : TIP {$$ = $1;}
                    | CONST TIP {char s[100]; sprintf(s,"const %s", $2); $$ = s;}
                    | TIP'['INTREG']'{char s[100]; sprintf(s,"%s[%s]", $1, $3); $$ = s;}
                    | CLASS ID
                    | CLASS CONST ID
                    | CLASS ID'['INTREG']'
                    ;

bloc_functie : BGIN_FUNC declaratii END_FUNC;

lista_parametrii :  lista_parametrii ',' lista_parametrii  {char *s = (char*)malloc(1000); sprintf(s,"%s, %s",$1, $3); $$ = s; /*printf("magie uau %s\n",$$)*/;}
                 | declaratie_parametru {$$ = strdup($1); stiva_push(&functionParameters, $1);}
                 ;

declaratie_parametru : declaratie_tip_functie ID {char s[100]; sprintf(s,"%s %s", $1, $2); $$ = s; }
                     ;
                
declaratie_tip_functie : TIP {$$ = $1;}
                    | CONST TIP {char s[100]; sprintf(s,"const %s", $2); $$ = s;}
                    | TIP'['INTREG']'{char s[100]; sprintf(s,"%s[%s]", $1, $3); $$ = s;}
                    | CLASS ID
                    | CLASS CONST ID
                    | CLASS ID'['INTREG']'
                    ;
/*</functii>*/

/*<variabile>*/
declaratie_variabila : declaratie_tip declaratie_ids
                     ;
        
declaratie_ids : ID ',' declaratie_ids {symbolTable_InsertMember(currentTypeDeclared, $1);}
               | ID ASSIGN ID ',' declaratie_ids {
                   symbolTable_InsertMember(currentTypeDeclared, $1);
                    if(!symbolTable_Lookup($3))
                    {
                        handleError(NOT_DEFINED, $3);
                    }
                    if(strcmp(symbolTable_GetTypeOfMember($1),symbolTable_GetTypeOfMember($3)) != 0)
                    {
                        handleError(NOT_THE_SAME_TYPE, "?");
                    }
                }
               | ID {symbolTable_InsertMember(currentTypeDeclared, $1);}
               | ID ASSIGN ID {symbolTable_InsertMember(currentTypeDeclared, $1);}
               | ID ASSIGN CONSTANTA {symbolTable_InsertMember(currentTypeDeclared, $1);}
               ;

CONSTANTA : INTREG
          | REAL {printf("uuuf\n");}
          | STRING_CONST
          | CHAR_CONST
          ;
/*</variabile>*/
declaratie_tip: TIP {char * s= strdup($1); symbolTable_ChangeCurrentType(s);}
              | CONST TIP {char s[100]; sprintf(s,"const %s",$2); symbolTable_ChangeCurrentType(s);}
              | TIP'['INTREG']'{char s[100]; sprintf(s,"%s[%s]", $1, $3); symbolTable_ChangeCurrentType(s);}
              | CLASS ID
              | CLASS CONST ID
              | CLASS ID'['INTREG']'
              ;
%%



void yyerror(char * s){
    symbolTable_Print("symbolTable.txt");
    printf("linia : %s\n", yytext);
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

    top = stiva_createNode("global");
    functionParameters = stiva_createNode("bottom");
    current = symbolTable_CreateNode();
    currentTypeDeclared = (char*)malloc(30);
    current->name = Scope_GetInfo();
    radacina = current;
    yyparse();
    symbolTable_Print("symbolTable.txt");
}