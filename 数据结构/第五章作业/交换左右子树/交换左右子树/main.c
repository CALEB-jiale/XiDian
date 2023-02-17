//
//  main.c
//  交换左右子树
//
//  Created by 叶子寻 on 2020/4/28.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
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

void Layer(Bitree *root)    //按广度优先遍历输出,利用队列的先进先出来实现
{
    Bitree *Q[MAX];
    Bitree *s;
    int front=0,rear=1;
    if(root)                    //二叉树不为空时
    {
        Q[rear]=root;
        while(front<rear)       //队列从1开始，front指向队头的头元素
        {
            front++;
            printf("%c ",Q[front]->ch);      //出队列
            s=Q[front];
            if(s->lchild!=NULL)             //入队列
            {
                rear++;
                Q[rear]=s->lchild;
            }
            if(s->rchild!=NULL)
            {
                rear++;
                Q[rear]=s->rchild;
            }
        }
        printf("\n");
    }
    else
        printf("二叉树为空！\n");
}

void exchange(Bitree *root)      //交换左右子树
{
    Bitree *s;
    if(root)
    {
        s=root->lchild;
        root->lchild=root->rchild;
        root->rchild=s;
        exchange(root->lchild);  //根节点的左子树交换
        exchange(root->rchild);  //根节点的右子树交换
    }
}

int main()
{
    Bitree *root;
    printf("请输入按广度优先的二叉树，@表示虚结点，#表示结束：\n");
    root=creatree();
    printf("交换之前按广度优先遍历可以得到：\n");
    Layer(root);
    printf("交换之后按广度优先遍历可以得到：\n");
    exchange(root);
    Layer(root);
    return 0;
}
