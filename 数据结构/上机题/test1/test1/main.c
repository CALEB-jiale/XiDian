//
//  main.c
//  test1
//
//  Created by Lucas on 2020/8/22.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data[10000];
    int top;
}stack;

void push(stack *s,int e)
{
    s->top++;
    s->data[s->top]=e;
}

int pop(stack *s)
{
    int e;
    e=s->data[s->top];
    s->top--;
    return e;
}

void ttot(stack *root,int num)
{
    int s,y;
    s=num;
    if(s==0)
        push(root,0);
    else
    {
        while(s>0)
           {
               y=s%2;
               s=s/2;
               push(root,y);
           }
    }
}

int main()
{
    stack * root;
    root=(stack*)malloc(sizeof(stack));
    int num[3];
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    getchar();
    int i;
    for(i=0;i<3;i++)
    {
        root->top=-1;
        ttot(root,num[i]);
        while(root->top>=0)
        {
            printf("%d",pop(root));
        }
        printf(" ");
    }
    return 0;
}
