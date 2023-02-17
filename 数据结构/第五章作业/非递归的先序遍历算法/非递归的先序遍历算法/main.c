//
//  main.c
//  非递归的先序遍历算法
//
//  Created by 叶子寻 on 2020/4/28.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef char elemtype;

typedef struct node         //定义二叉树
{
    elemtype ch;
    struct node *lchild,*rchild;
}Bitree;

Bitree *CreatTree()     //二叉树的建立，广度优先输入
{
    char m;
    Bitree *S,*root;
    root=NULL;
    Bitree *Q[MAX];         //指向每个元素的指针构成的队列
    int front=1,rear=0;
    while((m=getchar())!='#')
    {
        S=NULL;
        if(m!='@')
        {
            S=(Bitree*)malloc(sizeof(Bitree));
            S->ch=m;
            S->lchild=NULL;
            S->rchild=NULL;
        }
        rear++;
        Q[rear]=S;
        if(rear==1)
        {
            root=S;
        }
        else
        {
            if(S&&Q[front])
            {
                if(rear%2==0)
                {
                    Q[front]->lchild=S;
                }
                else
                {
                    Q[front]->rchild=S;
                }
            }
            if(rear%2==1)
            {
                front++;
            }
        }
    }
    return root;
}

void preOrder(Bitree *root)//非递归的先序遍历算法
{
    Bitree *Stack[MAX];
    Bitree *s;
    int top=-1;
    if(root!=NULL)
    {
        top++;
        Stack[top]=root;
        while(top!=-1)
        {
            s=Stack[top];
            top--;
            while(s)
            {
                printf("%c ",s->ch);
                if(s->rchild!=NULL)     //若有右孩子，入栈
                {
                    top++;
                    Stack[top]=s->rchild;
                }
                s=s->lchild;
            }
        }
    }
    else
        printf("二叉树为空！\n");
}

int main()
{
    Bitree *root;
    printf("请输入按广度优先的二叉树，@表示虚结点，#表示结束：\n");
    root=CreatTree();
    printf("按非递归的先序遍历算法可以得到：\n");
    preOrder(root);
    printf("\n");
    return 0;
}

