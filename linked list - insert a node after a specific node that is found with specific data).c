#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int find(int dataf);
void insert(int position, int datai);
void displaylist();

int main()
{
    int n,dataf,position,datai;

    printf ("Enter no of nodes: \n");
    scanf ("%d",&n);

    createlist(n);

    printf ("Data in the list:\n");
    displaylist ();

    printf ("Enter a data for position x : \n");
    scanf ("%d",&dataf);

    position = find(dataf);
    printf ("Position of the node with specific data is %d\n",position);

    printf ("Enter a data for insertnode : \n");
    scanf ("%d",&datai);

    insert(position,datai);

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

    for(i=2;i<=n;i++)
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

int find(int data)
{
    struct node *currnode = head;
    int index =1;

    while (currnode != NULL && currnode->data != data)
    {
        currnode = currnode -> next;
        index++;
    }
    if (currnode != NULL)
        return index;
    else
        return 0;
}

void insert(int position, int datai)
{
    struct node *insertnode , *temp;
    int i;

    insertnode = (struct node *)malloc(sizeof (struct node));

    insertnode -> data = datai;
    insertnode -> next = NULL;

    temp = head;

    for (i=2;i<=position;i++)
    {
        temp = temp -> next;
        if (temp == NULL)
            break;
    }
    if (temp != NULL)
    {
        insertnode -> next = temp -> next;
        temp -> next = insertnode;
        printf ("Successfully Inserted\n");
    }
    else
        printf ("Not possible to insert\n");
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

