#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
    int data;
    struct mylist *link;
}node;

void main()
{
    int i;

    node *p = (node *)malloc (sizeof(node));
    node *q = (node *)malloc (sizeof(node));
    node *r = (node *)malloc (sizeof(node));
    node *s = (node *)malloc (sizeof(node));

    p ->data = 5;
    q ->data = 11;
    r ->data = 10;
    s ->data = 7;

    p ->link = q;
    q ->link = r;
    r ->link = s;
    s ->link = p;

    for (i=0;i<12;i++)
    {
        printf ("%d ",p ->data);
        p = p ->link;
    }
}
