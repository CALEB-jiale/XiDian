//
//  main.c
//  test3
//
//  Created by Lucas on 2020/8/22.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct pnode
{
    int coef;
    int exp;
    struct pnode *next;
}polynode;

polynode *create()
{
    int coef;
    int exp;
    int nums;
    polynode *head,*s,*r;
    head=(polynode*)malloc(sizeof(polynode));
    head->coef=0;
    head->exp=-1;
    r=head;
    scanf("%d",&nums);
    int i;
    for(i=0;i<nums;i++)
    {
        scanf("%d %d",&coef,&exp);
        s=(polynode*)malloc(sizeof(polynode));
        s->coef=coef;
        s->exp=exp;
        r->next=s;
        r=s;
    }
    r->next=head;
    return head;
}

polynode *polyadd(polynode *pa,polynode *pb)
{
    polynode *p,*q,*s,*add,*t,*temp;
    float x;
    add=(polynode*)malloc(sizeof(polynode));
    p=pa->next;
    q=pb->next;
    s=pa;
    t=add;
    while((p!=pa)&&(q!=pb))
    {
        if(p->exp>q->exp)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=p->coef;
            temp->exp=p->exp;
            t->next=temp;
            t=t->next;
            p=p->next;
        }
        else if(p->exp<q->exp)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=q->coef;
            temp->exp=q->exp;
            t->next=temp;
            t=t->next;
            q=q->next;
        }
        else
        {
            x=p->coef+q->coef;
            if(x!=0)
            {
                temp=(polynode*)malloc(sizeof(polynode));
                temp->coef=x;
                temp->exp=p->exp;
                t->next=temp;
                t=t->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    if(q!=pb)
    {
        while(q!=pb)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=q->coef;
            temp->exp=q->exp;
            t->next=temp;
            q=q->next;
            t=t->next;
        }
    }
    if(p!=pa)
    {
        while(p!=pa)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=p->coef;
            temp->exp=p->exp;
            t->next=temp;
            p=p->next;
            t=t->next;
        }
    }
    t->next=add;
    return add;
}

polynode *polysub(polynode *pa,polynode *pb)
{
    polynode *p,*q,*s,*sub,*t,*temp;
    float x;
    sub=(polynode*)malloc(sizeof(polynode));
    p=pa->next;
    q=pb->next;
    s=pa;
    t=sub;
    while((p!=pa)&&(q!=pb))
    {
        if(p->exp>q->exp)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=p->coef;
            temp->exp=p->exp;
            t->next=temp;
            t=t->next;
            p=p->next;
        }
        else if(p->exp<q->exp)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=-q->coef;
            temp->exp=q->exp;
            t->next=temp;
            t=t->next;
            q=q->next;
        }
        else
        {
            x=p->coef-q->coef;
            if(x!=0)
            {
                temp=(polynode*)malloc(sizeof(polynode));
                temp->coef=x;
                temp->exp=p->exp;
                t->next=temp;
                t=t->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    if(q!=pb)
    {
        while(q!=pb)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=-q->coef;
            temp->exp=q->exp;
            t->next=temp;
            t=t->next;
            q=q->next;
        }
    }
    if(p!=pa)
    {
        while(p!=pa)
        {
            temp=(polynode*)malloc(sizeof(polynode));
            temp->coef=p->coef;
            temp->exp=p->exp;
            t->next=temp;
            t=t->next;
            p=p->next;
        }
    }
    t->next=sub;
    return sub;
}

void output(polynode * head)
{
    polynode *p;
    p=head->next;
    int count=0;
    while(p!=head)
    {
        count++;
        p=p->next;
    }
    printf("%d ",count);
    p=head->next;
    while(p!=head)
    {
        printf("%d %d ",p->coef,p->exp);
        p=p->next;
    }
    printf("\n");
}

int main() {
    polynode *ha,*hb,*hadd,*hsub;
    ha=create();
    hb=create();
    output(ha);
    output(hb);
    hadd=polyadd(ha, hb);
    hsub=polysub(ha, hb);
    output(hadd);
    output(hsub);
    return 0;
}
