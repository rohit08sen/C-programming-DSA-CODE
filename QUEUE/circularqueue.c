#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1, rear=-1, temp,no_of_elements=0;
	
void insert()
	{
    int value;
	// check queue is full or not
    if(((front==0) && (rear==max-1))|| front==rear+1){
        printf("queue overflow!!!\n");
    }
	//if not full input the value and find the rear location place the value there
	else{
        printf("enter value to insert:");
        scanf("%d",&value);
        if(front==-1 && rear==-1){
            front++;
            rear++;
        }
        else if(rear==max-1){
            rear=0;
        }
        // else if(front==rear+1){
        //     front=-1;
        //     rear=-1;
        // }
        else{
            rear++;
        }
        queue[rear]=value;
        no_of_elements++;
    }
    //increase no_of_elements by 1
	
	}

void delete()
	{
	// check queue is empty or not
    if(front==-1 && rear==-1){
        printf("queue underflow!!!\n");
    }

    //if not empty find the front location from where you delete the element
    else{
        printf("deleted element is %d.\n",queue[front]);
        if(front==max){
            front=0;
        }
        else if(rear==front){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        no_of_elements--;
    } 
	// decrease no_of_elements by 1
	}

void display()
    {
	int i;
	printf("\nThe queue content is :\n");
	if (front >rear)
		{
			for (i = front; i < max; i++)
				printf("%d\t",queue[i]);
			for (i = 0; i <= rear; i++)
				printf("%d\t",queue[i]);
		}
	else
		for (i = front; i <= rear; i++)
			printf("%d\t",queue[i]);
	printf("\n");
		
}

int main()
{
	int choice;
	while(1)
	{
		printf("\nMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("\nYour choice = ?");
		scanf(" %d",&choice);
		printf("\n*****");
		switch(choice)
		{
			case 1:
						insert();
						break;

			case 2:
						delete();
						break;

			case 3:
						if (no_of_elements==0)
							printf("\nNo elements in the list");
						else
							display();
						break;

			case 4:
						return 0;
						

			default:
						printf("Invalid Choice");
		}
	}

}