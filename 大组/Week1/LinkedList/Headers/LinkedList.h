#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct LNode{
    int data;
    struct LNode *next;
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
//插入结点
void headInsertToList(Node *head,int data);
//删除结点
void DeleteNode(Node *head,int data);
//查找链表结点
Node *findNode(Node *head,int data);
//链表反转
void ReverseList(Node *head);
//链表反转（递归）
Node *ReverseListGoReturn(Node *head);
//链表是否成环
Status ifRoundList(Node *head);
//中间结点
Node *middleNode(Node *head);
//奇偶调换
void changestructure(Node *head);










#endif