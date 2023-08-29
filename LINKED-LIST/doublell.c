#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* first,*next;
};
struct node*start=NULL;
void create();
void traverse();
void insertbegin();
void insertend();
void insertposition();
void insertafternode();
void deletebegin();
void deleteend();
void deleteposition();
void deleteafternode();
void main()
{
	int choice;
	while(1){
		printf("\nMENU \n1.CREATE \n2.TRAVERSE \n3.INSERT-AT-BEGINING \n4.INSERT-AT-END \n5.INSERT-AT-POSITION \n6.INSERT-AFTER-NODE \n7.DELETE-AT-BEGINING \n8.DELETE-AT-END \n9.DELETE-AT-POSITION \n10.DELETE-AFTER-NODE \n11.EXIT\n");
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
			insertbegin();
			break;
			case 4:
			insertend();
			break;
			case 5:
			insertposition();
			break;
			case 6:
			insertafternode();
			break;
			case 7:
			deletebegin();
			break;
			case 8:
			deleteend();
			break;
			case 9:
		    deleteposition();
			break;
			case 10:
			deleteafternode();
			break;
			case 11:
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
void insertbegin()
{
    struct node*newnode,*temp;
    int item;
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
        temp=start;
        temp->first=newnode;
        newnode->next=temp;
        start=newnode;
    }
}
void insertend()
{
    struct node*newnode,*temp;
    int item;
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
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->first=temp;
    }
}
void insertposition()
{
    struct node*newnode,*temp,*ptr;
    int item,position,count=1;
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
    {   if(position==1)
        {
            insertbegin();
        }
        else
        {
        temp=start;
        printf("Enter the position where you want to insert:");
        scanf("%d",&position);
        while(temp!=NULL&&count!=position)
        {
            ptr=temp; 
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
        {
            printf("Node not present!!!");
        }
        else
        {
            ptr->next=newnode;
            newnode->next=temp;
            newnode->first=ptr;
            temp->first=newnode;
        }
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
void deletebegin()
{
    struct node*temp,*ptr;
    if(start==NULL)
    {
        printf("Node is not present!!!!");
    }
    else
    {
        temp=start;
        ptr=temp;
        temp=temp->next;
        ptr->next=NULL;
        temp->first=NULL;
        start=temp;
    }
}
void deleteend()
{
    struct node*temp,*ptr;
    if(start==NULL)
    {
        printf("Node is not present!!!");
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        temp->first=NULL;
    }
}
void deleteposition()
{
    struct node*temp,*ptr,*temp1;
    int count=1,pos;
    if(start==NULL)
    {
        printf("Node is not present!!!");
    }
    else
    {
        temp=start;
        printf("Enter the position you want to delete:");
        scanf("%d",&pos);
        while(temp!=NULL&&count!=pos)
        {
            ptr=temp;
            temp=temp->next;
            count++;
        }
        temp1=temp->next;
        ptr->next=temp->next;
        temp1->first=ptr;
    }
}
void deleteafternode()
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
