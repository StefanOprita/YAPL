#ifndef PARSESYNTAXTREE_GUARD
#define PARSESYNTAXTREE_GUARD
#include "syntaxTree.h"
#include "symbolTable.h"
#include "errorHandling.h"

char* returnResult(const char* r1, const char* r2)
{
    char result[100];
    strcpy(result, "?");
    if(strcmp(r1, r2) == 0)
    {
        strcpy(result, r1);
        
    }
    if(strcmp(r1, "int") == 0 && strcmp(r2, "float") == 0)
    {
        strcpy(result,"float");
    }
    if(strcmp(r1, "float") == 0 && strcmp(r2, "int") == 0)
    {
        strcpy(result,"float");
    }
    if(strcmp(r1, "bool") == 0 || strcmp(r2, "bool") == 0)
    {
        strcpy(result,"bool");
    }
  
    char *aux;
    aux = (char*)malloc(strlen(result));
    strcpy(aux, result);

    return aux;
}

info* parseSyntaxTree(nodeType *p)
{
    //printf("hei buyna\n");
    if(!p) return NULL;
    //printf("%d tipuuuul\n", p->type);
    switch (p->type)
    {
    case typeId :
    {
        //printf("sunt un o variabila uuu\n");
        struct info * returnable;
        printf("ulalal o variabila %s unde e scopul ei? %s\n", p->id.identifier ,p->id.theScope->name);
        symbolTable_NeedPointer_LookUpThisScope(p->id.theScope, p->id.identifier, &returnable);
        return returnable;
    }
    case typeConstantInteger: {
            //printf("sunt un integer uuu\n");
            
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            returnable->type = (char*)malloc(strlen("int"));
            strcpy(returnable->type, "int");
            
            returnable->value = (int*)malloc(sizeof(int));
            //printf("banane in pijamale\n");
            *((int*)(returnable->value)) = p->conInt.value;
            //printf("%d banane in pijamale\n", *((int*)(returnable->value)));
            return returnable;
        }
        break;
    case typeConstantFloat: {
            printf("uuu sunt un float\n");
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            returnable->type = (char*)malloc(strlen("float"));
            strcpy(returnable->type, "float");
            
            returnable->value = (float*)malloc(sizeof(float));
            //printf("banane in pijamale\n");
            *((float*)(returnable->value)) = p->conFlt.value;
            //printf("%d banane in pijamale\n", *((int*)(returnable->value)));
            return returnable;
        }
        break;
    case typeConstantString: {
            printf("sunt un string uuuu\n");
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            returnable->type = (char*)malloc(strlen("string"));
            strcpy(returnable->type, "string");
            
            returnable->value = (char*)malloc(strlen(p->conStr.value));
            strcpy((char*)returnable->value, p->conStr.value);

            //returnable->value = (float*)malloc(sizeof(float));
            //printf("banane in pijamale\n");
            //*((float*)(returnable->value)) = p->conFlt.value;
            //printf("%d banane in pijamale\n", *((int*)(returnable->value)));
            return returnable;
    }
    case typeOperator: {
        //printf("tipul operatorului magic %d\n", p->opr.type);
        switch (p->opr.oper)
        {
        case operatorPLUS: {
            printf("uuuu sunt plus\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen(type));
            strcpy(returnable->type, type);
          
            if(strcmp(type,"string") == 0)
            {
                char concatenate[100];
                sprintf(concatenate,"%s%s", (char*)rez1->value, (char*)rez2->value);
                returnable->value = (char*)malloc(strlen(concatenate));
                strcpy((char*)returnable->value, concatenate);    
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((float*)returnable->value) = value1 + value2;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = *((int*)rez1->value) + *((int*)rez2->value);
            }
            
            return returnable;
        }
            break;
        case operatorMINUS: {
            printf("uuuu sunt minus\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen(type));
            strcpy(returnable->type, type);
          
            if(strcmp(type,"string") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY,"The operator \'-\' doesn't exists for strings");
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((float*)returnable->value) = value1 - value2;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = *((int*)rez1->value) - *((int*)rez2->value);
            }
            
            return returnable;
        }break;
        case operatorMULT:{
            printf("uuuu sunt inmultit\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen(type));
            strcpy(returnable->type, type);
          
            if(strcmp(type,"string") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY,"The operator \'*\' doesn't exists for strings");
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((float*)returnable->value) = value1 * value2;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = *((int*)rez1->value) * *((int*)rez2->value);
            }
            
            return returnable;
        }break;
        case operatorDIV: {
            printf("uuuu sunt impartit\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen(type));
            strcpy(returnable->type, type);
          
            if(strcmp(type,"string") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY,"The operator \'-\' doesn't exists for strings");
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
    
                *((float*)returnable->value) = value1 / value2;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = *((int*)rez1->value) / *((int*)rez2->value);
            }
            
            return returnable;
        }break;
        case operatorASSIGN: {
        
            fflush(stdout);
            struct info* var = parseSyntaxTree(p->opr.op1);
            struct info* result = parseSyntaxTree(p->opr.op2);
            
            if(strcmp(var->type,"string") == 0)
            {
                if(strcmp(result->type,"string") !=0)
                {
                    handleError(JUST_SAY_WHAT_I_SAY, "Can't copy non-string into a string");
                }
                if(var->value != NULL)
                {
                    free(var->value);
                }
                var->value = (char*)malloc(strlen((char*)result->value));
                strcpy((char*)var->value, (char*)result->value);
            }
            if(strcmp(var->type, "float") == 0)
            {
                printf("aici sunt la float\n");
                if(strcmp(result->type,"string") == 0)
                {
                    handleError(JUST_SAY_WHAT_I_SAY, "Can't copy string into a non-string");
                }
                if(var->value == NULL)
                {
                    var->value = (float*)malloc(sizeof(float));
                }
                float value;
                if(strcmp(result->type, "int") == 0)
                {
                     printf("in acest caz int\n");
                    value = *((int*)result->value);
                }
                else
                {
                    printf("in acest caz\n");
                    value = *((float*)result->value);
                }
                
                *((float*)var->value) = value;
            }
            if(strcmp(var->type, "int") == 0)
            {

                if(strcmp(result->type,"string") == 0)
                {
                    handleError(JUST_SAY_WHAT_I_SAY, "Can't copy string into a non-string");
                }
                if(var->value == NULL)
                {
                    var->value = (int*)malloc(sizeof(int));
                }
                int value;
                if(strcmp(result->type, "float") == 0)
                {
                    value = *((float*)result->value);
                }
                else{
                    value = *((int*)result->value);
                }
                *((int*)var->value) = value;
            }
            return var;
        }break;
        case operatorUMINUS: {
            printf("uuuu sunt Uminus\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            char type[100];
            strcpy(type, rez1->type);
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen(type));
            strcpy(returnable->type, type);
          
            if(strcmp(type,"string") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY,"The operator \'-\' doesn't exists for strings");
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }                
                *((float*)returnable->value) = -value1 ;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = - *((int*)rez1->value);
            }
            
            return returnable;
        }
        case operatorLT: {
            printf("uuuu sunt un <\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez < 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 < value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                printf("%d < %d ?", *((int*)rez1->value), *((int*)rez2->value));
                *((int*)returnable->value) = (*((int*)rez1->value) < *((int*)rez2->value))? 1: 0;
                printf(" result = %d", *((int*)returnable->value));
            }
            
            return returnable;
        } break;
        case operatorGT: {
            printf("uuuu sunt un >\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez > 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 > value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = (*((int*)rez1->value) > *((int*)rez2->value))? 1: 0;
            }
            
            return returnable;
        }break;
        case operatorLE: {
            printf("uuuu sunt un <=\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez <= 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 <= value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = (*((int*)rez1->value) <= *((int*)rez2->value))? 1: 0;
            }
            
            return returnable;
        }break;
        case operatorGE: {
            printf("uuuu sunt un >=\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez >= 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 >= value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = (*((int*)rez1->value) >= *((int*)rez2->value))? 1: 0;
            }
            
            return returnable;
        }break;
        case operatorEQ: {
            printf("uuuu sunt un ==\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez == 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 == value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = (*((int*)rez1->value) == *((int*)rez2->value))? 1: 0;
            }
            
            return returnable;
        }break;
        case operatorNE: {
            printf("uuuu sunt un !=\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
          
            if(strcmp(type,"string") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                int rez = strcmp((char*)rez1->value, (char*)rez2->value);
                 *((int*)returnable->value) = (rez != 0) ? 1: 0;
                   
            }

            if(strcmp(type,"float") == 0)
            {
                returnable->value = (float*)malloc(sizeof(float));
                float value1, value2;
                if(strcmp(rez1->type,"int") == 0)
                {
                    value1 = *((int*)rez1->value);
                }
                else{
                    value1 = *((float*)rez1->value);
                }
                if(strcmp(rez2->type,"int") == 0)
                {
                    value2 = *((int*)rez2->value);
                }
                else{
                    value2 = *((float*)rez2->value);
                }
                
                *((int*)returnable->value) = (value1 != value2)? 1 : 0;
                
            }

            if(strcmp(type, "int") == 0)
            {
                returnable->value = (int*)malloc(sizeof(int));
                *((int*)returnable->value) = (*((int*)rez1->value) != *((int*)rez2->value))? 1: 0;
            }
            
            return returnable;
        }break;
        case operatorAND: {
            printf("uuuu sunt un &&\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
            returnable->value = (int*)malloc(sizeof(int));
            int value1, value2;
            if(strcmp(rez1->type, "string") == 0) 
            {
                value1 = 1;
            }
            if(strcmp(rez2->type, "string") == 0) 
            {
                value2 = 1;
            }
            if(strcmp(rez1->type, "int") == 0) 
            {
                if(*(int*)rez1->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez2->type, "int") == 0) 
            {
                if(*(int*)rez2->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
               if(strcmp(rez1->type, "int") == 0) 
            {
                if(*(int*)rez1->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez2->type, "float") == 0) 
            {
                if(*(float*)rez2->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez1->type, "bool") == 0)
            {
                value1 = *(int*)rez1->value;
            }
            if(strcmp(rez2->type, "bool") == 0)
            {
                value2 = *(int*)rez2->value;
            }
            
            if(value1 && value2)
            {
                *(int*)returnable->value = 1;
            }
            else
            {
                *(int*)returnable->value = 0;
            }
            
            
            return returnable;
        }break;
        case operatorOR: {
             printf("uuuu sunt un ||\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            
            struct info* rez2 = parseSyntaxTree(p->opr.op2);
            
            char *type = returnResult(rez1->type, rez2->type);
        
            if(strcmp(type,"?") == 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't mixt characters with numbers in operations");
            }
           
            returnable->type = (char*)malloc(strlen("bool"));
            strcpy(returnable->type, "bool");
            returnable->value = (int*)malloc(sizeof(int));
            int value1, value2;
            if(strcmp(rez1->type, "string") == 0) 
            {
                value1 = 1;
            }
            if(strcmp(rez2->type, "string") == 0) 
            {
                value2 = 1;
            }
            if(strcmp(rez1->type, "int") == 0) 
            {
                if(*(int*)rez1->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez2->type, "int") == 0) 
            {
                if(*(int*)rez2->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
               if(strcmp(rez1->type, "int") == 0) 
            {
                if(*(int*)rez1->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez2->type, "float") == 0) 
            {
                if(*(float*)rez2->type != 0)
                {
                    value1 = 1;
                }
                else{
                    value1 = 0;
                }
            }
            if(strcmp(rez1->type, "bool") == 0)
            {
                value1 = *(int*)rez1->value;
            }
            if(strcmp(rez2->type, "bool") == 0)
            {
                value2 = *(int*)rez2->value;
            }
            
            if(value1 || value2)
            {
                *(int*)returnable->value = 1;
            }
            else
            {
                *(int*)returnable->value = 0;
            }
            
            
            return returnable;
        }break;
        case operatorIF: {
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            if(*(int*)rez1->value != 0)
                parseSyntaxTree(p->opr.op2);
            return NULL;
        }break;
        case operatorWHILE: {
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            int value = *(int*)rez1->value;
            printf("poftim %d\n", value);
            while(value != 0)
            {
                printf("stop nu intra aici\n");
                parseSyntaxTree(p->opr.op2);
                rez1 = parseSyntaxTree(p->opr.op1);
                value = *(int*)rez1->value;
            }
            return NULL;
        }break;
        case operatorSTAT: {
            parseSyntaxTree(p->opr.op1);
            return parseSyntaxTree(p->opr.op2);
        }
        default:
            break;
        }
    }
    default:
        break;
    }

}





#endif