//
//  main.c
//  StuManager
//
//  Created by 叶子寻 on 2020/3/18.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
char name[25];
int number;
char sex;
struct node *next;
}stulist;

stulist *creatlist()             //创建链表
{
    stulist *L,*p,*s;
    L=(stulist*)malloc(sizeof(stulist));
    p=L;
    int i;
    //printf("请输入学生信息，并以‘#’结束\n");
    for(i=0;i<30;i++)
    {
        s=(stulist*)malloc(sizeof(stulist));
        scanf("%s",s->name);
        if(s->name[0]=='#')
            break;
        scanf("%d %c",&s->number,&s->sex);
        getchar();
        p->next=s;
        p=p->next;
    }
    p->next=NULL;
    return L;
}

int delete(struct node *k,int num)
{
   stulist *p,*q;
    p=k->next;
    while((p!=NULL)&&(p->number!=num))
        p=p->next;
    if(p==NULL)
    return 0;
    else
    {
        q=k;
        while(q->next!=p)
            q=q->next;
        q->next=p->next;
        free(p);
    }
    return 1;
}

void showlist(stulist *L)
{
    stulist *p;
    p=L->next;
    while(p)
    {
        printf("%s %d %c\n",p->name,p->number,p->sex);
        p=p->next;
    }
}

int main()
{
    int flag,num;
    stulist *L;
    L=creatlist();
    //showlist(L);
    scanf("%d",&num);
    flag=delete(L,num);
    if(flag)
        showlist(L);
    else
        printf("No\n");
    return 0;
}
