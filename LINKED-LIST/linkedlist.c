#include<stdio.h>
#include<stdlib.h>
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
void reverse();
void sort();
void merge();
void create1();
void create2();
struct node{
	int info;
	struct  node*next;
};
struct node*start=NULL,*start1=NULL,*start2=NULL;
void main(){
	int choice;
	while(1){
		printf("\nMENU \n1.CREATE \n2.TRAVERSE \n3.INSERT-AT-BEGINING \n4.INSERT-AT-END \n5.INSERT-AT-POSITION \n6.INSERT-AFTER-NODE \n7.DELETE-AT-BEGINING \n8.DELETE-AT-END \n9.DELETE-AT-POSITION \n10.DELETE-AFTER-NODE \n11.REVERSE \n12.SORT \n13.MERGE \n14.EXIT\n");
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
			reverse();
			break;
			case 12:
			sort();
			break;
			case 13:
			merge();
			break;
			case 14:
			return;
			break;
			default:
			printf("Invalid choice!!!");
		}
	}
}
void traverse(){

	struct node*temp;
	if(start==NULL)
	{
		printf("Elements are not present");
	}
	else
	{
		temp=start;
		printf("The elements are:");
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;       
		} 
	}
}
void insertbegin()
{
	struct node*newnode;
	int item;
	newnode=(struct node*) malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is not allocated.");
	}
	else
	{
        printf("Enter the value you want to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
	}
}
void insertend()
{
	struct node*newnode,*temp;
	int item;
	newnode=(struct node*) malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is not allocated.");
	}
	else
	{
        printf("Enter the value you want to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL){
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
		} 
	}
}
void insertposition()
{
	struct node*newnode,*temp,*ptr;
	int item;
	int position,count=1;
	newnode=(struct node*) malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory is not allocated.");
	}
	else
	{
        printf("Enter the value you want to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			temp=start;
			printf("enter the position at which you want to insert");
			scanf("%d",&position);
			if(position==1)
			{
				insertbegin();
			}
			else
			{
				while(temp!=NULL&&count!=position-1)
				{
					temp=temp->next;
					count++;
				}
				if(temp==NULL)
				{
					printf("\n Node is not present\n");
				}
				else
				{
					newnode->next=temp->next;
					temp->next=newnode;
				}
			}	
        }
	}
}
void insertafternode(){
	struct node*newnode,*temp;
	int value,item;
	newnode=(struct node*)malloc(sizeof(struct node*));
	if(newnode==NULL)
	{
		printf("Memory is not allocated");
	}
	else
	{
		printf("Enter the value you want to insert:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=NULL;
	}
	if(start==NULL){
		start=newnode;
	}
	else{
		printf("After which node you want to insert:");
		scanf("%d",&value);
		temp=start;
		while(temp->info!=value){
			temp=temp->next;
		}
		if(temp==NULL){
			printf("Value is not present!!!\n");
		}
		else{
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
}
void deletebegin()
{
	struct node*temp;
    if(start==NULL)
	{
		printf("No element is present:");
	}
	else
	{
		temp=start;
		start=temp->next;
		free(temp);
	}
}
void deleteend(){
	struct node*temp,*ptr;
	if(start==NULL)
	{
		printf("No element present\n");
	}
	else
	{
		temp=start;
		while(temp->next!=NULL){
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		free(temp);
	}
}
void deleteposition()
{
	struct node*temp,*ptr;
	int position,count=1;
	if(start==NULL)
	{
		printf("No element present!!!");
	}
	else
	{
		temp=start;
		printf("Enter the position You want to delete:");
		scanf("%d",&position);
		while(temp!=NULL&&count!=position)
		{
			ptr=temp;
			temp=temp->next;
			count++;
		}
		printf("The deleted item is %d.",temp->info);
		ptr->next=temp->next;
		free(temp);
	}
}
void deleteafternode()
{
	struct node*temp,*ptr;
	int value;
	if(start==NULL)
	{
		printf("No element is present\n");
	}
	else
	{
		temp=start;
		printf("Enter the node you want to delete:");
		scanf("%d",&value);
		while(temp!=NULL&&temp->info!=value)
		{
			ptr=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("Node not present\n");
		}
		else
		{
		ptr->next=temp->next;
		printf("The deleted item is %d",temp->info);
		free(temp);
		}
	}
}
void create()
{
	int item,index,total;
	struct node*temp,*newnode;
	if(start==NULL)
	{
		printf("Total no.of node you want:");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			start=temp;
			for(index=2;index<=total;index++)
			{
			newnode=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			newnode->info=item;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
			}
		}
	}
	else
	{
		printf("\nAlready link is present\n");
	}
}  
void reverse()
{
	struct node*current,*previous,*forward;
	if(start==NULL)
	{
		printf("List is not present");
	}
	else{
		current=start;
		previous=forward=NULL;
		while(current!=NULL)
		{
			forward=current->next;
			current->next=previous;
			previous=current;
			current=forward;
		}
		start=previous;
	}
}
void sort()
{
	struct node*temp,*min,*ptr;
	int item;
	if(start==NULL)
	{
		printf("No list is present!!!!");
	}
	else
	{
		temp=start;
	   for(int i=0;temp!=NULL;i++){
		
	   }
    }
}
void create1()
{
	int item,index,total;
	struct node*temp,*newnode;
	if(start1==NULL)
	{
		printf("Total no.of node you want:");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			start1=temp;
			for(index=2;index<=total;index++)
			{
			newnode=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			newnode->info=item;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
			}
		}
		printf("List-1 is created.\n");
	}
	else
	{
		printf("\nAlready link is present\n");
	}
}  
void create2()
{
	int item,index,total;
	struct node*temp,*newnode;
	if(start2==NULL)
	{
		printf("Total no.of node you want:");
		scanf("%d",&total);
		if(total<=0)
		{
			printf("\nList size must be greater than zero\n");
		}
		else
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			temp->info=item;
			temp->next=NULL;
			start=temp;
			for(index=2;index<=total;index++)
			{
			newnode=(struct node*)malloc(sizeof(struct node*));
			printf("\nEnter the value you want :");
			scanf("%d",&item);
			newnode->info=item;
			newnode->next=NULL;
			temp->next=newnode;
			temp=newnode;
			}
		}
		printf("List-2 is created.");
	}
	else
	{
		printf("\nAlready link is present\n");
	}
}  
void merge()
{
	struct node*temp;
	create1();
	create2();
	temp=start1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=start2;
	start=start1;
	traverse();
}