#include"sort.h"
#include"sort.c"
#include<windows.h>


void menu(){
    int datanum;//记录所有的数据数量
    char choice;
    int num[200000];
    int number1 = 0,number2 = 0;
    int *numb;//用来对读取的一维整数数组进行分段
    //记录所用时间
    double dTimeTake;
    LARGE_INTEGER fre = {0};
	LARGE_INTEGER startCount={0};
	LARGE_INTEGER endCount = {0};
    do{
        system("cls");
        printf("1.创建一次大数量数据文件\n");
        printf("2.创建多次100个数的数据文件\n");
        printf("3.对一次大数量数据进行各种排序\n");
        printf("4.对多次100个数的数据进行各种排序\n");
        printf("0.退出\n");
        printf("输入操作数:");
        scanf("%c",&choice);
        getchar();
        switch (choice)
        {
            case '0':
                break;


            case '1':
                printf("输入数据数量(10000、50000、200000):");
                scanf("%d",&number1);
                if(number1 != 10000 && number1 != 50000 && number1 != 200000){
                    printf("输入数量错误\n");
                    break;
                }
                createData(number1);
                printf("创建成功\n");
                break;


            case '2':
                printf("输入数据数量k(100个数据 * 100k个):");
                scanf("%d",&number2);
                creatmanyData(100 * 100*number2);
                printf("创建成功\n");
                break;


            case '3':
                datanum = read(num,choice);
                if(datanum == 0){
                    printf("没有数据\n");
                    break;
                }
            
                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                CountSort(num,datanum);
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("计数排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                QuickSort(num,0,datanum-1);
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("快速排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                MergeSort(num,0,datanum-1);
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("归并排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                RadixCountSort(num,datanum);
                QueryPerformanceCounter(&endCount);
                //计算时间
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("基数计数排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                InsertSort(num,datanum);
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("插入排序用时%f毫秒\n", dTimeTake * 1000);

                createSortData(num,datanum-1,choice);
                system("pause");
                break;
            
            
            
            case '4':
                datanum = read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                for(int i =0;100 * i < datanum;i++){
                    QuickSort(num,100*i,100*(i+1)-1);
                }
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("快速排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                for(int i =0;100 * i < datanum;i++){
                    numb = &(num[100*i]);            
                    CountSort(numb,100);
                }
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("计数排序用时%f毫秒\n", dTimeTake * 1000);


                read(numb,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                for(int i =0;100 * i < datanum;i++){
                    numb = &(num[100*i]);
                    InsertSort(numb,100);
                }
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("插入排序用时%f毫秒\n", dTimeTake * 1000);
                
                
                
                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                for(int i = 0;100 * i < datanum;i++){           
                    numb = &(num[100*i]);
                    RadixCountSort(numb,100);
                }
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("基数计数排序用时%f毫秒\n", dTimeTake * 1000);


                read(num,choice);
                QueryPerformanceFrequency(&fre);//获取本机cpu频率
                //开始计时
                QueryPerformanceCounter(&startCount);
                for(int i =0;100 * i < datanum;i++){
                    numb = &(num[100*i]);            
                    MergeSort(numb,0,100);
                }
                QueryPerformanceCounter(&endCount);
                //计算时间差
                dTimeTake = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)fre.QuadPart;
                printf("归并排序用时%f毫秒\n", dTimeTake * 1000);

                createSortData(num,datanum,choice);
                break;
        }
        if(choice < '0' || choice > '4')
            printf("输入错误\n");
        system("pause");
    }while(choice != '0');    
}

int main(){
    SetConsoleOutputCP(65001);
    menu();
    return 0;
}