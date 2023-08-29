#include<stdio.h>
#define size 10
char stack[size];
int top;
void push(char);
void display();
void decTobin(int);
void decTooctal(int);
void decTohexadec(int);
void main(){
    int num,choice;
    top=-1;
    printf("Enter a decimal number:");
    scanf("%d",&num);
     while(1){
        printf("\nMENU\n 1.DectoBin\n 2.DectoOctal\n 3.DectoHexadec\n 4.Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 printf("The Binary form is:");
                 decTobin(num);
                 break;
            case 2:
                 printf("The octal form is:");
                 decTooctal(num);
                 break;
            case 3:
                 printf("The Hexadecimal form is:");
                 decTohexadec(num);
                 break;
            case 4:
                 return;
            default:
                printf("Invalid Choice!!!");
        }
    }
}
void push(char x){
    if(top==size-1){
        printf("Stack is over flow!!!");
    }
    else{
    top++;
    stack[top]=x;
    }
}
char pop(){
    if(top==-1){
        printf("stack underflow!!!.\n");
    }
    else{
        return stack[top--];
    }
}
void display(){
    int i;
    if(top==-1){
        printf("Stack is underflow!!!");
    }
    else{
    for(i=top;i>=0;i--)
		{
			printf("%c\t",pop());
		}
    }
    //top=-1;
}
void decTobin(int num){
    int p;
     char c[]={'0','1'};
    while(num!=0){
    p=num%2;
    push(c[p]);
    num=num/2;
    }
    display();
}
void decTooctal(int num){
    int p;
    char c[]={'0','1','2','3','4','5','6','7'};
    while(num!=0){
    p=num%8;
    push(c[p]);
    num=num/8;
    }
    display();
}
void decTohexadec(int num){
    int p;
    char c[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(num!=0){
        p=num%16;
        push(c[p]);
        num=num/16;
    }
    display();
 }
