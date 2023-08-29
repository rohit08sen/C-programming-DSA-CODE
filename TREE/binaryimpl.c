#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*lchild,*rchild;
};
void inorder(struct node*);
void insert();
struct node*root=NULL;
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
void inorder(struct node*temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);//L
        printf("%d",temp->info);//N
        inorder(temp->rchild);//R
    }
}
void insert()
{
    struct node*temp,*ptr,*par;
    int item;
    temp=(struct node*) malloc(sizeof(struct node*));
    if(temp==NULL)
    {
        printf("Memory is not allocated:\n");
    }
    else
    {
        printf("\nEnter the value you want to insert:");
        scanf("%d",&item);
        temp->info=item;
        temp->lchild=NULL;
        temp->rchild=NULL;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            ptr=root;
            while(ptr!=NULL)
            {
                par=ptr;
                if(item<ptr->info)
                {
                    ptr=ptr->lchild;
                }
                else if(item>ptr->info)
                {
                    ptr=ptr->rchild;
                }
                else
                {
                    printf("\nDuplicate element can't be inserted:");
                    break;
                }
            }
            if(ptr==NULL)
            {
                if(item<par->info)
                {
                    par->lchild=temp;
                }
                else
                {
                    par->rchild=temp;
                }
            }
        }
    }
}