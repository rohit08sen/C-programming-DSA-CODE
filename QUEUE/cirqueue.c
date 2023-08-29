#include<stdio.h>
#define max 6
int queue[max];
int front=-1,rear=-1;
void insert()
{   
    int value;
    printf("Enter the to be inserted:");
    scanf("%d",&value);
    if((rear==max-1)&&(front==0)||(front=rear+1)){
        printf("Queue is Overflow!!!");
    }
    else if(front==-1&&rear==-1){
        front==0;
        rear==0;
    }
    else if(rear==max-1){
        rear==0;
    }
    else{
        rear=rear+1;
        queue[rear]=value;
    }
}
void delete(){
    if(front==-1&&rear==-1){
        printf("Queue Underflow!!");
    }
    else{
        printf("The deleted item is %d",queue[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==max-1){
            front==0;
        }
        else{
            front++;
        }
    }
}
void display()
{
    int i;
    printf("Elements in the queue are:");
    if(front==-1){
        printf("Queue is Empty\n");
    }
    else if(front<=rear){
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    else{
        for(i=front;i<max;i++){
            printf("%d\t",queue[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
int main()
{
	int choice;
	while(1)
	{
		printf("\nMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("\nYour choice = ?");
		scanf(" %d",&choice);
		printf("\n*****\n");
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
						return 0;
						

			default:
						printf("Invalid Choice");
		}
	}

}

