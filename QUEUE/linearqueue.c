/*Write a program to implement a Queue by using array. The array is global variable.
Define following 4 functions as per given specification.
(i) void insert(int) to insert an element into the Queue.
(ii) void delete() to remove an element from the Queue and return the removed
element.
(iii) int isFull() to check the Queue is full or not and return 1 (full) or 0 (not full).
(iv) int isEmpty() to check the Queue is empty or not and return 1 (empty) or 0
(not empty).
(v) void displayQueue() to display the elements of the Queue.
Using menu driven program design the main() and call individual function to
perform repeated operations on the Queue and display the status of the Queue
after every operation until the user enters his choice to exit.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;

int isFull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if((rear==-1 && front==-1)||(front>rear))
		return 1;
	else
		return 0;
}

void insert(int x){
	if(!isFull()){
		if(rear==-1 && front==-1){
			rear++;
			front++;
		}
		else{
			rear++;
		}
		queue[rear]=x;
	}
	else{
		printf("queue overflow!!!\n");
	}
}

void delete(){
    if(isEmpty())
    {
	    printf("Queue underflow!!!\n");
	}
    else{
		printf("The deleted item is: %d\n",(queue[front++]));
	}
}

void display()
{
	int i;
	printf("The queue content is :\n");
	if(isEmpty()){
		printf("queue is empty!!!\n");
	}
	else{
		for(i=front;i<=rear;i++){
			printf("%d ",queue[i]);
		}
	}
	printf("\n");
}

void main()
{
	int item,choice;
	while(1)
	{
		printf("\nMENU\n1.INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT\n");
                printf("\nYour Choice= ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				return;
			default :
				printf("Invalid Choice\n");
		}
	}
}
