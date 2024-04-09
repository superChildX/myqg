#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ElemType int

typedef enum {
    FALSE,
    TRUE,
}Status;
typedef struct Node{
    ElemType value;
    struct Node *left,*right,*parent;
}Node,*BinaryTree;


void visit(ElemType e);
BinaryTree init(BinaryTree tree);
Node *insert(BinaryTree tree, ElemType e);
BinaryTree deleteNode(BinaryTree tree, ElemType e);
Node *search(BinaryTree tree, ElemType e);
Status preorder(BinaryTree tree);
Status inorder(BinaryTree tree);
Status postorder(BinaryTree tree);
void level(BinaryTree tree,int leve);
Status levelorder(BinaryTree tree);
int getHeight(BinaryTree tree);
int Scan();



typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}sNode;
typedef struct{
    sNode *top;
    int count;
}LinkedStack;
//初始化栈
Status InitStack(LinkedStack *L);
//栈是否为空
Status isEmptyStack(LinkedStack *L);
Status getTop(LinkedStack *L,ElemType *e);
//出栈
Status pop(LinkedStack *L,ElemType *e);
//进栈
Status push(LinkedStack *L,ElemType e);



typedef struct node{
    ElemType data;
    struct node *next;
}qNode;

typedef struct Queue{
    qNode *front,*rear;
    int length;
}Queue;

Status InitQueue(Queue *Q);

Status isEmptyQueue(Queue *Q);

int QueueLength(Queue *Q);

Status enQueue(Queue *Q,ElemType *e);

Status deQueue(Queue *Q,ElemType *e);
#endif