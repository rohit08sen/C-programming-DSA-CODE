#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void delete();
void insert();
struct node{
	int info;
	struct node*next;
};
struct node*start=NULL;
void main(){
	int choice;
	while(1)
	{
		printf("\nmenu \n1.insert \n2.delete \n3.displayqueue \n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
                                return;
				break;
			default:
				printf("Invalid choice!!!!\n");
		}
	}
}
void insert()
{
	struct node*newnode,*temp;
	int item;
	newnode=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the you wnt to insert");
	scanf("%d",&item);
	newnode->info=item;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{       temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void delete()
{
	struct node*temp;
	if(start==NULL)
	{
		printf("Underflow!!!\n");
	}
	else
	{
		temp=start;
		printf("The deleted item is %d",temp->info);
		start=temp->next;
		
		free(temp);
	}
}
void display()
{
	struct node*temp;
	if(start==NULL)
	{
		printf("UnderFlow!!!\n");
	}
	else
	{
		temp=start;
		printf("Contents are:");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
	}
}
