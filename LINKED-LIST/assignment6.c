/*1. Write a menu-driven program to perform the following operations on a Linked List.
2. Note: Don’t write all the functions at the same time. Do one by one and test.
3. Create a linked list
4. Traverse a linked list
5. Insert a node at the beginning of the linked list
6. Insert a node at the end of the linked list
7. Insert a node at a given location/position in the linked list
8. Insert a node after a specific node in the linkedlist
9. Delete a node from the beginning of the linked list
10. Delete a node from the end of the linked list
11. Delete a node from a given location/position in the linked list
12. Delete a node after a specific node in the linked list */
#include<stdio.h>
#include<stdlib.h>
typedef struct item
{
	int data;
	struct item *next;
}link;
link* create(link*);
void traverse(link*);
link* insertLink(link*);
link* deleteLink(link*);
void main()
{
	link *start;  
	start=NULL;
	int choice;
	while(1)
	{
		printf("\nmenu\n1.createlist\n2.displaylist\n3.insert\n4.delete\n5.stop\n");
		printf("\nEnterr your choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=(link*)malloc(sizeof(link));
				create(start);
				break;
			case 2:
				traverse(start);
				break;
			case 3:
				start=insertLink(start);
				break;
			case 4:
				start=deleteLink(start);
				break;
			case 5:
				return;
			default:
				printf("Ivalid choice");
		}
	}
}
link* create(link* new)
{
	printf("Enter the data:");
	scanf("%d",&new->data);
	new->next=NULL;
	return(new);
}
void traverse(link* list)
{
	link *tmp=list;
	while(tmp!=NULL)
	{
		printf("\ndata-%d",tmp->data);
		tmp=tmp->next;
	}
	return;
}
link* insertLink(link *list)
{
	int x;
	int choice,value;
	link *newlink;
	link *tmp,*tmp1,*ptr;
	int count,position;
	printf("\n1.insert at begining \n2insert at end \n3insert at position \n4insert after element\n");
	printf("\nEnter your choice=");
	scanf("%d",&choice);   
	switch(choice)
	{
		case 1:
			newlink=(link*)malloc(sizeof(link));
			printf("Enter the element to be inserted");
			scanf("%d",&newlink->data);
			newlink->next=list;
			list=newlink;
			break;
		case 2:
			tmp=list;
			while(tmp->next!=NULL){
				tmp=tmp->next;
			}
			newlink=(link*)malloc(sizeof(link));
			printf("Enter the elemnent is to be inserted");
			scanf("%d",&newlink->data);
			newlink->next=NULL;
			tmp->next=newlink;
			break;
	    case 4:
			tmp1=list;
			printf("\nAfter what value you want to insert-");
			scanf("%d",&value);
			while(tmp1->data!=value){
				tmp1=tmp1->next;
			}
			newlink=(link*)malloc(sizeof(link));
            newlink->next=NULL;
			printf("Enter the element to be inserted:");
			scanf("%d",&newlink->data);
			newlink->next=tmp1->next;
			tmp1->next=newlink;
			break;
		case 3:
			count=0;
			tmp1=list;
			printf("\nEnter the position to insert-");
			scanf("%d",&position);
			while(count<position-1){
				tmp1=tmp1->next;
				if(tmp1==NULL){
					printf("position not found");
                
				}				
				count++;
			}
                newlink=(link*)malloc(sizeof(link));
                printf("Enter the element to be inserted:");
                scanf("%d",&newlink->data);
                newlink->next=tmp1->next;
                tmp1->next=newlink;		
			break;
		default:
			printf("Invalid");
	}
	return list;
	}
link* deleteLink(link* list){
	int x;
	int choice,value;
	link *tmp,*tmp1;
	int count=0,position;
	printf("\n1.Delete from begining\n 2.Delete from end\n 3.Delete From position\n 4.Delete after element\n");
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			tmp=list;
			printf("The deleted value is:%d",tmp->data);
			tmp=tmp->next;
			list=tmp;
			break;
		case 2:
			tmp=list;
			while(tmp->next->next!=NULL){
				tmp=tmp->next;
			}
			printf("The deleted item is %d",tmp->next->data);
			tmp->next=NULL;
			break;
		case 3:
			tmp=list;
			printf("Enter the position you want to delete:");
			scanf("%d",&position);
			while(count<position-1){
				tmp=tmp->next;
				count++;
			}
			printf("The deleted item is %d",tmp->next->data);
			tmp=tmp->next->next;
			list=tmp;
             break;
		case 4:
			tmp=list;
			printf("Enter the value you want to delete:");
			scanf("%d",&value);
				while(tmp->data<value){
					tmp=tmp->next->next->next;
			}
			printf("The deleted item is %d",tmp->data);
			tmp=tmp->next;
			list=tmp;
			break;

       }
	return list;
}