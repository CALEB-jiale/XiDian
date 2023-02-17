//
//  main.c
//  Reverse
//
//  Created by 叶子寻 on 2020/3/18.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024
typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}linklist;

linklist *creatlist()             //创建链表（有表头）
{
    linklist *L,*s,*p;
    datatype num,n;
    L=(linklist*)malloc(sizeof(linklist));
    p=L;
    //printf("请输入链表中的元素，并以‘#’结束\n");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        s=(linklist*)malloc(sizeof(linklist));
        s->data=num;
        p->next=s;
        p=s;
    }
    p->next=NULL;
    return L;
}

void showlist(linklist *L)        //打印链表
{
    linklist *p;
    p=L->next;
    //printf("链表表中元素为：\n");
    printf("%d",p->data);
    p=p->next;
    while(p!=NULL)
    {
        printf(" %d",p->data);
        p=p->next;
    }
    printf("\n");
}

void reverselist(linklist *L)         //逆转链表
{
    linklist *p,*q,*r;
    if(L->next&&L->next->next)
    {
        p=L->next;
        q=p->next;
        p->next=NULL;
        r=p;
        while(q)
        {
            p=q;
            q=q->next;
            p->next=r;
            r=p;
        }
        L->next=r;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    linklist *L[n];
    for(int i=0;i<n;i++)
       L[i]= creatlist();
    for(int i=0;i<n;i++)
        reverselist(L[i]);
    for(int i=0;i<n;i++)
        showlist(L[i]);
    return 0;
}
