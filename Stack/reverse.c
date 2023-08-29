#include<stdio.h>
#include<string.h>
#define size 10
char stack[size];
void push(char);
char pop();
void display();
void reverse(char ar[]);
int top;
void main()
{
   top=-1;
   char name[size];
   printf("Enter your Name:");
   scanf("%s",name);
   reverse(name);
}
void push(char x){
   if(top==size-1){
      printf("Stack is Overflow!!!");
   }
   else{
      stack[++top]=x;
   }
}
char pop(){
   if(top==-1){
      printf("Stack is Underflow!!!");
   }
   else{
      return stack[top--];
   }
}
void display(){
    int index;
    if(top==-1){
        printf("Stack is underflow!!!");
    }
    else{
        printf("The reversed is:");
    for(index=top;index>=0;index--){
			printf("%c",pop());
		}
    }
}
void reverse(char ar[]){
   int index;
   for(index=0;ar[index]!='\0';index++){
      push(ar[index]);
   }
   display();
}
       