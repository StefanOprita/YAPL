#ifndef ERRORHANDLING_GUARD
#define ERRORHANDLING_GUARD
#define NOT_DEFINED 0
#define NOT_THE_SAME_TYPE 1
#define ALREADY_DEFINED 2
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;

void handleError(int errorCode, const char * id)
{
    printf("At line %d :", yylineno);
    switch (errorCode)
    {
    case NOT_DEFINED: printf("%s is not defined!", id); 
        /* code */
        break;
    case NOT_THE_SAME_TYPE: printf("Not the same type!");
        break;
    case ALREADY_DEFINED: printf("%s is already defined!", id);
        break;
    default:
        break;
    }
    printf("\n");
    exit(EXIT_FAILURE);
}

#endif