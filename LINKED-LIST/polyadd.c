#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int coef,expo;
    struct n *link;
}node;
node *head=NULL,*head1=NULL,*head2=NULL,*newnode,*temp;


node *createpoly(node *start){
    int n;
    if(start==NULL){
        printf("Enter the no. of terms you want:");
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            newnode=(node*)malloc (sizeof(node));
            newnode->link=NULL;
            printf("\nEnter the co-efficient of %d term :",i);
            scanf("%d",&newnode->coef);
            printf("\nEnter the exponent of %d term :",i);
            scanf("%d",&newnode->expo);
            if(start==NULL){
                start=newnode;
                temp=start;
            }
            else{
                temp->link=newnode;
                temp=newnode;
            }
        }
        return start;
    }
    else{
        printf("POlYNOMIAL IS PRESENT");
    }
    
}

void traverse(node* start){
    if(start==NULL){
        printf("Polynomial is not present\n");
    }
    else{
        temp=start;
        while(temp!=NULL){
            if(temp->expo==0){
                printf("(%d)",temp->coef);
            }
            else if(temp->expo==1){
                printf("(%d)x",temp->coef);
            }
            else{
                printf("(%d)x^%d",temp->coef,temp->expo);
            }
            temp=temp->link;
            if(temp!=NULL){
                printf("+ ");
            }
        }
    }
}
void polynomial_add(){
    node*h1,*h2;
    if(head1==NULL&&head2!=NULL){
        head=head2;
    }
    else if(head1!=NULL&&head2==NULL){
        head=head1;
    }
    else{
        h1=head1;
        h2=head2;
        while(h1!=NULL&&h2!=NULL){
            newnode=(node*)malloc(sizeof(node));
            newnode->link=NULL;
            if(h1->expo>h2->expo){
                newnode->expo=h1->expo;
                newnode->coef = h1->coef;
                h1 = h1->link;
            }
            else if(h1->expo<h2->expo){
                newnode->expo=h2->expo;
                newnode->coef=h2->coef;
                h2=h2->link;
            }
            else{
                newnode->expo=h1->expo;
                newnode->coef=h1->coef+h2->coef;
                h1=h1->link;
                h2=h2->link;
            }
            if(head==NULL){
                head=newnode;
            }
            else{
                temp=head;
                while(temp->link!=NULL){
                    temp=temp->link;
                }
                temp->link=newnode;
            }
        }
        while(h1!=NULL){
             newnode=(node*)malloc(sizeof(node));
             newnode->link=NULL;
             newnode->expo=h1->expo;
             newnode->coef=h1->coef;
             if(head==NULL){
                head=newnode;
            }
            else{
                temp=head;
                while(temp->link!=NULL){
                    temp=temp->link;
                }
                temp->link=newnode;
            }
            h1=h1->link;
        }
        while(h2!=NULL){
             newnode=(node*)malloc(sizeof(node));
             newnode->link=NULL;
             newnode->expo=h2->expo;
             newnode->coef=h2->coef;
             if(head==NULL){
                head=newnode;
            }
            else{
                temp=head;
                while(temp->link!=NULL){
                    temp=temp->link;
                }
                temp->link=newnode;
            }
            temp->link=newnode;
            h2=h2->link;
        }
    }
}
void main(){
    printf("create poly 1:-\n");
    head1=createpoly(head1);
    printf("create poly 2:-\n");
    head2=createpoly(head2);
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