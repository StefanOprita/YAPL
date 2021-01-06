#ifndef PARSESYNTAXTREE_GUARD
#define PARSESYNTAXTREE_GUARD
#include "syntaxTree.h"
#include "symbolTable.h"
#include "errorHandling.h"
#include "functionStack.h"

struct function_stiva_nod * bottom = NULL, *topFunctions = NULL;



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
    if(bottom == NULL)
    {
        bottom = function_stiva_createNode(NULL);
        topFunctions = bottom;
    }
    if(!p) return NULL;
    //printf("%d tipuuuul\n", p->type);
    switch (p->type)
    {
    case typeFunctionCall:
    {
        printf("apel de functie\n");
        struct info * dePus;
        dePus = (info*)malloc(sizeof(dePus));
        //printf("%s dc stack smash palng\n", p->func.id)
        dePus->type = (char*)malloc(strlen(p->func.id));
        printf("apel de functie\n");
        strcpy(dePus->type, p->func.id);
        printf("apel de functie\n");
        function_stiva_push(&topFunctions, dePus);
        
        int eVoid = 1;
        if(p->func.pushParameters != NULL){
            parseSyntaxTree(p->func.pushParameters);
            eVoid = 0;
        }
        

       
        
        //printf("uuuuuuuuuuuuuu %s\n", function_getInfo(topFunctions, p->func.id));

        char signature[1000];
        if(!eVoid)
        {
            sprintf(signature, "%s(%s)", dePus->type, function_getInfo(topFunctions, p->func.id));
        }
        else
        {
            sprintf(signature, "%s(%s)", dePus->type, "void");
        }
        
       

        struct functionInfo * funcInf = functionSearch(signature);

        if(funcInf == NULL)
        {
            handleError(NOT_DEFINED, signature);
        }

        if(funcInf->momentulDefinirii > p->func.momentulApelarii)
        {
            handleError(NOT_DEFINED, signature);
        }

        int index = 0;
    

        while(strcmp(topFunctions->info->type, dePus->type) != 0)
        {
           
            
            //funcInf->functionStuff->cont.cont[index].value = (int*)malloc(sizeof(int));
            //funcInf->functionStuff->cont.cont[index].value = topFunctions->info->value;    
            if(strcmp(topFunctions->info->type, "int") == 0)
            {
                funcInf->functionStuff->cont.cont[index].value = (int*)malloc(sizeof(int));
                *(int*)funcInf->functionStuff->cont.cont[index].value = *(int*)topFunctions->info->value;
            }
            if(strcmp(topFunctions->info->type, "float") == 0)
            {
                funcInf->functionStuff->cont.cont[index].value = (char*)malloc(sizeof(float));
                *(float*)funcInf->functionStuff->cont.cont[index].value = *(float*)topFunctions->info->value;
            }
            if(strcmp(topFunctions->info->type, "string") == 0)
            {
                funcInf->functionStuff->cont.cont[index].value = (char*)malloc(strlen((char*)topFunctions->info->value));
                strcpy((char*)funcInf->functionStuff->cont.cont[index].value, (char*)topFunctions->info->value);
            }
            if(strcmp(topFunctions->info->type, "char") == 0)
            {
                funcInf->functionStuff->cont.cont[index].value = (char*)malloc(sizeof(char));
                *(char*)funcInf->functionStuff->cont.cont[index].value = *(char*)topFunctions->info->value;
            }
            if(strcmp(topFunctions->info->type, "bool") == 0)
            {
                funcInf->functionStuff->cont.cont[index].value = (int*)malloc(sizeof(int));
                *(int*)funcInf->functionStuff->cont.cont[index].value = *(int*)topFunctions->info->value;
            }
            if(strstr(topFunctions->info->type, "[") != NULL)
            {
                funcInf->functionStuff->cont.cont[index].value = topFunctions->info->value; 
            }
            function_stiva_pop(&topFunctions);
            index++;
        }
        function_stiva_pop(&topFunctions);
        
        parseSyntaxTree(funcInf->body);

        index = 0;
        int gasit = 0 ;
        while(strcmp(funcInf->functionStuff->cont.cont[index].id, "return") != 0)
        {
            int gasit = 1;
            index++;
        }
        struct info * deTrimis = (info*)malloc(sizeof(info));
        deTrimis->type = (char*)malloc(strlen(funcInf->functionStuff->cont.cont[index].type));
        strcpy(deTrimis->type, funcInf->functionStuff->cont.cont[index].type);
        if((strcmp(deTrimis->type, "int") == 0))
        {
            
            deTrimis->value = (int*)malloc(sizeof(int));
            *(int*)deTrimis->value = *(int*)funcInf->functionStuff->cont.cont[index].value;
        }
        if((strcmp(deTrimis->type, "float") == 0))
        {
            deTrimis->value = (float*)malloc(sizeof(float));
            *(float*)deTrimis->value = *(float*)funcInf->functionStuff->cont.cont[index].value;
        }
        if((strcmp(deTrimis->type, "string") == 0))
        {
            deTrimis->value = (char*)malloc(strlen((char*)funcInf->functionStuff->cont.cont[index].value));
            //*(float*)deTrimis->value = *(float*)funcInf->functionStuff->cont.cont[index].value;
            strcpy((char*)deTrimis->value, (char*)funcInf->functionStuff->cont.cont[index].value);
        }
        if(strcmp(deTrimis->type, "bool") == 0)
        {
            deTrimis->value = (int*)malloc(sizeof(int));
            *(int*)deTrimis->value = *(int*)funcInf->functionStuff->cont.cont[index].value;
        }
        if((strcmp(deTrimis->type, "char") == 0))
        {
            deTrimis->value = (char*)malloc(sizeof(char));
            *(char*)deTrimis->value = *(char*)funcInf->functionStuff->cont.cont[index].value;
        }

        
        return deTrimis;
    }break;
    case typeId :
    {
        //printf("sunt un o variabila uuu\n");
        struct info * returnable = NULL;
        printf("ulalal o variabila %s unde e scopul ei? %s\n", p->id.identifier ,p->id.theScope->name);
        symbolTable_NeedPointer_LookUpThisScope(p->id.theScope, p->id.identifier, &returnable);
        return returnable;
    }break;
    case typeConstantInteger: {
            printf("sunt un integer uuu\n");
            
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

            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
            
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

            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }        


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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            printf("sunt un := uu\n");
            fflush(stdout);
            if(p->opr.op1 == NULL)
            {
                struct info* result = parseSyntaxTree(p->opr.op2);
                function_stiva_push(&topFunctions, result);
                return NULL;
            }
            struct info* var = parseSyntaxTree(p->opr.op1);
            struct info* result = parseSyntaxTree(p->opr.op2);
            if(strcmp(var->type, result->type) != 0)
            {
                char eroare[1000];
                sprintf(eroare, "Can't assign %s to %s!\n", result->type, var->type);
                handleError(JUST_SAY_WHAT_I_SAY, eroare);
            }
            if(var->isConstantValue == 1 && var->value != NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't re-assign value to constant variable!\n");
            }
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
                //var->value = (float*)malloc(sizeof(float));
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
                //var->value = (int*)malloc(sizeof(int));
                *((int*)var->value) = value;
                
            }

            if(strcmp(var->type, "bool")  == 0)
            {
                printf("aici\n");
                if(var->value == NULL)
                {
                    var->value = (int*)malloc(sizeof(int));
                }
                *((int*)var->value) = *(int*)result->value;
            }
            
            return var;
        }break;
        case operatorUMINUS: {
            printf("uuuu sunt Uminus\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            if(rez1->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
            
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
            
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
            if(rez1->value == NULL || rez2->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
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
        case operatorNOT: {
             printf("uuuu sunt un !\n");
            fflush(stdout);
            struct info* returnable;
            returnable = (info*)malloc(sizeof(info));
            struct info* rez1 = parseSyntaxTree(p->opr.op1);
            if(rez1->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
            char *type = returnResult(rez1->type, "bool");
        
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
            if(strcmp(rez1->type, "bool") == 0)
            {
                value1 = *(int*)rez1->value;
            }
            
            if(value1)
            {
                *(int*)returnable->value = 0;
            }
            else
            {
                *(int*)returnable->value = 1;
            }
            
            
            return returnable;
        }
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
        case operatorACCESARRAY:{
            printf("accesez un array???\n");
            struct info * theArray = parseSyntaxTree(p->opr.op1);
            struct info * index = parseSyntaxTree(p->opr.op2);
            if(strcmp(index->type, "int") != 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "The index of an array must be an int!\n");
            }
            if(index->value == NULL)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Can't use unitialized variables in operations!\n");
            }
            if(theArray->isArray != 1)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Not an array that you can acces\n");
            }
            int indexValue = *(int*)index->value;
            if(indexValue < 0 || indexValue >= theArray->sizeOfArray)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Out of bounds array acces!\n");
            }
            return ((info**)theArray->value)[indexValue];
        }break; 
        case operatorSTAT: {
            parseSyntaxTree(p->opr.op1);
            return parseSyntaxTree(p->opr.op2);
        }
        case operatorEVAL:
        {
            
            struct info * rez = parseSyntaxTree(p->opr.op1);
            
            if(strcmp(rez->type, "int") != 0)
            {
                handleError(JUST_SAY_WHAT_I_SAY, "Eval accepts only ints!");
            }
            char dePusInStiva[100];
            sprintf(dePusInStiva, "Eval: %d\n", *(int*)rez->value);
            stiva_push(&EvalStack, dePusInStiva);
        }break;
        default:
            break;
        }
    }
    default:
        break;
    }

}





#endif