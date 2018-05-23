#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
}node;

// function to create new nodes
node *newnode(int data)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr -> info = data;
    ptr -> left = NULL;
    ptr -> right = NULL;
    return ptr;
}

// function to insert nodes in BST
node *insert(node *root,int data)
{
    if(root==NULL)
        return newnode(data);

    else
    {
        if(data<root->info)
        {
            root->left = insert(root->left,data);
            printf("%d***\n",root);
        }
        else if (data>root->info)
        {
            root->right = insert(root->right,data);
            printf("%d***\n",root);
        }
        else
            printf ("Duplicate Element!!! Not allowed\n");

    }
    printf("%d\n",root);
    return root;
}

// function for inorder traversal
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);

        printf("%d ",root->info);

        inorder(root->right);
    }
}
int main()
{

    node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("The Binary Search tree is: \n");
    inorder(root);
    return 0;
}

