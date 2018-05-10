#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
    char o;
    float p;
    int q;
    struct mylist *l;
}node;

void main()
{
    node *head = (node *)malloc(sizeof (node));
    node *tail = (node *)malloc(sizeof (node));

    head -> o = 'X';
    head -> p = 3.5;
    head -> q = 6;

    tail -> o = 'Y';
    tail -> p = 4.5;
    tail -> q = 7;

    tail -> p = head -> q;

    head -> l = tail;
    tail -> l = NULL;

    while (head != NULL)
    {
        printf ("%c %.1f %d -> ",head -> o,head -> p,head -> q);
        head = head -> l;
    }
    printf ("NULL\n");
}

