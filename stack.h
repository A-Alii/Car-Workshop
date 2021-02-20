#include "global.h"

typedef struct stack
{
    int top;
    EntryType entry[MAX];
} StackType;

void CreateStack(StackType *s);

int StackEmpty(StackType s);

int StackFull(StackType s);

void Push(EntryType item , StackType *s);

void Pop(EntryType *item , StackType *s);

