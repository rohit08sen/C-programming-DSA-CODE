/*1. Design a function evaluatePostfix() to evaluate a postfix expression by using stack. Call it in main() to verify whether it is working correctly or not for the following expression:
623+-382/+* (Output: 7)
Also check for other different expressions.*/
#include<stdio.h>
#include<ctype.h>
#define MAXSTACK 100
#define POSTFIXSIZE 100
int stack[MAXSTACK];
int top=-1;
void push(int item)
{
	if(top>=MAXSTACK-1){
		printf("stackoverflow");
	}
	else{
		top=top+1;
		stack[top]=item;
	}
}
int pop()
{
	int item;
	if(top<0){
		printf("stackunder overflow:");
	}
	else{
		item=stack[top];
		top=top-1;
		return item;
	}
}
	void EvalPostfix(char postfix[])
{
	int i;
	char ch;
	int val;
	int A,B;
	for(i=0;postfix[i]!='\0';i++){
		ch=postfix[i];
		if(ch>=48&&ch<=57){
			val=ch-48;
			push(val);
		}
		else{
			A=pop();
			B=pop();
			switch(ch){
				case '+':
					push(B+A);
					break;
				case '-':
					push(B-A);
					break;
				case '*':
					push(B*A);
					break;
				case '/':
					push(B/A);
					break;
			}}
	}
			printf("The evaluated value =%d\n",stack[top]);
}
int main()
{
	int i;
	char postfix[POSTFIXSIZE];
	printf("Assumption:there are only 4 operators:\n");
	printf("Enter the postfix expression\n");
	scanf("%s",postfix);
	EvalPostfix(postfix);
	return 0;
}


