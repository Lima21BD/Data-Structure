#include<stdio.h>
#include<conio.h>

char b[20];
char ajMat[20][20];
char que[20];
char arr[20];

int front=0 , rear=0 , n;
int p=0;

int bfs(int i);
void display();


void main()
{
    char v;
    int i, j;

    printf("Enter the number of nodes in a graph : \n");
    scanf("%d",&n);
    printf("Enter the value of nodes : \n");

    for(i=0; i<n; i++)
        scanf("%s",&b[i]);

    printf("Enter the value in adjancency matrix in from of 'y' or 'n'\n");
    printf("If there exits an edge between two vertices then 'y' otherwise 'n'\n");

    for(i=0; i<n; i++)
        printf(" %c ",b[i]);

    for(i=0; i<n; i++)
    {
        printf("\n%c ",b[i]);

        for(j=0; j<n; j++)
        {
             printf("%c ",v = getch());

             ajMat[i][j] = v;
        }

        printf("\n\n");
    }

    for(i=0;i<n;i++)
        bfs(i);

    display();

}

void display()
{
    int i;

    printf("BFS of Graph : ");

    for(i=0; i<n; i++)
       printf("%c ",arr[i]);
}

void insert(char value)
{
    que[front] = value;
    front++;
}

char del()
{
    rear = rear+1;
    return que[rear-1];
}

int unvisit(char value)
{
    int i;

    for(i=0; i<front; i++)
    {
         if(value == que[i])
         return 0;
    }

    return 1;
}

int bfs(int i)
{
     char m;
     int j;

     if(front == 0)
         insert(b[i]);

     for(j=0; j<n; j++)
     {
         if(ajMat[i][j]=='y')
         {
              if(unvisit(b[j]))
              {
                   insert(b[j]);
              }
         }
     }
     m = del();
     arr[p] = m;
     p++;

     return 0;
}
