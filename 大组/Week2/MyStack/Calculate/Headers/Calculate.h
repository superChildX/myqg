#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

#define ElemType1 char
#define ElemType2 double
//运用的是会自动扩容的栈
#define MAX_SIZE 10
#define INCREASE_SIZE 5

typedef enum Status{
    FALSE,
    TRUE,
}Status;

//字符栈
typedef struct{
    ElemType1 *top;
    ElemType1 *base;
    int size;
}strStack;
//运算数栈
typedef struct{
    ElemType2 *top;
    ElemType2 *base;
    int size;
}calStack;

//下方函数str都为字符栈的处理，cal都为运算数栈的处理
Status InitstrStack(strStack *S);
Status InitcalStack(calStack *C);

//出栈
Status pop_str(strStack *S,ElemType1 *e);
Status pop_cal(calStack *C,ElemType2 *e);

//进栈
Status push_str(strStack *S,ElemType1 e);
Status push_cal(calStack *C,ElemType2 e);

//判断栈是否为空
Status isEmpty_str(strStack *S);

//将中缀表达式换算成后缀表达式
Status infixToSuffix(ElemType1 str[],ElemType1 p[]);

//计算后缀表达式
double calculate(ElemType1 *p);

#endif