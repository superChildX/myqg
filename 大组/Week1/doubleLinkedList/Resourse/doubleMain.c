#include"doubleLinkedList.h"
#include"doubleLinkedList.c"
#include<windows.h>
int main(){
    SetConsoleOutputCP(65001);
    Node *head =NULL;
    int choice,x;
    Node *temp;

    do{
        printf("这里是码农链表VIP版，欢迎光临~↗\n");
        printf("1.创建空链表\n");
        printf("2.插入结点\n");
        printf("3.查找链表结点\n");
        printf("4.删除结点\n");
        printf("5.销毁链表\n");
        printf("6.链表反转VIP版（两种反转效果都一样，看看代码算了）（￣︶￣）↗　\n");
        printf("7.链表是否成环\n");
        printf("8.查找中间结点\n");
        printf("9.打印链表\n");
        printf("10.奇偶调换\n");
        printf("0.结束\n");
        printf("===================================\n");
        printf("请输入操作：");
        scanf("%d",&choice);
        switch (choice){
            case 0:
                break;
            case 1:
                head = createLinkedList();
                printf("创建完成~~\n");
                break;
            case 2:
                insertMenu(head);
                break;
            case 3:
                printf("找哪个结点呀~：");
                scanf("%d",&x);
                if(temp = findNode(head,x)){
                    int y = 0;
                    for(Node *t = head;t != temp;t = t->next)
                        y++;
                    printf("这个数据在链表的第%d个",y);
                }
                else
                    printf("链表没有这个数据呀~\n");
                break;
            case 4:
                printf("要删除哪个数据呀~~~：");
                scanf("%d",&x);
                DeleteNode(head,x);
                break;
            case 5:
                DestoryList(head);
                printf("销毁成功！\n");
                break;
            case 6:
                ReverseList(head);
                printf("反转完成~~\n");
                break;
            case 7:
                if(ifRoundList(head))
                    printf("成环啦\n");
                else
                    printf("没成环呀~\n");
                break;
            case 8:
                temp = middleNode(head);
                if(temp)
                    printf("中间数据是%d,地址是%d\n",temp->data,temp);
                break;
            case 9:
                printList(head);
                break;
            case 10:
                changestructure(head);
                break;
            default:
                printf("没有该指令哟~~");
        }
        printf("\n==============================\n\n");
        Sleep(1000);
    }while(choice != 0);
    return 0;
}

//二级菜单
void insertMenu(Node *head){
    int choice;
    do{
        system("cls");
        printf("1.头插    2.尾插\n");
        printf("3.结点前插入    4.结点后插入\n");
        printf("0.退出\n");
        printf("输入操作：");
        scanf("%d",&choice);
        switch (choice){
            case 0:
                break;
            case 1:
                headInsert(head,Scanner(1));
                break;
            case 2:
                endInsert(head,Scanner(1));
                break;
            case 3:
                insertBeforeNode(findNode(head,Scanner(0)),Scanner(1));
                break; 
            case 4:
                insertAfterNode(findNode(head,Scanner(0)),Scanner(1));
                break;
            default:
                printf("输入错误啦！！！");
            Sleep(500);
        }
    }while(choice != 0);
    printf("再按任意按键退出~~");
    getchar();
    getchar();
}