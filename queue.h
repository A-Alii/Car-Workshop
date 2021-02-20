#include "global.h"

typedef struct queue
{
    int front;
    int rear;
    int size;
    EntryType entry[MAX];
} QueueType;

void CreateQueue(QueueType *q);

int QueueEmpty(QueueType q);

int QueueFull(QueueType q);

void Enqueue(EntryType item , QueueType *q);

void Dequeue(EntryType *item , QueueType *q);
