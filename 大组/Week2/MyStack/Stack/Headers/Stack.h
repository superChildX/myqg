#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#define ElemType char

typedef enum Status{
    FALSE,
    TRUE,
}Status;

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}Node;
typedef struct{
    Node *top;
    int count;
}LinkedStack;
//初始化栈
Status InitStack(LinkedStack *L);
//栈是否为空
Status isEmptyStack(LinkedStack *L);
//获取栈顶元素
Status getTop(LinkedStack *L,ElemType *e);
//清空栈
Status clearStack(LinkedStack *L);
//销毁栈
Status DestoryStack(LinkedStack *L);
//获取栈长度
int StackLength(LinkedStack *L);
//出栈
Status pop(LinkedStack *L,ElemType *e);
//进栈
Status push(LinkedStack *L,ElemType e);
//打印栈所有元素（不出栈）
Status print(LinkedStack *L);


#endif