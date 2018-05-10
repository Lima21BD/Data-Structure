#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void insert (int x);
void displaylist();

int main()
{
    head = NULL;
    int n, i, x;

    printf ("How many number? : \n");
    scanf ("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf ("Enter data for node %d : \n",i);
        scanf ("%d",&x);
        insert (x);
        displaylist();
    }
}

void insert(int x)
{
    struct node *temp = (struct node *)malloc(sizeof (struct node *));

    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void displaylist()
{
    struct node *temp;

    temp = head;

    while (temp!=NULL)
    {
        printf ("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf ("NULL\n");
}

