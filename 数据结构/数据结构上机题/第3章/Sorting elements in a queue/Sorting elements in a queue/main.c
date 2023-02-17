//
//  main.c
//  Sorting elements in a queue
//
//  Created by 叶子寻 on 2020/4/6.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node             //定义链表
{
    datatype data;
    struct node *next;
}linklist;

typedef struct                      //定义队列
{
    linklist *front,*rear;
}linkqueue;

int EmptyQL(linkqueue *q)                //判别队列是否为空
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

datatype *FrontQL(linkqueue *q)             //取队头节点元素
{
    datatype *temp=(datatype*)malloc(sizeof(datatype));
    if(EmptyQL(q))
    {
        printf("queue is empty");
        return NULL;
    }
    else
        *temp=q->front->next->data;
    return temp;
}

void EnqueueQL(linkqueue *q,datatype x)     //入队
{
    q->rear->next=(linklist*)malloc(sizeof(linklist));
    q->rear=q->rear->next;
    q->rear->data=x;
    q->rear->next=NULL;
}

datatype *DequeueQL(linkqueue *q)           //出队
{
    datatype * temp;
    linklist *s;
    if(EmptyQL(q))
    {
        printf("queue is empty");
        return NULL;
    }
    else
    {
        s=q->front->next;
        if(s->next==NULL)
        {
            q->front->next=NULL;
            q->rear=q->front;
        }
        else
            q->front->next=s->next;
        temp=(datatype*)malloc(sizeof(datatype));
        *temp=s->data;
        free(s);
        return temp;
    }
}

int main()
{
    linkqueue *q,*p;
    q=(linkqueue*)malloc(sizeof(linkqueue));
    p=(linkqueue*)malloc(sizeof(linkqueue));
    q->front=q->rear=(linklist*)malloc(sizeof(linklist));
    p->front=p->rear=(linklist*)malloc(sizeof(linklist));
    int n,i,j,num,temp1,temp2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        EnqueueQL(q,num);
    }
    
    for(i=0;i<n;i++)
    {
        temp1=*DequeueQL(q);
        for(j=n-i-1;j>0;j--)
        {
            temp2=*DequeueQL(q);
            if(temp1<=temp2)
                EnqueueQL(q,temp2);
            else
            {
                EnqueueQL(q,temp1);
                temp1=temp2;
            }
        }
        EnqueueQL(p,temp1);
    }
    
    temp1=*DequeueQL(p);
    printf("%d",temp1);
    for(i=0;i<n-1;i++)
    {
        temp1=*DequeueQL(p);
        printf(" %d",temp1);
    }
    printf("\n");
    
    return 0;
}
