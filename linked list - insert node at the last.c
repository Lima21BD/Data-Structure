#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insert(int data);
void displaylist();


int main()
{
    int n, datai;

    printf ("Enter no of nodes: \n");
    scanf ("%d",&n);

    createlist(n);

    printf ("Enter a data for insertnode : \n");
    scanf ("%d",&datai);

    printf("Data in the list : \n");
    displaylist();

    insert(datai);

    printf("Data in the list : \n");
    displaylist();

    return 0;
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

void insert (int datai)
{
    struct node *insertnode, *temp;

    insertnode = (struct node*)malloc(sizeof(struct node));
    insertnode->data = datai;
    insertnode->next = NULL;

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        if(temp == NULL)
            break;
    }
    if (temp != NULL)
    {
        temp->next = insertnode;
        printf("Data Inserted Successfully\n");
    }
    else
       printf("Unable to allocate memory.\n");
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

