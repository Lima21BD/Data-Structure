#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int traverse();
void displaylist();

int main()
{
    int n, data;

    printf ("Enter number of nodes : \n");
    scanf ("%d",&n);

    createlist(n);

    printf ("Data in the list : \n");
    displaylist();

    int x = traverse();
    printf ("Number of nodes: %d\n",x);

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

int traverse()
{
    int p = 0;
    struct node *currnode;

    currnode = head;

    while (currnode != NULL)
    {
        currnode = currnode -> next;
        p++;
    }

    return p;
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



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int traverse();
void displaylist();

int main()
{
    int n;

    printf ("Enter number of nodes : \n");
    scanf ("%d",&n);

    createlist(n);

    printf ("Data in the list : \n");
    displaylist();

    int x = traverse();
    printf ("Number of nodes: %d\n",x);

    return 0;
}

void createlist (int n)
{
    struct node *newnode, *temp1;
    int data1, i;

    head = (struct node *)malloc(sizeof(struct node));

    printf ("Enter data of node 1 : \n");
    scanf ("%d",&data1);

    head -> data = data1;
    head -> next = NULL;

    temp1 = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf ("Enter data for node %d : \n",i);
        scanf ("%d",&data1);

        newnode -> data = data1;
        newnode -> next = NULL;

        temp1 -> next = newnode;
        temp1 = temp1 -> next;
    }
}

int traverse()
{
    int p = 0;
    struct node *currnode;

    currnode = head;

    while (currnode != NULL)
    {
        currnode = currnode -> next;
        p++;
    }

    return p;
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
