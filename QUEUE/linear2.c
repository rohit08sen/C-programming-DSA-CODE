/*program to implement a linear queue using array*/
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
	if((rear==-1 && front==-1)||(front=rear+1))
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
	// if(front<0){
	// 	for(i=0;i<rear;i++)
	// 		printf("%d\t",queue[i]);
	// }
	// else{
	// 	if(front==rear)
	// 		printf("NO items found");
	// 	else{
	// 		for(i=front+1;i<=rear;i++)
	// 			printf("%d\t",queue[i]);
	// 	}
	// 	}
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
				// if(front==rear)
				// 	front =rear=-1;
				// if (isFull())
				// 	printf("queue is full\n");
				// else
				// {
					printf("Enter the element to be inserted: ");
					scanf("%d",&item);
					insert(item);
					//display();
				// }
				break;
			case 2:
				// if(isEmpty())
				// 	printf("Queue is Empty\n");
				// else{
				// 	printf("The deleted item is: %d\n",delete());
			    //     	display();
				// }
				delete();
				//display();
				break;
			case 3:
				// if(isEmpty())
				// 	printf("Queue is Empty\n");
				// else
				// 	display();
				display();
				break;
			case 4:
				return;
			default :
				printf("Invalid Choice\n");
		}
	}
}
