#include"Calculate.h"
#include"Calculate.c"
#include<windows.h>
int main(){
    SetConsoleOutputCP(65001);
    ElemType1 str[100];
    ElemType1 post[100];
    double num;
    while (1)
    {
        system("cls");
        printf("输入计算式子:\n");
        gets(str);
        Status truth = infixToSuffix(str,post);
        if(truth == TRUE){
            puts(post);
            num = calculate(post);
            printf("式子计算结果为%lf\n",num);
        }
        else{
            printf("计算式输入错误！\n");
            system("pause");
        }
    }
    

    return 0;
}