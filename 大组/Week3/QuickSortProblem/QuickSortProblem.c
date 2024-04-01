#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//find用来查找第find小的数
int QuickSort(int num[],int start,int end,int find){
    int base = num[start];
    int left = start;
    int right = end;
    while(right > left){
        while(num[right] >= base && right > left)
            right--;
        num[left] = num[right];
        while(num[left] <= base && right > left)
            left++;
        num[right] = num[left];
    }
    num[left] = base;
    if(left + 1 == find)
        return num[left];
    else if(left + 1 > find)
        return QuickSort(num,start,left - 1,find);
    else if(left + 1 < find)
        return QuickSort(num,left + 1,end,find);
}
int main(){
    SetConsoleOutputCP(65001);
    int num[10] = {2,5,3,7,32,4,5,6,1,10};
    int find,number;
    printf("数组为:");
    for(int i =0;i < 10;i++)
        printf("%d ",num[i]);
    printf("\n输入想寻找的第__小的数字:");
    scanf("%d",&find);
    getchar();
    number = QuickSort(num,0,9,find);
    printf("第%d小的数字为%d\n",find,number);
    system("pause");
    return 0;
}