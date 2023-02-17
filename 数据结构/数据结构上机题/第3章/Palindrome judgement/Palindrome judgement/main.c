//
//  main.c
//  Palindrome judgement
//
//  Created by 叶子寻 on 2020/4/6.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
//使用顺序栈
typedef struct node
{
    char elements[MAXSIZE];
    int Top;
} stack;
stack *S;

stack *setnull(stack *S) //初始化栈
{
    S->Top=-1;
    return S;
}

char pop(stack *S) //出栈函数
{
    char temp;
    temp=S->elements[S->Top];
    S->Top--;
    return temp;
}

stack *push(stack *S, char e) //进栈函数
{
    S->Top++;
    S->elements[S->Top]=e;
    return S;
}

int correct(char String[],long len) //对输入的字符串，判断是否为回文，需要调用pop和push函数
{
    //建立顺序栈
    S = (stack*)malloc(sizeof(stack));
    //调用setnull函数初始化栈
    S=setnull(S);
    
    int i,flag;
    long n;
    n=len/2;
    if(len%2==0)
        flag=0;
    else
        flag=1;
    
    for(i=0;i<n;i++)            //前一半入栈
    {
        push(S,String[i]);
    }
    
    n+=flag;
    while(S->Top!=-1&&S->elements[S->Top]==String[n])
    {
        pop(S);
        n++;
    }
    
    if(S->Top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    int sign; //sign为标志，sign=1是回文，sign=0不是回文
    long len;
    char str[100];

    gets(str);//输入字符串
    len=strlen(str);
    sign=correct(str,len);
    if (sign)
        printf("right\n");
    else
        printf("wrong\n");
    
    return 0;
}
