#ifndef STIVA_GUARD
#define STIVA_GUARD

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stiva_nod{
    struct stiva_nod * urm;
    char * info;
}stiva_nod;


stiva_nod * EvalStack;




stiva_nod * stiva_createNode(const char * info)
{
    stiva_nod * node = (stiva_nod*) malloc(sizeof(stiva_nod));
    node->urm = NULL;
    node->info = (char*) malloc(strlen(info) * sizeof(char));
    strcpy(node->info, info);
    return node;
}

void stiva_push(stiva_nod ** stiva, const char * element)
{
    stiva_nod * newNode = stiva_createNode(element);
    newNode->urm = (*stiva);
    *stiva = newNode;
}

void stiva_pop(stiva_nod ** stiva)
{
    if((*stiva)->urm != NULL)
    {
        stiva_nod *temp = *stiva;
        *stiva = (*stiva)->urm;
        free(temp);
    }
}

void recursive_magic(stiva_nod *stiva, char *continut, int *lungime)
{
    //printf("aici sunt iei %s\n", stiva->info);
    fflush(stdout);
    if(stiva->urm != NULL)
    {
        recursive_magic(stiva->urm, continut, lungime);
    }

    if(strlen(continut) == 0)
    {
        strcpy(continut, stiva->info);
        *lungime += strlen(stiva->info);
    }
    else{

        sprintf(continut,"%s::%s", continut, stiva->info);
        *lungime += 2 + strlen(stiva->info);
        //strcpy(continut, aux);
    }
}

char * getInfo(stiva_nod *stiva)
{
    char *continut = (char*)malloc(sizeof(char) * 10000); //speram sa fie suficient
    int lungime = 0;
    recursive_magic(stiva, continut, &lungime);
    //continut[lungime] = 0;
    //printf("lungimea este : %d", lungime);
    return continut;
}

void EvalPrint(stiva_nod *stiva)
{
    if(stiva == NULL) return;
    EvalPrint(stiva->urm);
    printf("%s\n", stiva->info);
}




#endif
