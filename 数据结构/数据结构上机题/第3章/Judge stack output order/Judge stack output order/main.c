//
//  main.c
//  Judge stack output order
//
//  Created by 叶子寻 on 2020/4/6.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

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

datatype *GetTopS(Stack *s)                 //取栈顶元素
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
    int i,j,t,M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    Stack *s;
    s=(Stack*)malloc(sizeof(Stack));
    int nums[100];
    int example[100][100];
    
    for(i=0;i<N;i++)                //压栈数据
        scanf("%d",&nums[i]);
    
    for(i=0;i<K;i++)                //出栈数据
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&example[i][j]);
        }
    }
    
    for(i=0;i<K;i++)                //比较
    {
        t=0;
        s=SetNULLS(s);
        for(j=0;j<N;j++)
        {
            if(s->top==M-1)
                break;
            else
                PushS(s,nums[j]);
            while(!EmptyS(s)&&example[i][t]==*GetTopS(s))   //当栈不空且值相等，出栈
            {
                popS(s);
                t++;
            }
        }
        if(EmptyS(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
