#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createbst(struct node *root, int value);
void display (struct node *root);
void Inorder (struct node *root);
void Preorder (struct node *root);
void Postorder (struct node *root);

void main()
{
    struct node *root = NULL;
    int choice , value , n , i;
    do
    {
        printf(":::Binary Search Tree Operations:::\n\n");
        printf("1. Create BST \n2. Display \n3. Inorder \n4. Preorder \n5.Postorder \n6. Exit\n");
        printf("Enter your choice : \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    root = NULL;
                    printf("How many nodes do you want? \n ");
                    scanf("%d",&n);

                    for(i = 1; i <= n; i++)
                    {
                        printf("Enter data for node %d : ", i);
                        scanf("%d",&value);

                        root = createbst(root,value);
                    }

                    break;
            case 2:
                    display(root);
                    break;

            case 3:
                    printf("Inorder\n");
                    Inorder(root);
                    break;
            case 4:
                    printf("Preorder\n");
                    Preorder(root);
                    break;
            case 5:
                    printf("Postorder\n");
                    Postorder(root);
                    break;
            case 6:
                    exit (0);

            default:
                    printf("Wrong Selection !!! Try Again !!!\n");
                    break;
        }

    }while(choice != 6);

}

struct node *createbst(struct node *root, int value)
{
    if(root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = value;
        return root;
    }
    else
    {
        if(value < root->data )
            root->left = createbst(root->left,value);

        else if(value > root->data )
            root->right = createbst(root->right,value);

        else
            printf(" Duplicate Element !!! Not Allowed !!!\n");

        return root;
    }
}

void display(struct node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d\t",root->data);
        display(root->right);
    }
}

void Inorder(struct node *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}



