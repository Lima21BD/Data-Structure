#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deleteNode(int x);
void displaylist();

int main()
{
    int n, x, data;

    printf ("Enter number of nodes : \n");
    scanf ("%d",&n);
    printf ("Enter a position : \n");
    scanf ("%d",&x);

    createlist(n);

    deleteNode(x);

    printf ("Data in the list : \n");
    displaylist();

    return 0;
}

void createlist (int n)
{
    struct node *newnode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf ("Enter data of node 1 : \n");
    scanf ("%d",&data);

    head -> data = data;
    head -> next = NULL;

    temp = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf ("Enter data for node %d : \n",i);
        scanf ("%d",&data);

        newnode -> data = data;
        newnode -> next = NULL;

        temp -> next = newnode;
        temp = temp -> next;
    }
}

void deleteNode(int x)
{
    int i;
    struct node *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    for (i=2;i<=x;i++)
    {
        prevnode = currnode;
        currnode = currnode -> next;
        if(currnode == NULL)
            break;
    }
    if(currnode != NULL)
    {
        prevnode -> next = currnode -> next;
        free (currnode);
        printf ("Delete successful\n");
    }
    else
        printf ("Not possible to delete\n");
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

