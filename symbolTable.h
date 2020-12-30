#ifndef SYMBOLTABLE_GUARD
#define SYMBOLTABLE_GUARD

#include "scope.h"

stiva_nod * top;
stiva_nod * functionParameters;


typedef struct info
{
    char * type;
    char * scope;
    char * id; 
    int isArray;
    void * value; //nu vreau sa ne folosim de asta dar o pun sa fie...
}info;

//containerul trebuie modificat, momentan e un vector...
//ar fi frumos sa fie un hashtable, arbore binar sau macar o lista 
//but ain't nobody got time for that rn
typedef struct container
{
    struct info cont[1000];
    int size;
}container;

void Add2Container(struct container *c,struct info inf)
{
    c->cont[c->size++] = inf;
}


typedef struct symbolTable_nod
{
    char * name;
    struct container cont;
    struct symbolTable_nod *parinte;
    //din nou.. ar fi frumos sa nu fie un vector
    struct symbolTable_nod *fii[10000];
    int nrCopilasi;
}symbolTable_nod;

symbolTable_nod * current;
symbolTable_nod * radacina;
char * currentTypeDeclared;



void symbolTable_ChangeCurrentType(const char *newType)
{
    strcpy(currentTypeDeclared, newType);
    //printf("%s\n",currentTypeDeclared);
}

symbolTable_nod * symbolTable_CreateNode()
{
    symbolTable_nod * newNode = (symbolTable_nod*) malloc(sizeof(symbolTable_nod));
    newNode->nrCopilasi = 0;
    newNode->cont.size = 0;
    return newNode;
}

void symbolTable_pushScope(const char * name)
{
    Scope_push(name);
    symbolTable_nod * newNode = symbolTable_CreateNode();
    current->fii[current->nrCopilasi++] = newNode;
    newNode->parinte = current;
    current = newNode;
    current->name = Scope_GetInfo();
}


void symbolTable_CheckClassOrFunc(const char * name)
{
    Scope_CheckClassOrFunc(name);
    free(current->name);
    current->name = Scope_GetInfo();
}

void symbolTable_popScope()
{
    //printf("apelam pop\n");
    Scope_pop();
    current = current->parinte;
}

int symbolTable_InsertFunctionParameters()
{
    //printf("parametru de functie : %s\n", functionParameters->info);
}

int symbolTable_InsertMember(const char * type, const char * id)
{
    //printf("am plecat sa inseram : %s %s\n", type, id);
    fflush(stdout);
    if(!symbolTable_LookUpThisScope(current, id))
    {
       // printf("pe bune ca inseram: %s %s\n", type, id);
        fflush(stdout);
        struct info temp;
        temp.type = (char*) malloc(strlen(type));
        strcpy(temp.type, type);
        temp.id = (char*) malloc(strlen(id));
        strcpy(temp.id, id);
        Add2Container(&current->cont, temp);
        fflush(stdout);
        return 0;
    }
    else{
        //printf("NU-I BINE WE\n");
        return -1;
    }
}

int symbolTable_LookUpThisScope(symbolTable_nod * scope,const char * id)
{
    for(int i = 0 ; i < scope->cont.size; ++i)
    {
        if(strcmp(id, scope->cont.cont[i].id) == 0) return 1;
    }

    return 0;
}

int symbolTable_Lookup(const char * id)
{
    symbolTable_nod * temp = current;

    while(temp != NULL)
    {
        if(symbolTable_LookUpThisScope(temp, id)) return 1;
        temp = temp->parinte;
    }

    return 0;
}

void AddSpaces(FILE * file, int nb)
{
    for(int i = 0 ; i < nb; ++i)
    {
        fprintf(file, " ");
    }
}

void PrintInfo(FILE* file, info inf)
{
    fprintf(file, " Type: %s", inf.type);
    fprintf(file, " Id: %s", inf.id);
}

void RecursivePrint(FILE * file, symbolTable_nod * node, int level)
{
    AddSpaces(file, level);
    fprintf(file, "Scope: %s\n", node->name);
    AddSpaces(file, level);
    fprintf(file, "Symbols:\n");
    for(int i = 0 ; i < node->cont.size; ++i)
    {
      AddSpaces(file, level);
      PrintInfo(file, node->cont.cont[i]);  
      fprintf(file, "\n");
    }
    AddSpaces(file, level);
    fprintf(file, "Childs: \n");
    for(int i = 0 ; i < node->nrCopilasi; ++i)
    {
        RecursivePrint(file, node->fii[i], level + 1);
    }
}

void symbolTable_Print(const char * fileName)
{
    FILE * output = fopen(fileName,"w");
    RecursivePrint(output, radacina, 0);

}

#endif