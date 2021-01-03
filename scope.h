#ifndef SCOPE_GUARD
#define SCOPE_GUARD

#include "stiva.h"


stiva_nod * top;

char* Scope_GetInfo()
{
    char *uau = getInfo(top);
    //printf("%s\n", uau);
    return uau;
}


char* Scope_Top()
{
    return top->info;
}

void Scope_push(const char * element)
{
    stiva_push(&top, element);
    Scope_GetInfo();
}

void Scope_pop()
{
    stiva_pop(&top);
    Scope_GetInfo();
}



void Scope_CheckClassOrFunc(const char * element)
{
    char *temp = (char*)malloc(10);
    strcpy(temp, Scope_Top());
    if(strcmp(temp, "class") == 0)
    {
        Scope_pop();
        Scope_push(element);
    }
    if(strcmp(temp, "function") == 0)
    {
        Scope_pop();
        Scope_push(element);
    }
}


#endif SCOPE_GUARD