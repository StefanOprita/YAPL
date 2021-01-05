#ifndef SYMBOLTABLE_GUARD
#define SYMBOLTABLE_GUARD
#include "scope.h"
#include "errorHandling.h"

stiva_nod * top;
stiva_nod * functionParameters;
int classFunctIncoming = 0;
char nameOfClassFunc[1000];


typedef struct info
{
    
    char * type;
    char * scope;
    char * id; 
    int isArray;
    int sizeOfArray;
    int isFunction;
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
    if(strcmp(name, "class") == 0)
    {
        //printf("%d Scope push : %s\n", yylineno, nameOfClassFunc);
        Scope_push(nameOfClassFunc);
        symbolTable_nod * newNode = symbolTable_CreateNode();
        current->fii[current->nrCopilasi++] = newNode;
        newNode->parinte = current;
        current = newNode;
        current->name = Scope_GetInfo();
        return;
    }

    if(strcmp(name, "function") == 0)
    {
        //printf("%d Scope push : %s\n", yylineno, nameOfClassFunc);
        Scope_push(nameOfClassFunc);
        symbolTable_nod * newNode = symbolTable_CreateNode();
        current->fii[current->nrCopilasi++] = newNode;
        newNode->parinte = current;
        current = newNode;
        current->name = Scope_GetInfo();

        while(strcmp(functionParameters->info, "bottom") != 0)
        {
            char copie[100];
            strcpy(copie, functionParameters->info);
            char type[100];
            char id[100];
            char *p = strtok(copie, " ");
            strcpy(type, p);
            p = strtok(NULL, "  ");
            strcpy(id, p);
            symbolTable_InsertMember(type, id);
            stiva_pop(&functionParameters);
        }

        return;
    }

    //printf("%d Scope push : %s\n", yylineno, name);
    Scope_push(name);
    symbolTable_nod * newNode = symbolTable_CreateNode();
    current->fii[current->nrCopilasi++] = newNode;
    newNode->parinte = current;
    current = newNode;
    current->name = Scope_GetInfo();
}


void symbolTable_CheckClassOrFunc(const char * name)
{
    /*Scope_CheckClassOrFunc(name);
    free(current->name);
    current->name = Scope_GetInfo();*/
    if(classFunctIncoming)
    {
        classFunctIncoming = 0;
        strcpy(nameOfClassFunc, name);
    }
}

void symbolTable_popScope()
{
    //printf("apelam pop\n");
    //printf("%d Scope pop\n ", yylineno);
    Scope_pop();
    current = current->parinte;
}

int symbolTable_InsertFunctionParameters()
{
    //printf("parametru de functie : %s\n", functionParameters->info);
}

int symbolTable_InsertMember(const char * type, const char * id)
{
    
    printf("am plecat sa inseram : %s %s\n", type, id);

    //asta inseamna ca e functie si functiile is mai speciale na...
    
    if(strstr(type, "->") != NULL)
    {
        char signature[100];
        strcpy(signature, type);
        char *p = strtok(signature, " ");
        
        if(!symbolTable_Function_LookUpThisScope(current, signature, id))
        {
            //printf("aici\n");
            fflush(stdout);
            struct info temp;
            temp.type = (char*) malloc(strlen(type));
            strcpy(temp.type, type);
            temp.id = (char*) malloc(strlen(id));
            strcpy(temp.id, id);
            //printf("Cat de ciudat... %s %s\n", temp.type, temp.id);
            Add2Container(&current->cont, temp);
            char scopeNou[200];
            sprintf(scopeNou, "%s(%s)", temp.id, signature);
            p = strtok(NULL, " ");
            p = strtok(NULL, " ");
            char returnType[100];
            strcpy(returnType, p);
            int i;
            for(i = 0; i < current->nrCopilasi; ++i)
            {
                char aux[200];
                 //printf("ajung aici nebunule %s\n", current->fii[i]->name);
                 strcpy(aux, current->fii[i]->name);
                int deUndeIncepe = strlen(aux);
                for(;deUndeIncepe >= 0; deUndeIncepe--)
                {
                    if(aux[deUndeIncepe] == ':')
                        break;
                }
                if(strcmp(aux + deUndeIncepe + 1, temp.id) == 0)
                {
                   
                    free(current->fii[i]->name);
                    current->fii[i]->name = (char*)malloc(strlen(scopeNou));
                    strcpy(current->fii[i]->name, scopeNou);
                    int j;
                   
                    for(j = 0; j < current->fii[i]->cont.size; ++j)
                    {
                    
                        if(strcmp(current->fii[i]->cont.cont[j].id, "return") == 0)
                        {
                            free(current->fii[i]->cont.cont[j].type);
                            current->fii[i]->cont.cont[j].type = (char*)malloc(strlen(returnType));
                            strcpy(current->fii[i]->cont.cont[j].type, returnType);
                            break;
                        }
                    }
                    break;
                }
            }
            
            
            fflush(stdout);
            
            return 0;
        }
        else
        {
            char nameWithSignature[100];
            //sprintf(nameWithSignature,"%s (%s)", id, signature);

            handleError(ALREADY_DEFINED, nameWithSignature);
            return -1;
        }
        
   
        return 0;
    }


    fflush(stdout);
    //printf("%d %s %s The Scope : %s\n", yylineno, type, id, current->name);
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
        handleError(ALREADY_DEFINED, id);
        return -1;
    }
}


int symbolTable_Function_LookUpThisScope(symbolTable_nod * scope,const char * signature, const char * id)
{

    for(int i = 0 ; i < scope->cont.size; ++i)
    {
        if(strcmp(id, scope->cont.cont[i].id) != 0) continue;
        char signatureAux[100];
        strcpy(signatureAux, scope->cont.cont[i].type);
        char *p = strtok(signatureAux, " ");
        //printf("mare comparatie : %s %s\n", p, signature);
        if(strcmp(p, signature) == 0) return 1;
    }

    return 0;
}

int symbolTable_Function_Lookup(const char * signature, const char * id)
{
    symbolTable_nod * temp = current;

    while(temp != NULL)
    {
        if(symbolTable_Function_LookUpThisScope(temp, signature, id)) return 1;
        temp = temp->parinte;
    }

    return 0;
}


int symbolTable_LookUpThisScope(symbolTable_nod * scope,const char * id)
{
    for(int i = 0 ; i < scope->cont.size; ++i)
    {
        if(strcmp(id, scope->cont.cont[i].id) == 0) return 1;
    }

    return 0;
}

int symbolTable_NeedPointer_LookUpThisScope(symbolTable_nod * scope,const char * id, info **returnable)
{
    for(int i = 0 ; i < scope->cont.size; ++i)
    {
        if(strcmp(id, scope->cont.cont[i].id) == 0){
            (*returnable) = &scope->cont.cont[i];
            return 1;
        }
    }

    return 0;
}

int symbolTable_NeedPointer_Lookup(const char * id, info **returnable)
{
    symbolTable_nod * temp = current;

    while(temp != NULL)
    {
        if(symbolTable_NeedPointer_LookUpThisScope(temp, id, returnable)){

            return 1;
        }
        temp = temp->parinte;
    }

    return 0;
}

symbolTable_nod* symbolTable_Lookup(const char * id)
{
    symbolTable_nod * temp = current;

    while(temp != NULL)
    {
        if(symbolTable_LookUpThisScope(temp, id)) return temp;
        temp = temp->parinte;
    }

    return NULL;
}

char * symbolTable_Function_GetTypeOfMember(const char * signature, const char * id)
{
    symbolTable_nod * temp = current;
    while(temp != NULL)
    {
         if(symbolTable_Function_LookUpThisScope(temp, signature, id))
        {
            for(int i = 0 ; i < temp->cont.size; ++i)
            {
                if(strcmp(id, temp->cont.cont[i].id) != 0) continue;
                char signatureAux[100];
                strcpy(signatureAux, temp->cont.cont[i].type);
                char *p = strtok(signatureAux, " ");
                //printf("mare comparatie : %s %s\n", p, signature);
                if(strcmp(p, signature) != 0) continue;
                p = strtok(NULL, " ");
                p = strtok(NULL, " ");
                return p;
            }
        }

        temp = temp->parinte;
    }

    return NULL;
}


char *  symbolTable_GetTypeOfMember(const char * id)
{
    symbolTable_nod * temp = current;
    while(temp != NULL)
    {
        if(symbolTable_LookUpThisScope(temp, id))
        {
            for(int i = 0 ; i < temp->cont.size; ++i)
            {
                if(strcmp(id, temp->cont.cont[i].id) == 0){
                    int len = strlen(temp->cont.cont[i].type);
                    char * copyOfType =(char*)malloc(len);
                    strcpy(copyOfType, temp->cont.cont[i].type);
                    return copyOfType;
                };
            }
        }
        temp = temp -> parinte;
    }
    return NULL;
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
    if(inf.value == NULL)
    {
        fprintf(file, " Value: (null)");
    }
    else{
        //fprintf(file, " Value : %d", *((int*)inf.value));
        if(strcmp(inf.type, "string") == 0)
        {
            fprintf(file, " Value : \"%s\"", (char*)inf.value);
        }
        if(strcmp(inf.type,"int") == 0)
        {
            fprintf(file, " Value : %d", *((int*)inf.value));
        }
        if(strcmp(inf.type, "float") == 0)
        {
            fprintf(file, " Value : %f", *((float*)inf.value));
        }
    }
    
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