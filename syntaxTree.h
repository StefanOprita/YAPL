#ifndef SYNTAXTREE_GUARD
#define SYNTAXTREE_GUARD
#include "symbolTable.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

typedef enum nodeEnum
{
    typeConstantInteger, typeConstantFloat, typeConstantString, typeConstantChar,
    typeId,
    typeOperator,
    typeFunctionCall
}nodeEnum;

typedef enum operatorEnum
{
    operatorGE, operatorLE, operatorEQ, operatorNE, operatorGT, operatorLT,
    operatorPLUS, operatorMINUS, operatorMULT, operatorDIV,
    operatorUMINUS,
    operatorASSIGN,
    operatorINSTR,
    operatorSTAT,
    operatorIF,
    operatorWHILE,
    operatorAND,
    operatorOR
}operatorEnum;

typedef struct constantIntegerType
{
    enum nodeEnum type;
    int value;
}constantIntegerType;

typedef struct constantFloatType
{
    enum nodeEnum type;
    float value;
}constantFloatType;

typedef struct constantStringType
{
    enum nodeEnum type;
    char *value;
}constantStringType;

typedef struct constantCharType
{
    enum nodeEnum type;
    char value;
}constantCharType;

typedef struct idNodeType
{
    enum nodeEnum type;
    struct symbolTable_nod * theScope;
    char * identifier;
}idNodeType;


typedef struct operatorNodeType
{
    enum nodeEnum type;
    enum operatorEnum oper;
    int numberOperators;
    struct nodeType *op1;
    struct nodeType *op2;
}operatorNodeType;

typedef struct nodeType
{
    enum nodeEnum type;
    struct constantIntegerType conInt;
    struct constantFloatType conFlt;
    struct constantStringType conStr;
    struct constantCharType conChr;
    struct operatorNodeType opr;
    struct idNodeType id;
}nodeType;



nodeType* Node_ConstantInt(int value)
{
    nodeType *p;
    //p = (struct constantIntegerType*)malloc(sizeof(constantIntegerType));
    p = (struct nodeType*)malloc(sizeof(nodeType));
    p->type = typeConstantInteger;
    p->conInt.value = value;
    printf("valoarea acestui int este : %d\n", p->conInt.value);
    return p;
}

nodeType* Node_ConstantFloat(float value)
{
    nodeType *p;
    //p = (struct constantFloatType*)malloc(sizeof(constantFloatType));
    p = (struct nodeType*)malloc(sizeof(nodeType));
    p->type = typeConstantFloat;
    p->conFlt.value = value;
    return p;
}

nodeType* Node_ConstantString(const char* value)
{
    nodeType *p;
    //p = (struct constantStringType*)malloc(sizeof(constantStringType));
    p = (struct nodeType*)malloc(sizeof(nodeType));
    p->type = typeConstantString;
    p->conStr.value = (char*)malloc(strlen(value));
    strcpy(p->conStr.value, value);
    return p;
}

nodeType* Node_ConstantChar(char value)
{
    nodeType *p;
    //p = (struct constantCharType*)malloc(sizeof(constantCharType));
    p = (struct nodeType*)malloc(sizeof(nodeType));
    p->type = typeConstantChar;
    p->conChr.value = value;
    //strcpy(p->conStr.value, value);
    return p;
}

nodeType* Node_OperatorNode(enum operatorEnum opr, int numberOperators, ...)
{
    va_list ap;
    struct nodeType *p;
    size_t size;
    int i;
    p = (nodeType*)malloc(sizeof(nodeType));
    p->type = typeOperator;
    p->opr.type = typeOperator;
    p->opr.oper = opr;
    p->opr.numberOperators = numberOperators;

    va_start(ap, numberOperators);
    for(i = 0 ; i < numberOperators; ++i)
    {
        if(i == 0)
        {
            p->opr.op1 = va_arg(ap, nodeType*);
        }
        else
        {
            p->opr.op2 = va_arg(ap, nodeType*);
        }
    }
    va_end(ap);
    return p;
}

nodeType* Node_IdNode(symbolTable_nod * scope, const char * identifier)
{
    nodeType *p;

    p = (nodeType*)malloc(sizeof(nodeType));
    p->type = typeId;
    p->id.theScope = scope;
    p->id.identifier = (char*)malloc(strlen(identifier));
    strcpy(p->id.identifier, identifier);
    return p;
}
#endif