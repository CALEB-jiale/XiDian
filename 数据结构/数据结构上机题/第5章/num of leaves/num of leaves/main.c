//
//  main.c
//  num of leaves
//
//  Created by 叶子寻 on 2020/4/29.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int num_of_leaves=0;
char leaves[MAX];

typedef struct node         //定义二叉树
{
    char ch;
    struct node *lchild,*rchild;
} Bitree;

Bitree *creatree()          //二叉树的建立，广度优先输入
{
    char m;
    Bitree *Q[MAX];
    Bitree *s,*root;
    root=NULL;
    int front=1,rear=0;
    while((m=getchar())!='#')
    {
        s=NULL;
        if(m!='@')
        {
            s=(Bitree*)malloc(sizeof(Bitree));
            s->ch=m;
            s->lchild=NULL;
            s->rchild=NULL;
        }
        rear++;
        Q[rear]=s;
        if(rear==1)
            root=s;
        else
        {
            if(Q[front]&&s)
            {
                if(rear%2==0)
                    Q[front]->lchild=s;
                else
                    Q[front]->rchild=s;
            }
            if(rear%2==1)
                front++;
        }
    }
    return root;
}

void find_leaves(Bitree *root)
{
    Bitree *Stack[MAX];
    Bitree *s;
    int top=-1;
    if(root)
    {
        top++;
        Stack[top]=root;
        while(top!=-1)
        {
            s=Stack[top];
            top--;
            while(s)
            {
                if(s->rchild)     //若有右孩子，入栈
                {
                    top++;
                    Stack[top]=s->rchild;
                }
                else if(!s->lchild)
                {
                    leaves[num_of_leaves]=s->ch;
                    num_of_leaves++;
                    break;
                }
                s=s->lchild;
            }
        }
    }
}

int main()
{
    Bitree *root;
    int i;
    root=creatree();
    find_leaves(root);
    printf("%c",leaves[0]);
    for(i=1;i<num_of_leaves;i++)
    {
        printf(" %c",leaves[i]);
    }
    printf("\n");
    printf("%d\n",num_of_leaves);
    return 0;
}
