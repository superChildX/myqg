#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int type;
int size;

typedef enum{
    FALSE,
    TRUE,
}Status;

typedef struct node{
    void *data;
    struct node *next;
}Node;

typedef struct Queue{
    Node *front,*rear;
    int length;
}Queue;

void yourChoose();

Status InitQueue(Queue *Q);

Status isEmptyQueue(Queue *Q);

Status getFront(Queue *Q,void *e);

Status clearQueue(Queue *Q);

Status DestoryQueue(Queue *Q);

int QueueLength(Queue *Q);

Status enQueue(Queue *Q,void *e);

Status deQueue(Queue *Q,void *e);


#endif