#include"Queue.h"

//类型选择
void yourChoose(){ 
    char choose,nothing;
    do{
        printf("1.int类(long就不写啦)\n");
        printf("2.char类\n");
        printf("3.double类\n");
        printf("输入你的选择：");
        scanf("%c",&choose);
        nothing = getchar();
        if(choose == '1'){
            type = 1;
            size = 4;
            printf("选择完成!\n");
            system("pause");
            return;
        }
        else if(choose == '2'){
            type = 2;
            size = 1;
            printf("选择完成!\n");
            system("pause");
            return;
        }
        else if(choose == '3'){
            type = 3;
            size = 8;
            printf("选择完成!\n");
            system("pause");
            return;
        }
        else
            printf("输入错误请重新选择\n");
        system("pause");
    }while(1);
}

//创建队列
Status InitQueue(Queue *Q){
    Node * s = (Node *)malloc(sizeof(Node));
    Q->front = Q->rear = s;
    Q->front->next = NULL;
    Q->length = 0;
    return TRUE;
}

//判断队列是否为空
Status isEmptyQueue(Queue *Q){
    if(Q->length == 0)
        return TRUE;
    return FALSE;
}

//获取队列头（不出队列）
Status getFront(Queue *Q,void *e){
    if(isEmptyQueue(Q))
        return FALSE;
    memcpy(e,Q->front->data,size);
    return TRUE;
}

//清空队列
Status clearQueue(Queue *Q){
    if(isEmptyQueue(Q))
        return FALSE;
    Node *p = Q->front;
    while(p != NULL){
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    Q->length = 0;
    Q->front = Q->rear = NULL;
}

//销毁队列
Status DestoryQueue(Queue *Q){
    clearQueue(Q);
    free(Q);
    Q = NULL;
    return TRUE;
}

//获取队列长度
int QueueLength(Queue *Q){
    return Q->length;
}

//进队列
Status enQueue(Queue *Q,void *e){
    Node *node = (Node *)malloc(sizeof(Node));
    void *data = malloc(size);
    node->data = data;
    memcpy(node->data,e,size);
    node->next = NULL;
    if(Q->length == 0){
        Q->rear = Q->front = node;
    }
    else{
        Q->rear->next = node;
        Q->rear = node;
    }
    Q->length++;
}

//出队列
Status deQueue(Queue *Q,void *e){
    if(isEmptyQueue(Q))
        return FALSE;
    Node *t = Q->front;
    if(Q->front == Q->rear)
        Q->front = Q->rear = NULL;
    else
        Q->front = Q->front->next;
    memcpy(e,t->data,size);
    free(t);
    Q->length--;
    return TRUE;
}

//遍历队列
Status printQueue(Queue *Q){
    if(isEmptyQueue(Q))
        return FALSE;
    Node *p = Q->front;
    int x = 1;
    printf("队列从后往前\n");
    if(type == 1){
        while(p != NULL){
            printf("第%d个数是%d\n",x++,*(int *)(p->data));
            p = p->next;
        }
    }
    else if(type == 2){
        while(p != NULL){
            printf("第%d个数是%c\n",x++,*(char *)(p->data));
            p = p->next;
        }
    }
    else if(type == 3){
        while(p != NULL){
            printf("第%d个数是%lf\n",x++,*(double *)(p->data));
            p = p->next;
        }
    }
    return TRUE;
}

//输入元素内容
void Scan(void *e){
    // e = malloc(size);
    char insert[100];
    int small = 0;
    int ok = 1;
    while(1){
        ok = 1;
        if(type == 1){
            printf("输入元素数据：(int数)\n");
            gets(insert);
            for(int i =0;insert[i];i++){
                if(insert[i] < '0' || insert[i] > '9'){
                    ok = 0;
                    break;
                }
            }
            if(ok == 1 && insert[0] != '\0'){
                int *num = malloc(100);
                *num = atoi(insert);
                memcpy(e,num,size);
                free(num);
                return;
            }
        }

        else if(type == 2 ){
            printf("输入元素数据：(char类)\n");
            gets(insert);
            memcpy(e,insert,size);
            return;
        }

        else if(type == 3){
            printf("输入元素数据：(double类)\n");
            gets(insert);
            for(int i =0;insert[i];i++){
                if(insert[i] >= '0' && insert[i] <= '9'){
                    continue;
                }
                else if(insert[i] == '.'){
                    if(small == 0)
                        small = 1;
                    else{
                        ok = 0;
                        break;
                    }
                }
                else{
                    ok = 0;
                    break;
                }
            }
            if(ok == 1 && insert[0] != '\0'){
                double *num = malloc(100);
                *num = atof(insert);
                memcpy(e,num,size);
                free(num);
                return;
            }
        }
        printf("输入有误，请重新输入噜\n");
        system("pause");
    }
}

//输出元素
void printElem(void *e){
    printf("队列Front");
    if(type == 1)
        printf("元素是%d\n",*(int *)e);
    else if(type == 2)
        printf("元素是%c\n",*(char *)e);
    else if(type == 3)
        printf("元素是%lf\n",*(double *)e);
}