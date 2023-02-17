//
//  main.c
//  Eagle
//
//  Created by 叶子寻 on 2020/3/18.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

typedef struct node
{
    datatype height;
    struct node *next;
}linklist;

linklist *creatlist(int n)             //创建链表（有表头）
{
    linklist *L,*s,*p;
    datatype h;
    L=(linklist*)malloc(sizeof(linklist));
    p=L;
    int i;
    for(i=0;i<n;i++)
    {
        s=(linklist*)malloc(sizeof(linklist));
        scanf("%d",&h);
        getchar();
        s->height=h;
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
    printf("%d",p->height);
    p=p->next;
    while(p!=NULL)
    {
        printf(" %d",p->height);
        p=p->next;
    }
    printf("\n");
}

void insertlist(int h,linklist *L)      //学生插入
{
    linklist *p,*q,*s;
    p=L;
    q=p->next;
    while(q&&(q->height<h))
    {
        p=q;
        q=q->next;
    }
    s=(linklist*)malloc(sizeof(linklist));
    s->height=h;
    s->next=q;
    p->next=s;
}

int main()
{
    linklist *L;
    int n,h;
    scanf("%d %d",&n,&h);
    getchar();
    L=creatlist(n);
    insertlist(h,L);
    showlist(L);
    return 0;
}
