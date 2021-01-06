#ifndef FUNCTIONSTACK_GUARD
#define FUNCTIONSTACK_GUARD

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"


typedef struct function_stiva_nod{
    struct function_stiva_nod * urm;
    struct info * info;
}function_stiva_nod;







function_stiva_nod * function_stiva_createNode(struct info * info)
{
    function_stiva_nod * node = (function_stiva_nod*) malloc(sizeof(function_stiva_nod));
    node->urm = NULL;
    //node->info = (char*) malloc(strlen(info) * sizeof(char));
    //strcpy(node->info, info);
    node->info = info;
    return node;
}

void function_stiva_push(function_stiva_nod ** stiva, struct info * element)
{
    function_stiva_nod * newNode = function_stiva_createNode(element);
    newNode->urm = (*stiva);
    *stiva = newNode;
}

void function_stiva_pop(function_stiva_nod ** stiva)
{
    if((*stiva)->urm != NULL)
    {
        function_stiva_nod *temp = *stiva;
        *stiva = (*stiva)->urm;
        //free(temp);
    }
}

void function_recursive_magic(function_stiva_nod *stiva, char *continut, int *lungime, const char *id)
{
    //printf("aici sunt iei %s\n", stiva->info->type);
    fflush(stdout);
    if(strcmp(stiva->urm->info->type, id) != 0)
    {
        function_recursive_magic(stiva->urm, continut, lungime, id);
    }

    if(strlen(continut) == 0)
    {
        strcpy(continut, stiva->info->type);
       // *lungime += strlen(stiva->info);
    }
    else{

        sprintf(continut,"%s,%s", continut, stiva->info->type);
        //*lungime += 2 + strlen(stiva->info);
        //strcpy(continut, aux);
    }
}

char * function_getInfo(function_stiva_nod *stiva, const char * id)
{
    char *continut = (char*)malloc(sizeof(char) * 10000); //speram sa fie suficient
    int lungime = 0;
    function_recursive_magic(stiva, continut, &lungime, id);
    //continut[lungime] = 0;
    //printf("lungimea este : %d", lungime);
    return continut;
}



#endif