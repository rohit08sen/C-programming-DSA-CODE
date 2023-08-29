/*1. Write a menu-driven program to perform the following operations on a Circular
Linked List.
2. Create a Circular Linked List
3. Count & print no of link in the list
4. Traverse a Circular Linked List
5. Insert a node after a specific node in the list
6. Delete a node from the list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node*start=NULL;
void create();
int list_size(struct node*);
void traverse();
void insertafternode();
void deletenode();
void main()
{
    int choice;
    while(1)
    {
        printf("\n1.CREATE \n2.LIST-SIZE \n3.TRAVERSE \n4.INSERT-AFTER-NODE \n5.DELETE-NODE \n6.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            list_size(start);
            break;
            case 3:
            traverse();
            break;
            case 4:
            insertafternode();
            break;
            case 5:
            deletenode();
            break;
            case 6:
            return;
            break;
            default:
            printf("Invalid choice!!!!");
        }
    }
}
void create()
{
    struct node*temp,*newnode;
    int item,index,total;
    if(start==NULL)
    {
        printf("Enter the no. node you want:");
        scanf("%d",&total);
        temp=(struct node*)malloc(sizeof(struct node*));
        printf("\nEnter the item you want to insert:");
        scanf("%d",&item);
        temp->info=item;
        temp->next=NULL;
        start=temp;
        temp->next=temp;
        for(index=2;index<=total;index++)
        {
            newnode=(struct node*)malloc(sizeof(struct node*));
            printf("Enter the item you want to insert:");
            scanf("%d",&item);
            newnode->info=item;
            newnode->next=start;
            temp->next=newnode;
            temp=newnode;        
        }
    }
    else
    {
        printf("\nList already present.");
    }
}
int list_size(struct node*start)
{
    struct node*temp;
    int count=0;
    if(start==NULL)
    {
        printf("\nZero node present");
    }
    else
    {
        temp=start;
        do
        {
            count++;
            temp=temp->next;
        }while(temp!=start);
    }
    printf("The no. of list present=%d",count);
    return 0;
}
void traverse()
{
    struct node*temp;
    if(start==NULL)
    {
        printf("NO NODE IS PRESENT!!!!");
    }
    else
    {
        temp=start;
        printf("The elements are:");
        do
        {
            printf("%d\t",temp->info);
            temp=temp->next;
        }while(temp!=start);
    }
}
void insertafternode()
{
    struct node*temp,*ptr,*newnode;
    int item,value;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("Enter the item you want to insert:");
    scanf( "%d",&item);
    newnode->info=item;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=newnode;
    }
    else
    {
        temp=start;
        printf("After which node you want to insert:");
        scanf("%d",&value);
        while(temp->info!=value)
        {
            ptr=temp;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletenode()
{
    struct node*temp,*ptr;
    int value;
    if(start==NULL)
    {
        printf("Node is not present!!!!");
    }
    else
    {
        temp=start;
        printf("\nAfter which value you want to delete:");
        scanf("%d",&value);
        while(temp->info!=value)
        {
            ptr=temp;
            temp=temp->next;
        }
        if(temp==start)
        {
            printf("Node not found!!!");
        }
        else
        {
            ptr->next=temp->next;
            printf("The deleted node is %d",temp->info);
        }
    }
}