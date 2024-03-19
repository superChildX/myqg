#include"LinkedList.h"
#include<stdio.h>
#include<stdlib.h>

//创建链表
Node *createLinkedList(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
    return head;
}

//遍历打印链表
void printList(Node *head){
    if (head == NULL || head->next == NULL){
        printf("该链表还未有元素或未创建");
        return;
    }
    for(Node *p = head->next;p != NULL;p = p->next)
        printf("%d->",p->data);
    printf("NULL\n");
}

//销毁链表
void DestoryList(Node *head){
    if (head == NULL ){
        printf("该链表还未创建");
        return;
    }
    Node *p;
    while(head->next){
        p = head->next;
        head->next = p->next;
        free(p);
    }
    head->data = 0;
    printf("\n销毁成功");
}

//插入结点
void headInsertToList(Node *head,int data){
    if (head == NULL){
        printf("该链表还未有元素或未创建");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    printf("插入完成");
}

//删除结点
void DeleteNode(Node *head,int data){
    if (head == NULL || head->next == NULL){
        printf("链表还未有元素或未创建");
        return;
    }
    Node *p,*q = head;
    for(p = head->next;p != NULL && q != NULL;q = q->next,p = p->next){
        if(p->data == data){
            q->next = p->next;
            free(p);
            continue;
        }
    }
    printf("删除完成~\n");
}

//查找链表结点
Node *findNode(Node *head,int data){
    Node *p;
    for(p = head->next;p != NULL;p = p->next){
        if(p->data == data){
            return p;
        }
    }
    return NULL;
}

//链表反转
void ReverseList(Node *head){
    Node *pre,*cur,*temp;
    for(pre = NULL,cur = head->next;cur != NULL;){
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    head->next = pre;
}

//链表反转（递归）
Node *ReverseListGoReturn(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node *p =ReverseListGoReturn(head->next);
    head->next->next = head;
    head->next =NULL;
    return p;
}

//链表是否成环
Status ifRoundList(Node *head){
    Node *fast,*slow;
    for(fast = slow = head;fast != NULL && fast->next != NULL;fast = fast->next->next,slow = slow ->next)
        if(fast == slow && fast !=head)
            return TRUE;
    return FALSE;
}

//中间结点
Node *middleNode(Node *head){
    if (head == NULL || head->next == NULL){
        printf("\n该链表还未有元素或未创建");
        return NULL;
    }
    Node *fast,*slow;
    for(fast = slow = head;fast != NULL && fast->next != NULL;fast = fast->next->next,slow = slow ->next);
    return slow;
}

//奇偶调换
void changestructure(Node *head){
    if(head->next == NULL || head->next->next == NULL){
        printf("没有或者只有一个数调换不了呀！\n");
        return;
    }
    Node *p=head->next,*q=p->next,*x=head;
    while(p->next != NULL){
        p->next = q->next;
        q->next = p;
        x->next = q;
        x = p;
        p = p->next;
        if(p == NULL)
            break;
        q = p->next;
    }
    printf("调换完成\n");
}