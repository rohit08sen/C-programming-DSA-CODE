/*Define following 4 functions as per given specification.
  (i) void push(int) to insert an element into the stack.
  (ii) int pop() to remove an element from the top of the stack.
  (iii) int isFull() to check the stack is full or not.
  (iv) int isEmpty() to check the stack is empty or not.
  (v) displayStack() to display the stack from tap to bottom.
  Using menu driven program design the main() and call individual function to perform
  repeated operations on the stack and display the status of the stack after every operation
  until the user enters his choice to exit.*/
#include<stdio.h>
#define max 6
int  stack[max];
int  top;
void push();
int  pop();
int  isFull();
int  isEmpty();
void displayStack();
void main()
{
	int choice;
	int num;
	int option=1;
	top=-1;
	printf("Stack Operation\n");
	while(option)
	{
		printf("--------------------------\n");
		printf("    1  -----> PUSH        \n");
		printf("    2  -----> POP         \n");
		printf("    3  -----> DISPLAY     \n");
		printf("    4  -----> EXIT        \n");
		printf("--------------------------\n");

		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				printf("\nThe deleted item %d\n",pop());
				break;
			case 3:
				displayStack();
				break;
			case 4:
				return;
		}
		fflush(stdin);
	}
}
/*Function to add an element to the stack*/
int isFull()
{
	if(top<max-1){
	return 0;}
	else{
	return 1;}
}

int isEmpty()
{
  if(top==-1)
  {
    return 1;}
  else
  {
	return 0;
  }
}  
void push()
{
	int num;
    if(isFull()==1)
    {
	    printf("Overflowi\n");
    }
    else
    {
	    printf("Enter the num to be pushed:");
	    scanf("%d",&num);
	    top++;
	    stack[top]=num;
    }
}
int pop()
{
	int val;
	if(isEmpty()==1)
	{
		printf("stack is empty\n");
	}
	else
	{
		val=stack[top];
		top--;
		return val;
	}
}
void displayStack()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty:\n");
		
	}
	else
	{
		printf("\nThe status of the stack is \n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
	printf("\n");
}

     
