#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

//插入排序
void InsertSort(int num[],int size);


//归并排序
void merge(int num[], int start, int mid, int end);
void MergeSort(int num[], int start, int end);


//快排
void QuickSort(int num[],int start,int end);


//计数排序
void CountSort(int num[],int size);


//计数基数排序
void RadixSort(int num[], int size, int place);
//基数排序基于计数排序
void RadixCountSort(int num[],int size);


//对文件的读取
int read(int num[],char choice);


//排序后文件的创造
void createSortData(int num[],int datanum,char choice);


//一次大量数据创造
void createData(int num);


//多次100个数的创造
void creatmanyData(int num);
#endif