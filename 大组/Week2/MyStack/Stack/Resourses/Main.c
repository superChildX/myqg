#include"Stack.h"
#include"Stack.c"
#include<windows.h>
int main(){
    SetConsoleOutputCP(65001);
    LinkedStack *L;
    ElemType e;
    int x = 0;
    char choice,nothing;
    do{
        system("cls");
        printf("1.初始化栈\n");
        printf("2.元素入栈\n");
        printf("3.元素出栈\n");
        printf("4.获取栈顶元素\n");
        printf("5.清空栈\n");
        printf("6.销毁栈\n");
        printf("7.获取栈长度\n");
        printf("8.打印栈元素（不出栈）\n");
        printf("0.结束程序\n");
        printf("请输入选择：");
        scanf("%c",&choice);
        nothing = getchar();
        if(choice >='0' && choice <='8' && (choice != '0' && choice != '1') && x == 0){
            printf("还没初始化栈呢~快去\n");
            system("pause");
            continue;
        }
        switch (choice)
        {


        case '0':
            break;


        case '1':
            if(InitStack(L)){
                printf("初始化成功\n");
                x = 1;
            }
            else{
                printf("初始化失败咯\n");
            }
            break;


        case '2':
            printf("输入元素：");
            scanf("%c",&e);
            getchar();
            if(push(L,e))
                printf("元素入栈成功\n");
            break;


        case '3':
            if(pop(L,&e))
                printf("出栈成功\n元素是%c",e);
            else
                printf("栈里面还没有数据呀快去进行入栈操作吧\n");
            break;


        case '4':
            if(getTop(L,&e))
                printf("栈顶元素是%c\n",e);
            else
                printf("栈里面还没有数据呀快去进行入栈操作吧\n");
            break;


        case '5':
            if(clearStack(L))
                printf("清空成功~\n");
            else
                printf("呀，栈里面本来就没有元素~");
            break;


        case '6':
            if(DestoryStack(L))
                printf("销毁成功\n");
            x = 0;
            break;


        case '7':
            printf("栈的长度是%d\n",StackLength(L));
            break;


        case '8':
            if(!print(L))
                printf("栈内还没有元素呢~\n");
            break;


        default:
            printf("输入错误咯\n");
        }
        system("pause");
    }while(choice != '0');
    return 0;
}