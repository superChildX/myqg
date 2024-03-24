#include"Queue.h"
#include"Queue.c"
#include<windows.h>
int main(){
    SetConsoleOutputCP(65001);
    char choose,nothing;
    void *e;
    int x,y;//记录是否创建队列和返回选择类型时是否销毁链表
    Queue *Q ;
    while(1){
        yourChoose();
        x = 0;
        y = 0;
        do{
            system("cls");
            printf("1.创建队列\n");
            printf("2.插入元素\n");
            printf("3.删除元素\n");
            printf("4.清空队列\n");
            printf("5.销毁队列\n");
            printf("6.获取头元素\n");
            printf("7.获取队列长度\n");
            printf("8.遍历打印队列（不出队列）\n");
            printf("0.退出\n");
            scanf("%c",&choose);
            nothing = getchar();
            if((choose != '0' && choose != '1') && x == 0){
                printf("还没创建队列呢~\n");
                system("pause");
                continue;
            }
            switch (choose)
            {
            case '0':
                if(y == 1){
                    printf("还没有销毁链表呢~,搞事情也要搞干净点呀\n");
                    break;
                }
                break;


            case '1':
                if(x == 1){
                    printf("别重复创建噜，已经有一个啦，不能一心二用哟~\n");
                    break;
                }
                // ！！！这里不知道为什么在函数里面malloc给Queue就不行会非法访问所以移到外面了
                Q = (Queue *)malloc(sizeof(Queue));
                if(InitQueue(Q))
                    printf("创建成功!\n");
                x = 1;
                y = 1;
                break;


            case '2':
                e = malloc(size);
                Scan(e);
                enQueue(Q,e);
                printf("入队成功\n");
                break;


            case '3':
                if(!deQueue(Q,e))
                    printf("还没有元素呢\n");
                else{
                    if(type == 1)
                        printf("出队元素是%d\n",*(int *)e);
                    else if(type == 2)
                        printf("出队元素是%c\n",*(char *)e);
                    else if(type == 3)
                        printf("出队元素是%lf\n",*(double *)e);
                }
                break;


            case '4':
                if(clearQueue(Q))
                    printf("清空完成\n");
                else
                    printf("还没有元素呢~\n");
                break;


            case '5':
                DestoryQueue(Q);
                printf("销毁成功~\n");
                x = 0;
                y = 0;
                break;


            case '6':
                if(getFront(Q,e))
                    printElem(e);
                else
                    printf("还没有元素呢~\n");
                break;
            case '7':
                printf("队列长度是%d\n",QueueLength(Q));
                break;

            
            case '8':
                if(!printQueue(Q))
                    printf("还没有元素哦~\n");
                break;


            default:
                printf("操作输入错误噜~\n");
            }
            system("pause");
        }while(choose != '0' || y == 1);
    }
    return 0;
}