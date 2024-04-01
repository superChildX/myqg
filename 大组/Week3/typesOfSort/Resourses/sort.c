#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DATA_CSV "..\\Week3\\Data.csv"
#define MANYDATA_CSV "..\\Week3\\manyData.csv"
#define SORTDATA_CSV "..\\Week3\\sortData.csv"
#define SORTMANYDATA_CSV "..\\Week3\\sortManyData.csv"

//插入排序
void InsertSort(int num[],int size){
    int mark,find;//find为当前询问的小标，用mark标记num
    for(int i = 0;i < size - 1;i++){
        find = i + 1;
        mark = num[find];
        //询问如果find的num大于前一个数
        if(num[find] < num[i]){//是则进行循环往前
            while(mark < num[find-1] && find > 0){
                num[find] = num[find-1];
                find--;
            }
            //直到最后find下标的nun小于前一个数或者到最前面了
            num[find] = mark;
        }
    }
}


//归并排序
void merge(int num[], int start, int mid, int end){
    int result[200000];
    int i = start,j = mid + 1,k = 0;
    while(i <= mid && j <= end){
        if(num[i] < num[j]){
            result[k++] = num[i++];
        }
        else{
            result[k++] = num[j++];
        }
    }
    //哪边先完成上述循环则另外一边的数全部直接插入
    if(i == mid +1){
        while(j <= end){
            result[k++] = num[j++];
        }
    }
    else{
        while(i <= mid ){
            result[k++] = num[i++];
        }
    }
    for(i = 0,j = start;i < k;i++,j++){
        num[j] = result[i];
    }
}
void MergeSort(int num[], int start, int end){
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    //先将所有的数查分开
    MergeSort(num,start,mid);
    MergeSort(num,mid + 1,end);
    merge(num,start,mid,end);
}


//快排
void QuickSort(int num[],int start,int end){
    if(start < end){
        int base = num[start];//记start为基准
        int left = start;//左指针
        int right = end;//右指针
        while(left < right){
            //直到找到右边第一个比base小的数或者和左指针相遇
            while(left < right && num[right] >= base)
                right--;
            //找到比base小的数并进行左指针赋值
            num[left] = num[right];
            //同理
            while(left < right && num[left] <= base)
                left++;
            num[right] = num[left];
        }
        //最后将base赋给左指针数完成一次易位
        num[left] = base;
        //采用分治思想
        QuickSort(num, start, left - 1);
        QuickSort(num, left + 1, end);
    }
}

//计数排序
void CountSort(int num[],int size){
    int max = num[0],min = num[0];
    for(int i =1;i < size;i++){
        if(num[i] > max)
            max = num[i];
        if(num[i] < min)
            min = num[i];
    }
    int d = max - min + 1;
    int temp[d];
    int sort[size];
    for(int i = 0;i < d;i++)
        temp[i] = 0;
    for(int i = 0;i < size;i++)
        temp[num[i] - min]++;
    for(int i = 1;i < d;i++)
        temp[i] += temp[i-1];
    for(int i = size - 1;i >= 0;i--){
        sort[temp[num[i] - min] - 1] = num[i];
        temp[num[i] - min]--;
    }
    for(int i = 0;i < size;i++){
        num[i] = sort[i];
    }
}


//计数基数排序
void RadixSort(int num[], int size, int place){
    int i,count[10] ={0},sort[size];
    //对数字的部分分，个十百千万位
    for(i = 0;i < size;i++)
        count[(num[i] / place) % 10]++;
    for(i = 1;i < 10;i++)
        count[i] +=count[i-1];
    for(i = size;i >= 0;i--){
        sort[count[(num[i] / place) % 10] - 1] = num[i];
        count[(num[i] / place) % 10]--;
    }
    for(i = 0;i < size;i++)
        num[i] = sort[i];
}
//基数排序基于计数排序
void RadixCountSort(int num[],int size){
    int place,max = num[0];
    //获取序列最大值
    for(int i =0;i < size;i++)
        if(num[i] > max)
            max = num[i];
    for(place = 1;max / place > 0;place*=10)
        RadixSort(num,size,place);
}



//创建一次大量数据文件
void createData(int num){
    FILE *fp;
    int seed = 0;
    if((fp = fopen(DATA_CSV,"w")) == NULL){
        printf("数据文件创建失败\n");
        system("cls");
        return;
    }
    for(int i = 0,x = 0;i < num;i++){
        int number = rand();
        char n[10];
        itoa(number,n,10);
        fprintf(fp,"%s",n);
        x++;
        if(x == 20){
            srand((unsigned)time(NULL) + seed * seed);//初始化种子
            x = 0;
            fprintf(fp,"\n");
            seed++;
        }
        else{
            fprintf(fp,",");
        }
    }
    fclose(fp);
}

//创建多次100个数据的文件
void creatmanyData(int num){
    FILE *fp;
    int seed = 0;
    if((fp = fopen(MANYDATA_CSV,"w")) == NULL){
        printf("数据文件创建失败\n");
        system("cls");
        return;
    }
    for(int i = 0;i <= num;i++){
        int number = rand();
        char n[10];
        itoa(number,n,10);
        fprintf(fp,"%s",n);
        if(i % 100 == 0){
            fprintf(fp,"\n\n");
        }
        else if(i % 20 == 0){
            srand((unsigned)time(NULL) + seed * seed);//初始化种子
            fprintf(fp,"\n");
            seed++;
        }
        else{
            fprintf(fp,",");
        }
        fflush(fp);
    }
    system("pause");
}

//对文件的数据读取
int read(int num[],char choice){
    FILE *fp;
    int datanum = 0,i = 0,j = 0;
    char c,n[10];
    if(choice == '3'){
        if((fp = fopen(DATA_CSV,"r")) == NULL){
            perror("打开错误");
            system("cls");
        return 0;
        }

        //开始读取数据
        while((c = fgetc(fp)) != EOF){
            //双重循环，在读取到，或换行符时直接传值并再次读取
            while(c != ',' && c != '\n'){
                n[i++] = c;
                c = fgetc(fp);
            }
            n[i] = '\0';
            i = 0;
            num[j++] = atoi(n);
            datanum++;
        }
    }
    else if(choice == '4'){
        if((fp = fopen(MANYDATA_CSV,"r")) == NULL){
            perror("打开错误");
            system("cls");
        return 0;
        }
        while((c = fgetc(fp)) != EOF){
            //双重循环，在读取到，或换行符时直接传值并再次读取
            while(c != ',' && c != '\n'){
                n[i++] = c;
                c = fgetc(fp);
            }
            if((c = fgetc(fp)) != '\n')
                fseek(fp,-1,SEEK_CUR);
            n[i] = '\0';
            i = 0;
            num[j++] = atoi(n);
            datanum++;
        }
    }
    fclose(fp);
    return datanum;
}

//创建排序后的数据文件
void createSortData(int num[],int datanum,char choice){
    FILE *fp;
    char number[10];
    if(choice == '3'){
        fp = fopen(SORTDATA_CSV,"w");
        for(int i = 0;i < datanum;i++){
            itoa(num[i],number,10);
            fprintf(fp,"%s",number);
            if(i % 20 == 0 && i != 0)
                fprintf(fp,"\n");
            else
                fprintf(fp,",");
        }
    }
    else if(choice == '4'){
        fp = fopen(SORTMANYDATA_CSV,"w");
        for(int i = 0;i < datanum;i++){
            if(i % 100 == 0 && i != 0){
                fprintf(fp,"\n\n");
                continue;
            }
            itoa(num[i],number,10);
            fprintf(fp,"%s",number);
            if(i % 20 == 0 && i != 0)
                fprintf(fp,"\n");
            else
                fprintf(fp,",");
        }
    }
    fclose(fp);
}