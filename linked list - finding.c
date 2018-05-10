#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int find(int x);
void displaylist();

void main()
{
    int n,x,m;

    printf ("Enter no of nodes: \n");
    scanf ("%d",&n);
    printf ("Enter which data do you need?");
    scanf ("%d",&x);

    createlist(n);

    printf ("Data in the list:\n");
    displaylist ();

    m = find(x);
    printf ("The node is in : %d",m);

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

int find(int x)
{
    struct node *currnode = head;
    int index =1;

    while (currnode != NULL && currnode->data != x)
    {
        currnode = currnode -> next;
        index++;
    }
    if (currnode != NULL)
        return index;
    else
        return 0;

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
