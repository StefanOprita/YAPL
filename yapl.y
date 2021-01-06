  %{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "hashTable.h"
    #include "stiva.h"
    #include "scope.h"
    #include "symbolTable.h"
    #include "errorHandling.h"
    #include "syntaxTree.h"
    #include "parseSyntaxTree.h"


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
    int shouldParse = 1;
%}

%union{
    char* strval;
    char chrval;
    struct nodeType* nPtr;
}


%type<nPtr> declaratii instructiune expr program lista_parametrii_apel function_call declaratie_ids declaratie_variabila
%type<strval> declaratie_tip_return declaratie_tip_functie declaratie_parametru lista_parametrii
%token<strval> ID TIP CONST INTREG REAL STRING_CONST CLASS 
%token <chrval> CHAR_CONST
%token ASSIGN AUX END_OF_FILE IN SAGETICA EVAL
%token FUNCTION 
%token BGIN_FUNC END_FUNC BGIN_IF END_IF BGIN_ELSE
%token BGIN_MEMBRS END_MEMBRS BGIN_FUNCS END_FUNCS BGIN_CLASS END_CLASS
%token BGIN_WHILE END_WHILE BGIN_FOR END_FOR
%token IF WHILE FOR
%left NOT
%left AND OR
%left GE LE EQ NE GT LT
%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS



%start program

%%
program : declaratii  END_OF_FILE {
            if(shouldParse)
                parseSyntaxTree($1) ;
            spuneCevaFrumos();
            }
        ;
declaratii : declaratie_variabila declaratii {
                $$ = Node_OperatorNode(operatorSTAT, 2, $1, $2);
                printf("declar o variabila\n");}
           | declaratie_functie declaratii {$$ = $2;printf("declar o functie\n");}
           | declaratie_clasa declaratii {$$ = $2;printf("declar o clasa\n");}
           | instructiune declaratii {
               $$ = Node_OperatorNode(operatorSTAT, 2, $1, $2);
            }
           | declaratie_variabila {
               $$ = $1;
               symbolTable_popScope();
               }
           | declaratie_functie {symbolTable_popScope();}
           | declaratie_clasa {symbolTable_popScope();}
           | instructiune {
               //struct nodeType * nod = $1;
               //printf("%d <<-- te rog\n", nod->type);
               symbolTable_popScope();
               $$ = $1;
            }
           ;
/*<expresii>*/
expr :  ID'['expr']' {
            struct symbolTable_nod * p = symbolTable_Lookup($1);
            if(p == NULL)
            {
                handleError(NOT_DEFINED, $1);
            }
            struct nodeType * idNode = Node_IdNode(p, $1);
            struct nodeType *  accesNode = Node_OperatorNode(operatorACCESARRAY, 2 , idNode, $3);
            $$ = accesNode;
        }
     | function_call {;$$ = $1;}
     | INTREG {int value = atoi($1); $$ = Node_ConstantInt(value);}
     | REAL {float value = atof($1);printf("the valuea of float is %f\n and the string %s\n", value, $1); $$ = Node_ConstantFloat(value);}
     | STRING_CONST {$$ = Node_ConstantString($1);}
     | CHAR_CONST {$$ = Node_ConstantChar($1);}
     | ID {
         struct symbolTable_nod * p = symbolTable_Lookup($1);
         if(p == NULL)
         {
             handleError(NOT_DEFINED, $1);
         }
         $$ = Node_IdNode(p, $1);
         }
     | MINUS expr %prec UMINUS {$$ = Node_OperatorNode(operatorUMINUS, 1, $2); }
     | expr PLUS expr {struct nodeType* n = Node_OperatorNode(operatorPLUS, 2, $1 , $3);;$$ = n;}
     | expr MINUS expr {$$ = Node_OperatorNode(operatorMINUS, 2, $1, $3);}
     | expr MULT expr { $$ = Node_OperatorNode(operatorMULT, 2, $1, $3);}
     | expr DIV expr { $$ = Node_OperatorNode(operatorDIV, 2, $1, $3);}
     | expr LT expr { $$ = Node_OperatorNode(operatorLT, 2, $1, $3);}
     | expr GT expr { $$ = Node_OperatorNode(operatorGT, 2, $1, $3);}
     | expr GE expr { $$ = Node_OperatorNode(operatorGE, 2, $1, $3);}
     | expr LE expr { $$ = Node_OperatorNode(operatorLE, 2, $1, $3);}
     | expr EQ expr { $$ = Node_OperatorNode(operatorEQ, 2, $1, $3);}
     | expr NE expr {$$ = Node_OperatorNode(operatorNE, 2, $1, $3);}
     | expr AND expr {$$ = Node_OperatorNode(operatorAND, 2, $1, $3);}
     | expr OR expr {$$ = Node_OperatorNode(operatorOR, 2, $1, $3);}
     | '(' expr ')' { $$ = $2;}
     | NOT expr {$$ = Node_OperatorNode(operatorNOT, 1, $2);}
     ;

/*</expresii>*/
declaratie_clasa : CLASS ID BGIN_CLASS  BGIN_MEMBRS membrii_clasa END_MEMBRS  BGIN_FUNCS functii_clasa END_FUNCS END_CLASS {symbolTable_popScope(); shouldParse = 0;};

membrii_clasa : declaratie_variabila membrii_clasa | declaratie_variabila;

functii_clasa : declaratie_functie functii_clasa  | declaratie_functie ;


instructiune : IF expr BGIN_IF declaratii END_IF {
                    $$ = Node_OperatorNode(operatorIF, 2, $2, $4);
                }
             | WHILE expr BGIN_WHILE declaratii END_WHILE {
                    $$ = Node_OperatorNode(operatorWHILE, 2, $2, $4);
                }
             | FOR ID IN range_for bloc_for {}
             | ID ASSIGN expr {
                 struct nodeType* node1 = $3;
                struct symbolTable_nod * p = symbolTable_Lookup($1);
                if(p == NULL)
                {
                    handleError(NOT_DEFINED, $1);
                }
                 struct nodeType* node = Node_IdNode(p, $1);
                 printf("tipuuuul %d %d\n", node->type, typeId);
                 struct nodeType* node2 =  Node_OperatorNode(operatorASSIGN, 2, node, node1);
                 $$ = node2;
                 //parseSyntaxTree($$);
               }
             | ID'['expr']' ASSIGN expr {
                    struct symbolTable_nod * p = symbolTable_Lookup($1);
                    if(p == NULL)
                    {
                        handleError(NOT_DEFINED, $1);
                    }
                    struct nodeType * idNode = Node_IdNode(p, $1);
                    struct nodeType *  accesNode = Node_OperatorNode(operatorACCESARRAY, 2 , idNode, $3);
                    $$ = Node_OperatorNode(operatorASSIGN, 2 , accesNode, $6);
                }
             | function_call { ;$$ = $1;}
             | EVAL '('expr')' {$$ = Node_OperatorNode(operatorEVAL, 1, $3);}
             ;
range_for : '('INTREG ',' INTREG ')';

bloc_for : BGIN_FOR declaratii END_FOR;

/*<functii>*/
declaratie_functie : FUNCTION ID'('lista_parametrii')' SAGETICA declaratie_tip_return BGIN_FUNC declaratii END_FUNC {
                        //printf("functie magica\n");
                        //printf("Pam %s si pam %s", $4, $8);
                        char s1[3000], s[3000];
                        //sprintf(s, "%s %s", $4, $8);
                        char copieMagica[3000];
                        strcpy(s1, $7);
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
                        char copyOfAux[100];
                        strcpy(copyOfAux, aux);
                        strcat(aux, " -> ");
                        strcat(aux, s1);

                       // printf("Ce e in varf? %s\n", top->info);
                    
                        struct symbolTable_nod * nod = symbolTable_InsertMember(aux, $2);
                        char trueSignature[1000];
                        

                        sprintf(trueSignature, "%s(%s)", $2, copyOfAux);

                        AddFunction(trueSignature, nod, $9, yylineno);
                   
                        
                        //char type[300];
                        //sprintf(type, "function (%s) -> %s", $4, $8);
                        //symbolTable_InsertMember(type, $2);
                    }
                   | FUNCTION ID'(' ')' SAGETICA declaratie_tip_return BGIN_FUNC declaratii END_FUNC {
                        char aux[300];
                        char copie[100];
                        strcpy(copie, $6);
                        sprintf(aux, "void -> %s", copie);
                        struct symbolTable_nod * nod = symbolTable_InsertMember(aux, $2);
                        char trueSignature[1000];
                        sprintf(trueSignature, "%s(void)", $2);

                        AddFunction(trueSignature, nod, $8, yylineno);
                    }
                   ;

declaratie_tip_return : TIP {$$ = $1;}
                    | CONST TIP {char s[100]; sprintf(s,"const %s", $2); $$ = s;}
                    | TIP'['INTREG']'{char s[100]; sprintf(s,"%s[%s]", $1, $3); $$ = s;}
                    | CLASS ID
                    | CLASS CONST ID
                    | CLASS ID'['INTREG']'
                    ;



lista_parametrii :  lista_parametrii ','  declaratie_parametru  {;char *s = (char*)malloc(1000); sprintf(s,"%s, %s",$1, $3); $$ = s; stiva_push(&functionParameters, $1); printf("magie uau %s\n", $3);}
                 | declaratie_parametru {printf("varful scope %s\n",current->name);;strcpy($$, $1); stiva_push(&functionParameters, $1);}
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

function_call : ID '('lista_parametrii_apel')' {
                    printf("apelam o functie ieeeei\n");
                    $$ = Node_FunctionCall($1, $3, yylineno);
                }
              | ID '('')' {
                    $$ = Node_FunctionCall($1, NULL , yylineno);
              };

lista_parametrii_apel : expr ',' lista_parametrii_apel {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, $1);
                            $$ = Node_OperatorNode(operatorSTAT, 2, nodeAssign, $3);

                        }
                      | expr {
                            printf("sunt un parametru uau\n");
                            struct nodeType * nodeAssign = Node_OperatorNode(operatorASSIGN, 2, NULL, $1);
                            $$ = Node_OperatorNode(operatorSTAT, 2, nodeAssign, NULL);
                          }
                      ;

/*</functii>*/

/*<variabile>*/
declaratie_variabila : declaratie_tip declaratie_ids {$$  = $2;}
                     ;
        
declaratie_ids : ID ',' declaratie_ids {
                    if(strstr(currentTypeDeclared, "const") != NULL)
                    {
                        handleError(JUST_SAY_WHAT_I_SAY, "An constant value must be initialized!\n");
                    }
                    symbolTable_InsertMember(currentTypeDeclared, $1);
                    $$ = Node_OperatorNode(operatorSTAT, 2, NULL, $3);
                }
               | ID ASSIGN expr ',' declaratie_ids {
                   symbolTable_InsertMember(currentTypeDeclared, $1);
                   struct nodeType * idNode = Node_IdNode(current, $1);
                   struct nodeType * assignNode = Node_OperatorNode(operatorASSIGN, 2, idNode, $3);
                   $$ = Node_OperatorNode(operatorSTAT, 2, assignNode, $5);
                   
                }
               | ID ASSIGN expr {
                   symbolTable_InsertMember(currentTypeDeclared, $1);
                   struct nodeType * idNode = Node_IdNode(current, $1);
                   struct nodeType * assignNode = Node_OperatorNode(operatorASSIGN, 2, idNode, $3);
                   $$ = assignNode;
                }
               | ID {
                    if(strstr(currentTypeDeclared, "const") != NULL)
                    {
                        handleError(JUST_SAY_WHAT_I_SAY, "An constant value must be initialized!\n");
                    }
                   symbolTable_InsertMember(currentTypeDeclared, $1);

                   }
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
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}   


int main(int argc,  char** argv)
{
    if(argc < 2)
    {
        PrintError("Nu-i bini, trebuie macar un argument");       
    }
    yyin = fopen(argv[1], "r");
    EvalStack = stiva_createNode("");
    top = stiva_createNode("global");
    functionParameters = stiva_createNode("bottom");
    current = symbolTable_CreateNode();
    currentTypeDeclared = (char*)malloc(30);
    current->name = Scope_GetInfo();
    radacina = current;
    yyparse();
    symbolTable_Print("symbolTable.txt");
    EvalPrint(EvalStack);
}
