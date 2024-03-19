#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

typedef struct LNode{
    int data;
    struct LNode *next,*front;
}Node;

typedef enum Status{
    FALSE,
    TRUE,
}Status;

//创建链表
Node *createLinkedList();
//遍历打印链表
void printList(Node *head);
//销毁链表
void DestoryList(Node *head);
//头插
void headInsert(Node *head,int data);
//尾插
void endInsert(Node *head,int data);
//结点后插入
void insertAfterNode(Node *node,int data);
//结点前插入
void insertBeforeNode(Node *node,int data);
//删除结点
void DeleteNode(Node *head,int data);
//查找链表结点
Node *findNode(Node *head,int data);
//链表反转(非递归)
void ReverseList(Node *head);
//反转链表（递归）
void ReverseListGoReturn(Node *p,Node *q,Node *head);
//链表是否成环
Status ifRoundList(Node *head);
//中间结点
Node *middleNode(Node *head);
//结点奇偶调换
void changestructure(Node *head);
//二级菜单，在main程序里
void insertMenu(Node *head);
//输入
int Scanner(int x);
#endif