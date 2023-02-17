//
//  main.c
//  sort bitree
//
//  Created by 叶子寻 on 2020/4/29.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define keytype int

typedef struct node         //定义二叉树
{
    keytype key;
    struct node *lchild,*rchild;
} Bitree;

Bitree *insertree(Bitree *t,Bitree *s)
{
    Bitree *f,*p;
    if(!t)
        return s;
    f=p=t;
    while(p)
    {
        f=p;
        if(s->key==p->key)
            return t;
        if(s->key<p->key)
            p=p->lchild;
        else
            p=p->rchild;
    }
    if(s->key<f->key)
        f->lchild=s;
    else
        f->rchild=s;
    return t;
}

void inorder(Bitree *root)
{
    if(root)
    {
        inorder(root->lchild);
        printf("%d ",root->key);
        inorder(root->rchild);
    }
}

Bitree *creatree(int n)
{
    Bitree *s,*t;
    int i;
    t=NULL;
    for(i=0;i<n;i++)
    {
        s=(Bitree*)malloc(sizeof(Bitree));
        scanf("%d",&s->key);
        s->lchild=s->rchild=NULL;
        t=insertree(t, s);
    }
    return t;
}

int main(int argc, const char * argv[])
{
    Bitree *root;
    int n;
    scanf("%d",&n);
    root=creatree(n);
    inorder(root);
    printf("\n");
    return 0;
}
