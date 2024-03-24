#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//初始化栈
Status InitStack(LinkedStack *L){
    L->top = (Node *)malloc(sizeof(Node));
    if(!L->top)
        return FALSE;
    L->top = NULL;
    L->count = 0;
    return TRUE;
}
//栈是否为空
Status isEmptyStack(LinkedStack *L){
    if(!L->count)
        return TRUE;
    return FALSE;
}
//获取栈顶元素
Status getTop(LinkedStack *L,ElemType *e){
    if(isEmptyStack(L))
        return FALSE;
    *e = L->top->data;
    return TRUE;
}
//清空栈
Status clearStack(LinkedStack *L){
    if(isEmptyStack(L))
        return FALSE;
    Node *p;
    p = L->top;
    while(p){
         L->top = L->top->next;
         free(p);
         p = L->top;
    }
    L->count = 0;
    return TRUE;
}
//销毁栈
Status DestoryStack(LinkedStack *L){
    if(!L->top)
        return FALSE;
    clearStack(L);
    free(L->top);
    L->top = NULL;
    return TRUE;
}
//获取栈长度
int StackLength(LinkedStack *L){
    return L->count;
}
//进栈
Status push(LinkedStack *L,ElemType e){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->top;
    L->top = p;
    L->count++;
    return TRUE;
}
//出栈
Status pop(LinkedStack *L,ElemType *e){
    if(isEmptyStack(L))
        return FALSE;
    Node *p = L->top;
    *e = p->data;
    L->top = p->next;
    free(p);
    L->count--;
    return TRUE;
}
//打印栈所有元素（不出栈）
Status print(LinkedStack *L){
    if(isEmptyStack(L))
        return FALSE;
    Node *p = L->top;
    for(int i =1;p;i++,p = p->next)
        printf("栈自上而下第%d个数为%c\n",i,p->data);
    return TRUE;
}
