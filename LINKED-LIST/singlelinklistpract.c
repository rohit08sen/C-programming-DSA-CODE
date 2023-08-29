#include<stdio.h>
#include<stdlib.h>
 struct node
{
	int data;
	struct node*next;
};
struct node *create_node(struct node*);
void traverse(struct node*);
struct node *insert_node(struct node*);
struct node *delete_node(struct node*);
 int main()
{
    struct node *start;
    start=NULL;
    int choice;
    while (1)
	{
		printf("\nMENU\n1. Create start \n2.Display start\n3. Insert \n4. Delete\n5. Stop\n");
		printf("\nEnter Your Choice = ");
		scanf("%d",&choice);
	
		switch (choice)
		{
			case 1:	
				 start=create_node(start);

				break;
			case 2:
					 traverse(start);
					break;

			case 3: 
					
					start=insert_node(start);
					break;
			case 4:
				   start=delete_node(start);	
					
					break;
			case 5: 
					return 0;
			default: 
					printf("Invalid Choice\n");
		}
	}
    
} 

struct node *create_node(struct node *start)
{
    start=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data = ");
    scanf("%d",&start->data);
    start->next=NULL;
    return start;
}
void traverse(struct node *start)
{
	struct node *temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=(struct node*)temp->next;
    }
	

}
struct node *insert_node(struct node *start)
{
	int i=1,choice,position;
	struct node *newnode;
	struct node *temp1,*temp;
	printf("\n1:insert at begin\n2:insert at end\n3:insert at position\n4:insert after elemenr");
	printf("\nEnter Your Choice = ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter Data = ");
			scanf("%d",&newnode->data);
			newnode->next=start;
			start=newnode;
			break;
		case 2:
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;

			}
		    newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter Data = ");
			scanf("%d",&newnode->data);
			temp->next=newnode;
			newnode->next=NULL;
			break;
		case 3:
			temp1=start;
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the position=");
			scanf("%d",&position);
			printf("\nenter the value to be inserted=");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			for(i=1;i<=position-1; i++)
			{
				temp1=temp1->next;
			}
			newnode->next=temp1->next;
			temp1->next=newnode;
			break;
	}
	return start;



}
struct node *delete_node(struct node *start)
{

}