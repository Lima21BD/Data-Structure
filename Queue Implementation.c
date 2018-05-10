#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
   int data;
   struct node *next;
}*front = NULL,*rear = NULL;

void enqueue(int value);
void dequeue();
void display();

void main()
{
   int choice, value;
   printf(":: Queue Implementation using Linked List ::\n");
   while(1)
   {
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1: printf("Enter the value to be insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
        case 4: exit(0);
        default: printf("Wrong selection!!! Please try again!!!\n");
      }
   }
}
void enqueue(int value)
{
   struct node *newnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode -> data = value;
   newnode -> next = NULL;
   if(front == NULL)
      front = rear = newnode;
   else
    {
      rear -> next = newnode;
      rear = newnode;
    }
   printf("Insertion Successful!!!\n");
}
void dequeue()
{
   if(front == NULL)
      printf("Queue is Empty!!!\n");
   else
   {
      struct node *temp = front;
      front = front -> next;
      printf("Deleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("Queue is Empty!!!\n");
   else
    {
      struct node *temp = front;

      while(temp->next != NULL)
      {
        printf("%d -> ",temp->data);
        temp = temp -> next;
      }
      printf("NULL\n");
   }
}
