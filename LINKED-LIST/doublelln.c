#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* first,*next;
};
struct node*start=NULL;
void create();
void traverse();
void insertafternode();
void deletenode();
void main() 
{
	int choice;
	while(1){
		printf("\nMENU \n1.CREATE \n2.TRAVERSE  \n3.INSERT-AFTER-NODE \n4.DELETE-NODE \n5.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			create();
			break;
			case 2:
			traverse();
			break;
			case 3:
			insertafternode();
			break;
			case 4:
			deletenode();
			break;
			case 5:
			return;
			break;
			default:
			printf("Invalid choice!!!");
		}
	}
}
void create()
{
    int i,n,item;
    struct node*temp,*newnode;
    if(start==NULL)
    {
        printf("Enter the no. of nodes u want:");
        scanf("%d",&n);
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter value u want to insert:");
        scanf("%d",&item);
        temp->info=item;
        temp->first=NULL;
        temp->next=NULL;
        start=temp;
        for(i=2;i<=n;i++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter value u want to insert:");
            scanf("%d",&item);
            newnode->info=item;
            newnode->first=NULL;
            newnode->next=NULL;
            temp->next=newnode;
            newnode->first=temp;
            temp=newnode;
        }
    }
    else
    {
        printf("List is present");
    }
}
void traverse()
{
    struct node*ptr,*temp;
    if(start==NULL)
    {
        printf("No node is present!!!");
    }
    else
    {
        temp=start;
        printf("The values in the list are:\n");
        while(temp!=NULL)
        {
            ptr=temp;
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        printf("\n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->first;
        }
    }
}
void insertafternode()
{
    struct node*newnode,*temp,*ptr;
    int item,value;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value you want to insert:");
    scanf("%d",&item);
    newnode->first=NULL;
    newnode->info=item;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        
        printf("After which node you want to insert:");
		scanf("%d",&value);
		temp=start;
		while(temp->info!=value){
			temp=temp->next;
		}
		if(temp==NULL){
			printf("Value is not present!!!\n");
		}
        else
        {
            ptr=temp->next;
            newnode->first=temp;
            newnode->next=ptr;
            temp->next=newnode;
            ptr->first=newnode;
        }
    }
}

void deletenode()
{
    struct node*temp,*ptr,*temp1;
    int value;
    if(start==NULL)
    {
        printf("Node not present!!!");
    }
    else
    {
        temp=start;
        printf("Enter the value you want to delete:");
        scanf("%d",&value);
        while(temp!=NULL&&temp->info!=value)
        {
            ptr=temp;
            temp=temp->next;
        }
        temp1=temp->next;
        ptr->next=temp->next;
        temp1->first=ptr;
    }
}
