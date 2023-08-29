/*Modify the above program to implement a stack using C structure named ‘stack’. The structure should have members top(int type) and an array of elements(int type).
Define following functions to perform the stack operations.
pushToStack(), popFromStack(), displayStack()
Using menu driven program design the main() and call individual function to perform repeated operations on the stack and display the status of the stack after every operation until the user enters his choice to exit.*/
#include<stdio.h>
#define max 6
void pushToStack();
int popFromStack();
int isFull();
int isEmpty();
void displayStack();
struct Stack{
    int top;
    int stack[max];
}s;
 void main()
{
	int choice;
	int num;
	int option=1;
	s.top=-1;
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
				pushToStack();
				break;
			case 2:
				printf("\nThe deleted item %d\n",popFromStack());
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
	if(s.top<max-1){
	return 0;}
	else{
	return 1;}
}

int isEmpty()
{
  if(s.top==-1)
  {
    return 1;}
  else
  {
	return 0;
  }
}  
void pushToStack()
{
	int num;
    if(isFull()==1)
    {
	    printf("Overflow.\n");
    }
    else
    {
	    printf("Enter the num to be pushed:");
	    scanf("%d",&num);
	    s.top++;
	    s.stack[s.top]=num;
    }
}
int popFromStack()
{
	int val;
	if(isEmpty()==1)
	{
		printf("stack is empty\n");
	}
	else
	{
		val=s.stack[s.top];
		s.top--;
		return val;
	}
}
void displayStack()
{
	int i;
	if(s.top==-1)
	{
		printf("Stack is empty:\n");
		
	}
	else
	{
		printf("\nThe status of the stack is \n");
		for(i=s.top;i>=0;i--)
		{
			printf("%d\n",s.stack[i]);
		}
	}
	printf("\n");
}

     
