//
//  main.c
//  hulm编码译码
//
//  Created by 叶子寻 on 2020/4/29.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int num_of_leaves;      //符号个数
int num_of_nodes;       //节点个数

typedef struct
{
    char bits[50];  //编译器不允许用变量来设置数组长度
    int start;
    char ch;
}codetype;
codetype code[50];

typedef struct
{
    int lchild,rchild,parent;
    float weight;
    char ch;
}hufmtree;
hufmtree *root;

hufmtree * creathufmtree()
{
    int i,j,p1,p2,s1,s2;
    hufmtree * root;
    num_of_nodes=2*num_of_leaves-1;
    root=(hufmtree*)malloc(num_of_nodes*sizeof(hufmtree));
    for(i=0;i<num_of_nodes;i++)         //初始化
    {
        root[i].lchild=root[i].parent=root[i].rchild=root[i].weight=-1;
        root[i].ch='@';
    }
    
    printf("请连续输入%d个符号（无空格）：\n",num_of_leaves);
    for(i=0;i<num_of_leaves;i++)
        scanf("%c",&root[i].ch);
    getchar();
    
    printf("请依次输入每个符号的权值：\n");
    for(i=0;i<num_of_leaves;i++)    //输入前n个点的权值
        scanf("%f",&root[i].weight);
    getchar();
    
    for(i=num_of_leaves;i<num_of_nodes;i++)    //合并
    {
        p1=p2=0;
        s1=s2=1000;
        for(j=0;j<i;j++)    //从第一个节点遍历，寻找权值最小的两个节点
        {
            if(root[j].parent==-1)
            {
                if(root[j].weight<s1)
                {
                    s2=s1;
                    s1=root[j].weight;
                    p2=p1;
                    p1=j;
                }
                else if(root[j].weight<s2)
                {
                    s2=root[j].weight;
                    p2=j;
                }
            }
        }
        root[p1].parent=i;
        root[p2].parent=i;
        root[i].lchild=p1;
        root[i].rchild=p2;
        root[i].weight=root[p1].weight+root[p2].weight;
    }
    return root;
}

void hufmcode(hufmtree *root)
{
    int i,son,p;
    codetype temp;
    for(i=0;i<num_of_leaves;i++)
    {
        temp.start=num_of_leaves;
        temp.ch=root[i].ch;       //保留root[i]的符号
        son=i;
        p=root[son].parent;
        while(p!=-1)
        {
            temp.start--;
            if(root[p].lchild==son)
                temp.bits[temp.start]='0';
            else
                temp.bits[temp.start]='1';
            son=p;
            p=root[son].parent;
        }
        code[i]=temp;
    }
    printf("生成的密码表为：\n");
    for(i=0;i<num_of_leaves;i++)
    {
        printf("%c \t ",code[i].ch);
        for(int j=code[i].start;j<num_of_leaves;j++)
        {
            printf("%c",code[i].bits[j]);
        }
        printf("\n");
    }
}

int hufmdecode(hufmtree *root)
{
    int i,bit;
    i=num_of_nodes-1;       //从根节点向下遍历
    printf("请输入二进制代码，每位以空格间隔，最终输入2结束：\n");
    scanf("%d",&bit);
    while(bit!=2)
    {
        if(bit==0)
            i=root[i].lchild;
        else if(bit==1)
            i=root[i].rchild;
        else
        {
            printf("请输入0或1，或输入2结束！\n");
            return 0;
        }
        if(root[i].lchild==-1)      //找到叶子,输出符号
        {
            printf("%c",root[i].ch);
            printf("\n");
            i=num_of_nodes-1;
        }
        scanf("%d",&bit);
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    printf("请输入符号个数：");
    scanf("%d",&num_of_leaves);
    getchar();
    root=creathufmtree();
    /*
    for(int i=0;i<num_of_leaves;i++)
        printf("%c",root[i].ch);
    printf("\n");
     */
    hufmcode(root);
    hufmdecode(root);
    return 0;
}
