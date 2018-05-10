#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deletingNode();
void displaylist();

void main()
{
    int n;

    printf ("Enter no of nodes: \n");
    scanf ("%d",&n);

    createlist(n);

    deletingNode();

    printf ("Data in the list:\n");
    displaylist ();
}

void createlist(int n)
{
    struct node *newnode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof (struct node *));

    printf ("Enter the data of node 1 : \n");
    scanf ("%d",&data);

    head -> data= data;
    head -> next=NULL;

    temp = head;

    for (i=2;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof (struct node *));

        printf ("Enter data for newnode %d : \n",i);
        scanf ("%d",&data);

        newnode -> data= data;
        newnode -> next=NULL;

        temp -> next = newnode;
        temp = temp -> next;
    }
}

void deletingNode()
{
    struct node *currnode;

    currnode = head;
    head = head -> next;

    free (currnode);
}

void displaylist()
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf ("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf ("NULL\n");
}
