#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void colorSort(int num[],int length){
    int i = 0,j = 0,k = length - 1;
    while(i <= k){
        if(num[i] == 0)
            swap(&num[i],&num[j++]);
        if(num[i] == 2){
            swap(&num[i],&num[k--]);
            continue;//从右边移过来的数字有可能时1，需要再次往左移，所以必须continue不让i++
        }
        i++;
    }
}
int main(){
    SetConsoleOutputCP(65001);
    int num[10] = {1,0,2,2,0,1,1,0,2,1};
    printf("原数组:");
    for(int i = 0;i < 10;i++)
        printf("%d ",num[i]);
    colorSort(num,10);
    printf("\n排序后:");
    for(int i = 0;i < 10;i++)
        printf("%d ",num[i]);
    printf("\n");
    system("pause");
    return 0;
}