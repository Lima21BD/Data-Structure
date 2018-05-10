#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int find(int dataf);
void deletenode(int position);
void displaylist();

void main()
{
    int n,dataf,position;

    printf ("Enter no of nodes: \n");
    scanf ("%d",&n);

    createlist(n);

    printf ("Data in the list:\n");
    displaylist ();

    printf ("Enter a data for position x : \n");
    scanf ("%d",&dataf);

    position = find(dataf);
    printf ("Position of the node with specific data is %d\n",position);

    deletenode(position);

    printf ("Data in the list:\n");
    displaylist ();
}

void createlist (int n)
{
    struct node *newnode, *temp1;
    int take, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf ("Enter data of node 1 : \n");
    scanf ("%d",&take);

    head -> data = take;
    head -> next = NULL;

    temp1 = head;

    for(i=2;i<n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf ("Enter data for node %d : \n",i);
        scanf ("%d",&take);

        newnode -> data = take;
        newnode -> next = NULL;

        temp1 -> next = newnode;
        temp1 = temp1 -> next;
    }
}

int find(int dataf)
{
    int index =1;
    struct node *currnode = head;

    while (currnode != NULL && currnode->data != dataf)
    {
        currnode = currnode -> next;
        index++;
    }
    if (currnode != NULL)
        return index;
    else
        return 0;
}

void deletenode(int position)
{
    int i;
    struct node *prevnode, *currnode;

    prevnode = NULL;
    currnode = head;

    for (i=2;i<=position-1;i++)
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
    struct node *temp2;

    temp2 = head;

    while (temp2!=NULL)
    {
        printf ("%d -> ",temp2 -> data);
        temp2 = temp2 -> next;
    }
    printf ("NULL\n");
}

