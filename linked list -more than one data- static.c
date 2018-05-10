#include <stdio.h>
#include <stdlib.h>

typedef struct mylist
{
    char name;
    int data1;
    float data2;
    struct mylist *next;
}node;

void main()
{
    node *head = (node *)malloc (sizeof (node));
    node *mid = (node *)malloc (sizeof (node));
    node *tail = (node *)malloc (sizeof (node));

    head -> name = 'A';
    head -> data1 = 8;
    head -> data2 = 6.5;

    mid -> name = 'B';
    mid -> data1 = 6;
    mid -> data2 = 4.5;

    tail -> name = 'C';
    tail -> data1 = 4;
    tail -> data2 = 7.5;

    head -> next = mid;
    mid -> next = tail;
    // notice that we have to assign NULL here
    tail -> next = NULL;

    while (head != NULL)
    {
        printf ("%c %d %.1f -> ",head -> name,head -> data1,head -> data2 );
        head = head -> next;
    }
    printf ("NULL\n");
}
