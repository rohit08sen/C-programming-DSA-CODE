//checking correctness of parentheses
#include<stdio.h>
#include<stdlib.h>
#define max 30

char stack[max],top=(-1);

void push(char value){
    if(top==(max-1)){
        printf("stack overflow!!\n");
    }
    else{
        stack[++top]=value;
    }
}
void pop(){
    if(top==(-1)){
        return;
    }
    else{
        top--;
    }
}
main(){
    int i;
    char str[20];
    printf("enter string:");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            push(str[i]);
        }
        if(str[i]==')'){
            pop();
        }
    }
    if(top==(-1)){
        printf("correct.");
    }
    else{
        printf("incorrect.");
    }
    printf("\n");
}