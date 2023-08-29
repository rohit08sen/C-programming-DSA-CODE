#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int expo;
    int coef;
    struct node* next;
}node;

node *head1=NULL, *head2=NULL, *head=NULL,*newnode=NULL, *prev,*temp;

node* create(node* star){
    int c;
    newnode=(node*)malloc(sizeof(node));
    printf("enter coefficient:");
    scanf("%d",&newnode->coef);
    printf("enter exponent:");
    scanf("%d",&newnode->expo);
    newnode->next=NULL;
    star=newnode;
    printf("enter 1 to continue adding and 0 to end:");
    scanf("%d",&c);
    while(c){
        newnode->next=(node*)malloc(sizeof(node));
        newnode=newnode->next;
        printf("enter coefficient:");
        scanf("%d",&newnode->coef);
        printf("enter exponent:");
        scanf("%d",&newnode->expo);
        newnode->next=NULL;
        printf("enter 1 to continue adding and 0 to end:");
        scanf("%d",&c);
    }
    return star;
}

void traverse(node* star){
    if(star==NULL){
        printf("list is empty.\n");
    }
    else{
        prev=star;
        while(prev!=NULL){
            printf("(%d)x^%d",prev->coef,prev->expo);
            prev=prev->next;
            if(prev!=NULL){
                printf("+ ");
            }
        }
    }
}

void polynomial_add(){
    node *h1,*h2;
    if(h1==NULL && h2!=NULL){
       head=h2; 
    }
    else if(h1!=NULL && h2==NULL){
        head=h1;
    }
    else{
        h1=head1;
        h2=head2;
        while(h1!=NULL && h2!=NULL){
            newnode=(node*)malloc(sizeof(node));
            newnode->next=NULL;
            if(h1->expo > h2->expo){
                newnode->expo = h1->expo;
                newnode->coef = h1->coef;
                h1 = h1->next;
            }
            else if(h1->expo < h2->expo){
                newnode->expo = h2->expo;
                newnode->coef = h2->coef;
                h2 = h2->next;
            }
            else{
                newnode->expo = h1->expo;
                newnode->coef = h1->coef + h2->coef;
                h1 = h1->next;
                h2 = h2->next;
            }

            if(head==NULL){
                head=newnode;
            }
            else{
                prev=head;
                while(prev->next!=NULL){
                    prev=prev->next;
                }
                prev->next=newnode;
            }
        }
        while(h1!=NULL){
            newnode=(node*)malloc(sizeof(node));
            newnode->expo = h1->expo;
            newnode->coef = h1->coef;
            newnode->next=NULL;
            prev=head;
            while(prev->next!=NULL){
                prev=prev->next;
            }
            prev->next=newnode;
            h1 = h1->next;
        }
        while(h2!=NULL){
            newnode=(node*)malloc(sizeof(node));
            newnode->expo = h2->expo;
            newnode->coef = h2->coef;
            newnode->next=NULL;
            prev=head;
            while(prev->next!=NULL){
                prev=prev->next;
            }
            prev->next=newnode;
            h2 = h2->next;
        }
    }
}

main(){
    printf("create poly 1:-\n");
    head1=create(head1);
    printf("create poly 2:-\n");
    head2=create(head2);
    printf("\npolynomial 1:\n");
    traverse(head1);
    printf("\npolynomial 2:\n");
    traverse(head2);
    printf("\n");
    polynomial_add();
    printf("\npolynomial 1 + polynomial 2 =\n");
    traverse(head);
    printf("\n");
}