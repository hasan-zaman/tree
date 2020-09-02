#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;

    printf("Enter Data for NEW NODE. If you don't want any new NODE then Enter 999\n");
    scanf("%d", &x);

    if(x==999)
    {
        return 0;
    }
    else{

        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = x;
        printf("Enter left child of %d", x);
        newnode->left = create();

        printf("Enter right child of %d", x);
        newnode->right = create();

        return newnode;
    }

};

void preorder(struct node *root)
{
    if(root==0){
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

void main()
{
    struct node *root;
    root=0;
    root = create();

    printf("Root of the tree is %d\n", root->data);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\n Postorder Traversal: ");
    postorder(root);
}
