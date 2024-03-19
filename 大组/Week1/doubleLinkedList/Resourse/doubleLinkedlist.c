#include"doubleLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

//创建链表
Node *createLinkedList(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->front = NULL;
    head->data = 0;
    return head;
}

//遍历打印链表
void printList(Node *head){
    if (head == NULL || head->next == NULL){
        printf("\n该链表还未有元素\n");
    }
    for(Node *p = head->next;p != NULL;p = p->next)
        printf("%d->",p->data);
    printf("NULL\n");
}

//销毁链表
void DestoryList(Node *head){
    Node *p;
    while(head->next){//当头结点后面结点不是NULL说明还有数据
        p = head->next;//用p取删除数据
        head->next = p->next;
        free(p);
    }
    head->data = 0;//本来是想用头结点记录结点总数的现在没用了
    printf("\n销毁成功\n");
}

//头插
void headInsert(Node *head,int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    newNode->front = head;
    if(head->next != NULL)
        head->next->front = newNode;
    head->next = newNode;
    printf("插入完成\n");
}

//尾插
void endInsert(Node *head,int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *p = head;
    newNode->data = data;
    while(p->next != NULL)
        p = p->next;
    newNode->next = NULL;
    newNode->front = p;
    p->next = newNode;
    printf("插入完成\n");
}

//结点后插入
void insertAfterNode(Node *node,int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->front = node;
    newNode->next = node->next;
    if(node->next)//原结点的后面可能是NULL
        node->next->front = newNode;
    node->next = newNode;
    printf("插入成功\n");
}

//结点前插入
void insertBeforeNode(Node *node,int data){
    if(node->front == NULL){
        printf("无法插在头结点前面\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->front = node->front;
    newNode->next = node;
    node->front->next = newNode;
    node->front = newNode;
    printf("插入成功\n");
}

//删除结点
void DeleteNode(Node *head,int data){
    Node *q = head;
    Node *p = head->next;    
    int num=0;//记录删除数据数量
    while(p != NULL){
        if(p->data == data){
            p->front->next = p->next;
            if(p->next != NULL)
                p->next->front = p->front;
            free(p);
            p = q->next;//删除结点后p要再指向q的后一个
            num++;
            continue;//删除后不能向前走一步
        }
        q = q->next;
        p = p->next;
    }
    if(num)
        printf("删除成功\n");
    else  
        printf("没有这个数呀~\n");
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

//链表反转（非递归）
void ReverseList(Node *head){
    Node *p = head->next,*q = NULL;//反转后q是p的next，第一步反转后p的next相当于NULL
    while(p != NULL){
        p->front = p->next;//反转p的指针
        p->next = q;
        q = p;//反转完成pq各走一布
        p = p->front;//相当于原链表p=p->next处理
    }
    head->next = q;//最后head指向原最后的数据
}

//反转链表（递归）
void ReverseListGoReturn(Node *p,Node *q,Node *head){
    if(q == NULL){//判断反转的后标记结点是否为NULL，是则说明反转到头了
        p->next = p->front;//p是最后一个结点
        p->front = head;
        head->next = p;
    }
    else{
        if(p->front == head){//判断是不是刚开始
            p->front = p->next;
            p->next = NULL;
        }else{
            p->next = p->front;//真的不会解释呀，我自己都是画图画出来的
            p->front = q;
        }
        ReverseListGoReturn(q,q->next,head);
    }
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
    Node *fast,*slow;
    for(fast = slow = head;fast != NULL && fast->next != NULL;fast = fast->next->next,slow = slow ->next);
    return slow;
}

//结点奇偶调换
void changestructure(Node *head){
    if(head->next == NULL ||head->next->next ==NULL){
        printf("没有或只有一个数据怎么调换呀~\n");
        return;
    }
    Node *p,*q;
    for(p = head->next,q = p->next;p != NULL && p->next != NULL; p = p->next,q = p->next){
        //先处理两个结点之间的指针
        p->next = q->next;
        q->front = p->front;
        //再处理两边的指针
        p->front->next = q;
        if(q->next != NULL)//如果q是最后一个结点就不能next->front
            q->next->front = p;
        p->front = q;
        q->next = p;
        //处理完后p再后方，q在前方
        if(p->next == NULL)
            break;
    }
    printf("调换完成\n");
}

//输入
int Scanner(int x){
    int sc;
    if(x == 1)
        printf("输入一个数字作为结点的数据吧：");
    else
        printf("输入你想插入到哪个数字附近：");
    scanf("%d",&sc);
    return sc;
}