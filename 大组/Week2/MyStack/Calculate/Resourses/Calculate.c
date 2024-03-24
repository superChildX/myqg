#include"Calculate.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//下方函数str都为字符栈的处理，cal都为运算数栈的处理
//初始化栈
Status InitstrStack(strStack *S){
    S->base = (ElemType1 *)malloc(MAX_SIZE * sizeof(ElemType1));
    if(!S->base)
        return FALSE;
    S->top = S->base;
    S->size = MAX_SIZE;
    return TRUE;
}

Status InitcalStack(calStack *C){
    C->base = (ElemType2 *)malloc(MAX_SIZE * sizeof(ElemType2));
    if(!C->base)
        return FALSE;
    C->top = C->base;
    C->size = MAX_SIZE;
    return TRUE;
}
//出栈
Status pop_str(strStack *S,ElemType1 *e){
    if(S->top == S->base)
        return FALSE;
    *e = *(--S->top);
    return TRUE;
}

Status pop_cal(calStack *C,ElemType2 *e){
    if(C->top == C->base)
        return FALSE;
    *e = *(--C->top);
    return TRUE;
}

//进栈
Status push_str(strStack *S,ElemType1 e){
    if(S->top - S->base >= S->size){
        S->base = (ElemType1 *)realloc(S->base,(S->size + INCREASE_SIZE) * sizeof(ElemType1));
        if(!S->base)
            return FALSE;
        S->top = S->base + S->size;
        S->size = S->size + INCREASE_SIZE;
    }
    *S->top = e;
    S->top++;
    return TRUE;
}

Status push_cal(calStack *C,ElemType2 e){
    if(C->top - C->base >= C->size){
        C->base = (ElemType2 *)realloc(C->base,(C->size + INCREASE_SIZE) * sizeof(ElemType2));
        if(!C->base)
            return FALSE;
        C->top = C->base + C->size;
        C->size = C->size +INCREASE_SIZE;
    }
    *C->top = e;
    C->top++;
    return TRUE;
}

//判断栈是否为空
Status isEmpty_str(strStack *S){
    if(S->top == S->base)
        return TRUE;
    return FALSE;
}

Status isEmpty_cal(calStack *C){
    if(C->top == C->base)
        return TRUE;
    return FALSE;
}

Status infixToSuffix(ElemType1 str[],ElemType1 p[]){
    strStack s;
    InitstrStack(&s);
    ElemType1 e;
    int right = 0,left = 0;//括号数量
    int i = 0,j = 0,k = 0;//k  0--刚开始  1--数字  2--左括号  3--右符号  4--运算符
    
    for(i = 0;i < strlen(str);i++){//对计算式进行遍历
        if(str[i] == '('){
            if(k == 1 || k == 3)//如果左括号前方为数字或者右括号则输入错误
                return FALSE;

            push_str(&s,str[i]);
            left++;
            k = 2;
        }
        else if(str[i] == ')'){

            if(k == 0 || k == 2 || k == 4)//如果右括号前方为左括号或运算符，或者刚开始就是右括号则输入错误
                return FALSE;

            while(*(s.top-1) != '('){
                pop_str(&s,&e);
                p[j++] = e;
                p[j++] = ' ';
            }
            right++;
            
            k = 3;
        }
        else if(str[i] == '+' || str[i] == '-'){
            if(k == 0 || k == 2 || k == 4)//如果运算符在刚开始，或者前方为左括号或运算符则输入错误
                return FALSE;

            while(!isEmpty_str(&s) && *(s.top-1) != '('){
                pop_str(&s,&e);
                p[j++] = e;
                p[j++] = ' ';
            }
            push_str(&s,str[i]);
            
            k = 4;
        }
        else if(str[i] == '*' || str[i] == '/'){
            if(k == 0 || k == 2 || k == 4)//如果运算符在刚开始，或者前方为左括号或运算符则输入错误
                return FALSE;

            push_str(&s,str[i]);
           
            k = 4;
        }
        else if((str[i] >= '0' && str[i] <= '9') || str[i] =='.'){
            if(k == 3)//数字前方不能是右括号
                return FALSE;

            while((str[i] >= '0' && str[i] <= '9') || str[i] =='.'){
                p[j++] = str[i++];
            }
            p[j++] = ' ';
            i--;//回退一个位置，因为最外层for循环会再加一次
            
            k = 1;
        }
        else{
            return FALSE;
        }
    }
    if(k == 0)//如果没有输入则输入错误
        return FALSE;

    if(left != right)//如果左右括号数量不同则输入错误
        return FALSE;

    while(!isEmpty_str(&s)){
        pop_str(&s,&e);
        if(e != '('){
            p[j++] = e;
            p[j++] = ' ';
        }
    }
    p[--j] = '\0';
    return TRUE;
}

double calculate(ElemType1 *p){
    double num =0;
    calStack c;
    InitcalStack(&c);
    ElemType2 e,x,y;
    char singlenum[100];
    int i;
    for(i = 0;i < strlen(p);i++){
        int j =0;
        if((p[i] >= '0' && p[i] <='9') || p[i] == '.'){
            while((p[i] >= '0' && p[i] <='9') || p[i] == '.'){
                singlenum[j++] = p[i++];
            }
            singlenum[j] = '\0';
            i--;
            e = atof(singlenum);
            push_cal(&c,e);
        }
        else if(p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/'){
            switch (p[i]){
                case '+':
                    pop_cal(&c,&x);
                    pop_cal(&c,&y);
                    push_cal(&c,y+x);
                    break;
                case '-':
                    pop_cal(&c,&x);
                    pop_cal(&c,&y);
                    push_cal(&c,y-x);
                    break;
                case '*':
                    pop_cal(&c,&x);
                    pop_cal(&c,&y);
                    push_cal(&c,y*x);
                    break;
                case '/':
                    pop_cal(&c,&x);
                    pop_cal(&c,&y);
                    push_cal(&c,y/x);
                    break;
            }
        }
    }
    pop_cal(&c,&e);
    return e;
}









