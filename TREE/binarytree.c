/*Design a Structure having following members:
1. item (integer)
2. Self-reference pointers left and right
Write a menu-driven program to perform the following operations on a binary tree.
1. Create a tree with one node (create())
2. Set the left child of a node passed to it (setLeft())
3. Set the right child of a node passed to it (setRight())
4. Traverse the tree in preOrder and display the contents (preOrder())
5. Traverse the tree in inOrder and display the contents (inOrder())
6. Traverse the tree in postOrder and display the contents (postOrder())
Pass and return the arguments in the functions as and when required.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node*left,*right;
}node;
node*root=NULL;
void inorderTraversal(node*);
void preorderTraversal(node*);
void postorderTraversal(node*);
void create();
node* insertleft(node*);
node* insertright(node*);
void main()
{
    int choice;
     while(1)
    {
        printf("\n1.INSERT\n 2.INORDER-TRAVESRE\n 3.PREORDER-TRAVERSE\n 3.POSTORDER-TRAVERSE\n 4.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            if(root==NULL)
            {
                printf("Tree is empty!!!");
            }
            else
            {
            inorder(root);
            }
            break;
            case 4:
            return;
            break;
            default:
            printf("Invalid choice!!!");
        }
    }
}
void create()
{
    node*newnode,*temp;
    int item;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the value you want to insert:");
    scanf("%d",&item);
    newnode->info=item;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
    }
    else{
        printf("Root is already present"); 
    }
}
node*insertleft(node *root)
{
    node*parent,*newnode;
    int item;
    parent=root;
    newnode=(node*)malloc(sizeof(node*));
    printf("Enter the value you want to insert at left:");
    scanf("%d",&item);
    newnode->left=NULL;
    newnode->info=item;
    newnode->right=NULL;
    parent->left=newnode;
    parent=newnode;
}
   
