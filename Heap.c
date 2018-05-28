#include <stdio.h>

int array[100], n;

void main()
{
    int choice, value;
    n = 0;/*Represents number of nodes in the heap*/
    while(1)
    {
        printf (":::Menu:::\n");
        printf("1. Insert \n");
        printf("2. Display \n");
        printf("3. Exit \n");

        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                    printf("Enter element for insertion : \n");
                    scanf("%d", &value);
                    insert(value , n);
                    n = n + 1;
                    break;


            case 2:
                    display();
                    break;


            case 3:
                    exit(0);

            default:
                    printf("Wrong Selection!!! Try again. \n");

            }
        }

}

display()

{
    int i;

    if (n == 0)
        printf("Heap is empty. \n");

    for (i = 0; i < n; i++)
        printf("%d  ",array[i]);

    printf("\n\n");

}


insert(int value, int n)
{
    int parentnode;

    while (n > 0)
    {
        parentnode = (n - 1) / 2;

        if (value <= array[parentnode])
        {
            array[n] = value;

        }

        array[n] = array[parentnode];

        n = parentnode;

    }
    array[0] = value;

}



