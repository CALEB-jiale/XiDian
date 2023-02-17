//
//  main.c
//  parentheses matching
//
//  Created by 叶子寻 on 2020/4/6.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char datatype;

typedef struct Stack            //定义栈
{
    datatype data[100];
    int top;
}Stack;

Stack *SetNULLS(Stack *s)       //置空栈
{
    s->top=-1;
    return s;
}

int EmptyS(Stack *s)               //判断是否为空
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

Stack *PushS(Stack *s,datatype x)       //入
{
    s->top++;
    s->data[s->top]=x;
    return s;
}

datatype *popS(Stack *s)                //出
{
    datatype *temp;
    if(EmptyS(s))
    {
        printf("under flow");
        return NULL;
    }
    else
    {
        temp=(datatype*)malloc(sizeof(datatype));
        *temp=s->data[s->top];
        s->top--;
        return temp;
    }
}

datatype *GetTopS(Stack *s)             //取栈顶元素
{
    datatype *temp;
    if(EmptyS(s))
    {
        printf("stack is empty");
        return NULL;
    }
    else
    {
        temp=(datatype*)malloc(sizeof(datatype));
        *temp=s->data[s->top];
        return temp;
    }
}

int main()
{
    Stack *s;
    s=(Stack*)malloc(sizeof(Stack));
    int N,i,j;
    long len;
    i=0;
    scanf("%d",&N);
    char ch[10][100];
    
    for(i=0;i<N;i++)
    {
        scanf("%s",ch[i]);
    }
    
    for(i=0;i<N;i++)
    {
        s=SetNULLS(s);
        PushS(s,ch[i][0]);
        len=strlen(ch[i]);
        for(j=1;j<len;j++)
        {
            if(!EmptyS(s)&&(*GetTopS(s)-ch[i][j]==-1||*GetTopS(s)-ch[i][j]==-2))
                popS(s);
            else
                PushS(s,ch[i][j]);
        }
        if(EmptyS(s))
                printf("YES\n");
            else
                printf("NO\n");
    }
    return 0;
}
