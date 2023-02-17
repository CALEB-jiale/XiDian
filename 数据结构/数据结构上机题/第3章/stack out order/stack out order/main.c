//
//  main.c
//  stack out order
//
//  Created by 叶子寻 on 2020/4/6.
//  Copyright © 2020 叶子寻. All rights reserved.
//

#include<stdio.h>
#define N (1000+10)
int n, m, k, a[N], b[N], sk[N];

int check()
{
    int top=0, *pa=a, *pae=a+n, *pb=b, *pbe=b+n;
    while (pb != pbe)
    {
        if (pa<pae&&*pb==*pa)
        {
            if (top == m) return 0;
            ++pb;
            ++pa;
        }
        else if(top&&*pb == sk[top - 1])
        {
            ++pb;
            --top;
        }
        else if(pa < pae)
        {
            if (top == m) return 0;
            sk[top++] = *pa++;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    while (k--)
    {
        for (int i=0; i<n; i++) scanf("%d", b+i);
        printf("%s\n",check()?"YES":"NO");
    }
    return 0;
}
