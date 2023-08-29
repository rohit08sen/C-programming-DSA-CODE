/*Write a menu-driven program to perform the following operations on a Binary
Search Tree
(i) Create a BST
(ii) Search for a node in the BST
(ii) Insert a node into the BST
(iii) Delete a node from the BST
(iv) Traverse the tree in inorder and display the contents*/
#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
    int info;
    struct node*lchild,*rchild;
}node;
 node*root=NULL;
void create()
{
    node*newnode,*ptr,*par=NULL;
    int item,total,i;
    if(root==NULL){
    printf("Enter the no. of node you want:");
    scanf("%d",&total);
    for(i=1;i<=total;i++)
    {
        newnode=(node*)malloc(sizeof(node));
        printf("Enter the value you want to insert:");
        scanf("%d",&item);
        newnode->info=item;
        newnode->lchild=NULL;
        newnode->rchild=NULL;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            ptr=root;
            while(ptr!=NULL)
            {
                par=ptr;
                if(item<ptr->info)
                {
                    ptr=ptr->lchild;
                }
                else if(item>ptr->info)
                {
                    ptr=ptr->rchild;
                }
                else
                {
                    printf("Duplicate child is not possible!!!!");
                    return;
                }
            }
                if(item<par->info)
                {
                    par->lchild=newnode;
                }
                else
                {
                    par->rchild=newnode;
                }
            }
        }
    }
    else{
        printf("list is present!!");
    }
}
void inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->lchild);//L
		printf("%d ",temp->info);//N
		inorder(temp->rchild);//R
	}
}
void search(){
    if(root==NULL){
        printf("Root is not present.");
    }
    else{
        node*temp=root;
        int item;
        printf("Enter the node you want to search:");
        scanf("%d",&item);
        while(temp!=NULL){
        if(item<temp->info){
            temp=temp->lchild;
        }
        else if(item<temp->info){
            temp=temp->rchild;
        }
        else{
            printf("Element found");
            return;
        }
    }
    printf("Node not found");
}
}
void insert(){
    node* newnode,*ptr,*par;
    int item;
    printf("Enter the node you want to insert: ");
    scanf("%d",&item);
    newnode=(node*)malloc(sizeof(node));
    newnode->info=item;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(root==NULL){
        root=newnode;
    }
    else{
        ptr=root;
        while(ptr!=NULL){
            par=ptr;
            if(item<ptr->info){
                ptr=ptr->lchild;
            }
            else if(item>ptr->info){
                ptr=ptr->rchild; 
            }
            else{
                printf("Duplicate child is not allowed!!!!\n");
                return;
            }
        }
        if(item<par->info){
            par->lchild=newnode;
        }
        else{
            par->rchild=newnode;
        }
    }
}
void case0(node *ptr,node*par){
    if(par==NULL){
        //Delete the single node i.e.root
        root==NULL;
        free(ptr);
    }
    else{
        if(ptr->info<par->info){
            par->lchild=NULL;
        }
        else{
            par->rchild=NULL;
        }
        free(ptr);
    }
}
void case1(node *ptr,node*par){
      node *child;
      if(ptr->lchild!=NULL){
        child=ptr->lchild;
      }
      else{
        child=ptr->rchild;
      }
      if(par==NULL){
        root=child;
        free(ptr);
      }
      else{
        if(ptr==par->lchild){
            par->lchild=child;
        }
        else{
            par->rchild=child;
        }
        free(ptr);
      }
}
void case2(node *ptr,node *par){
    node *pptr,*ppar;
    pptr=ptr->rchild;
    ppar=ptr;
    while(pptr->lchild!=NULL){
        ppar=pptr;
        pptr=pptr->lchild;
    }
    ptr->info=pptr->info;
    if(pptr->rchild!=NULL){
        case1(ppar,pptr);
    }
    else{
        case0(ppar,pptr);
    }
}       
void delete(){
    struct node *ptr,*par;
    int item;
    if(root==NULL){
        printf("Tree is empty\n");
    }
    else{
        ptr=root;
        par=NULL;
        printf("\nEnter the node to be deleted\n");
        scanf("%d",&item);
        while(ptr!=NULL){
            if(ptr->info==item){
                break;
            }
            par=ptr;
            if(item<ptr->info){
                ptr=ptr->lchild;
            }
            else{
                ptr=ptr->rchild;
            }
        }
        if(ptr==NULL){
            printf("Node is not present!!!!\n");
        }
        else{
            printf("The deleted node is =%d\n",ptr->info);
            if((ptr->lchild==NULL)&&(ptr->rchild==NULL)){
                case0(par,ptr);
            }
            else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL)){
                case2(par,ptr);
            }
            else{
                case1(par,ptr);
            }
        }
    }
}

void main()
{
	int choice;
    int k;
	while(1)		
	{
		printf("\nBST Operations\n");
		printf("\n1.INORDER-TRAVERSE\n2.CREATE\n3.SEARCH\n4.INSERT\n5.DELETE\n6.EXIT\n");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:inorder(root);
				   break;
			case 2:create();
					break;
			case 3:search();
					break;
			case 4:insert();
					break;
			case 5:
                    printf("Enter the node you want to delete:");
                    scanf("%d ",&k);
                    delete(root,k);
					break;
			case 6:exit(0);
			default:printf("\nWrong choice");
		}
	}
}