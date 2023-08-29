/*1. Design a function infixToPostfix() to convert an infix expression to postfix expression by using stack. Call it in main() to verify whether it is working correctly or not for the following expression:
((A-(B+C))*D)^(E+F) (Output: ABC+-D*EF+^)
Also check for other different expressions.*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define stackmax 50
#define postmax 50
int top=-1;
int stack[stackmax];
void push(char item)
{
    if(top>=stackmax-1){
        printf("stack is overflow");
    }
    else{
        top++;
        stack[top]=item;
    }
}
int pop()
{
    int item;
    if(top<0){
        printf("stack is empty");
    }
    else{
        item=stack[top];
        top--;
        return item;
    }
}
int is_Operator(char item)
{
    if(item=='^'||item=='*'||item=='+'||item=='-'||item=='/'||item=='%'){
        return 1;
    }
    else{
    return 0;
    }
}
int precedence(char operator)
{
    switch(operator){
        case'+':
        case'-':
          return 1;
        case'*':
        case'/':
          return 2;
        case'^':
          return 3;
        default:
          return 0;
    }
}
 void infixTopostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char ch;
    char x;
    push('(');
    strcat(infix,")");
    ch=infix[i];
    while(ch!='\0'){
        
        if(ch=='('){
            push(ch);
        }
        else if(isdigit(ch)||isalpha(ch)){
              postfix[j++]=ch;
        }
        else if(is_Operator(ch)==1){
            x=pop();
            while((is_Operator(x)==1&&precedence(x)>=precedence(ch))){
                postfix[j++]=x;
                x=pop();
            }
            push(x);
            push(ch);
        }
        else if(ch==')'){
            x=pop();
            while(x!='('){
                postfix[j++]=x;
                x=pop();
            }
        }
        else{
            printf("Invalid Expression");
        }
        i++;
        ch=infix[i];
       
    }
     postfix[j]='\0';
}
int main()
{
    char infix[postmax],postfix[postmax];
    printf("Enter the infix expression= ");
    scanf("%s",infix);
    infixTopostfix(infix,postfix);
    printf("Postfix Expression=%s ",postfix);
    return 0;
}