//
//  main.c
//  带权路径长度
//
//  Created by 叶子寻 on 2020/4/29.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int Degree=0;

typedef struct
{
    int weight,lchild,rchild,parent,degree;
}hufmtree;
hufmtree *root;

hufmtree * creathufmtree(int n)
{
    int i,j,p1,p2,s1,s2;
    hufmtree * root;
    int m=2*n-1;
    root=(hufmtree*)malloc(m*sizeof(hufmtree));
    for(i=0;i<m;i++)//初始化
    {
        root[i].lchild=root[i].parent=root[i].rchild=root[i].weight=-1;
        root[i].degree=0;
    }
    for(i=0;i<n;i++)    //输入前n个点的权值
        scanf("%d",&root[i].weight);
    for(i=n;i<m;i++)    //合并n-1次
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

int upper(int num)
{
    if(root[num].parent==-1)
        return 0;
    else
    {
        Degree+=1;
        upper(root[num].parent);
    }
    return 0;
}

int comp_degree(int num)
{
    Degree=0;
    upper(num);
    return Degree;
}

int main(int argc, const char * argv[])
{
    int n,i,wpl=0;
    scanf("%d",&n);
    root=creathufmtree(n);
    
    for(i=0;i<n;i++)    //计算合并后每个节点的路径长
    {
        root[i].degree=comp_degree(i);
    }
    
    for(i=0;i<n;i++)
    {
        wpl+=root[i].degree*root[i].weight;
    }
    printf("%d\n",wpl);
    return 0;
}
