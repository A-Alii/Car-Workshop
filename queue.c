#include "queue.h"
#include<stdio.h>

void CreateQueue(QueueType *q)
{
    q->front = 0;
    q->rear = MAX-1;
    q->size = 0;
}

int QueueEmpty(QueueType q)
{
    return (q.size==0);
}

int QueueFull(QueueType q)
{
    return (q.size==MAX);
}

void Enqueue(EntryType item , QueueType *q)
{
    q->rear = (q->rear+1) % MAX ;
    q->entry[q->rear] = item;
    q->size++;
}

void Dequeue(EntryType *item , QueueType *q)
{
    *item = q->entry[q->front];
    q->front = (q->front+1) % MAX;
    q->size--;
}
