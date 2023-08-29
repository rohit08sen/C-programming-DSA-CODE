#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *lchild;
	int info;
	struct Node *rchild;
};
struct Node *root = NULL;

void inorder(struct Node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->lchild);//L
		printf("%d ",temp->info);//N
		inorder(temp->rchild);//R
	}
}
void preorder(struct Node *temp)
{
	if(temp != NULL)
	{
		printf("%d ",temp->info);//N
		preorder(temp->lchild);//L
		preorder(temp->rchild);//R
	}
}
void postorder(struct Node *temp)
{
	if(temp != NULL)
	{
		postorder(temp->lchild);//L
		postorder(temp->rchild);//R
		printf("%d ",temp->info);//N
	}
}
void traverse()
{
	int choice;
	if(root != NULL)
	{
		printf("\nWelcome to the traversal mechanisms \n");
		printf("\n1.IN-ORDER\n2.PRE-ORDER\n3.POST-ORDER\n");
		printf("\nEnter your choice to traverse ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nValues of tree using inorder traversal are \n");
					inorder(root);
					break;
			case 2:printf("\nValues of tree using preorder traversal are \n");
					preorder(root);
					break;
			case 3:printf("\nValues of tree using postorder traversal are \n");
					postorder(root);
					break;
		}
	}
	else
	{
		printf("\nTree is empty\n");
	}
}
void largest()
{
	struct Node *temp;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		temp = root;
		while(temp->rchild != NULL)
		{
			temp = temp->rchild;
		}
		printf("\nLargest node is %d\n",temp->info);
	}
}
void smallest()
{
	struct Node *temp;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		temp = root;
		while(temp->lchild != NULL)
		{
			temp = temp->lchild;
		}
		printf("\nSmallest node is %d\n",temp->info);
	}
}
void sort()
{
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		printf("\nSorted tree values are \n");
		inorder(root);
	}
}
void create()
{
	int total,index,item;
	struct Node *newnode,*temp,*ptr;
	if(root == NULL)
	{
		printf("\nEnter how many nodes you want to keep in your tree ");
		scanf("%d",&total);
		for(index=1;index<=total;index++)
		{
			newnode = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter value for the node ");
			scanf("%d",&item);
			newnode->info = item;
			newnode->lchild = NULL;
			newnode->rchild = NULL; 
			if(root == NULL)
			{
				root = newnode;
			}
			else
			{
				temp = root;
				ptr = root;
				while(temp != NULL)
				{
					ptr = temp;
					if(item < temp->info)
					{
						temp = temp->lchild;
					}
					else if(item > temp->info)
					{
						temp = temp->rchild;
					}
					else
					{
						printf("\nDuplicate element is not allowed\n");
						return;
					}
				}
				if(item < ptr->info)
				{
					ptr->lchild = newnode;
				}
				else
				{
					ptr->rchild = newnode;
				}
			}
		}
	}
	else
	{
		printf("\nList is already present");
	}
}
void insert()
{
	struct Node *newnode,*temp,*ptr;
	int item;
	newnode = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter value for the node ");
	scanf("%d",&item);
	newnode->info = item;
	newnode->lchild = NULL;
	newnode->rchild = NULL; 
	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		temp = root;
		ptr = root;
		while(temp != NULL)
		{
			ptr = temp;
			if(item < temp->info)
			{
				temp = temp->lchild;
			}
			else if(item > temp->info)
			{
				temp = temp->rchild;
			}
			else
			{
				printf("\nDuplicate element is not allowed\n");
				return;
			}
		}
		if(item < ptr->info)
		{
			ptr->lchild = newnode;
		}
		else
		{
			ptr->rchild = newnode;
		}
	}
}
void search()
{
	struct Node *temp;
	int item;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		printf("\nEnter the value to search ");
		scanf("%d",&item);
		temp = root;
		while(temp != NULL)
		{
			if(item < temp->info)
			{
				temp = temp->lchild;
			}
			else if(item > temp->info)
			{
				temp = temp->rchild;
			}
			else
			{
				printf("\nElement found\n");
				return;
			}
		}
		printf("\nNode is not present\n");
	}	
}
void case_zero(struct Node *temp,struct Node *ptr)
{
	if(ptr == NULL)//delete the root
	{
		root = NULL;
	}
	else if(ptr->lchild == temp)
	{
		ptr->lchild = NULL;
	}
	else
	{
		ptr->rchild = NULL;
	}
	free(temp);
}
void case_one(struct Node *temp,struct Node *ptr)
{
	struct Node *child;
	if(temp->lchild != NULL)
	{
		child = temp->lchild;
	}
	else
	{
		child = temp->rchild;
	}
	if(ptr == NULL)//delete the root
	{
		root = child;
	}
	else
	{
		if(temp == ptr->lchild)
		{
			ptr->lchild = child;
		}
		else
		{
			ptr->rchild = child;
		}
	}
	free(temp);
}
void case_both(struct Node *temp,struct Node *ptr)
{
	struct Node *pptr,*ptemp;
	pptr = temp;
	ptemp = temp->lchild;//1 Left
	while(ptemp->rchild != NULL)//Extreme right
	{
		pptr = ptemp;
		ptemp = ptemp->rchild;
	}
	temp->info = ptemp->info;
	if(ptemp->lchild != NULL)
	{
		case_one(ptemp,pptr);
	}
	else
	{
		case_zero(ptemp,pptr);
	}
}
void delete1()
{
	struct Node *temp,*ptr=NULL;
	int item;
	if(root == NULL)
	{
		printf("\nTree is empty\n");
	}
	else
	{
		printf("\nEnter the value to delete ");
		scanf("%d",&item);
		temp = root;
		while(temp != NULL)
		{
			if(temp->info == item)
			{
				break;
			}
			ptr = temp;
			if(item < temp->info)
			{
				temp = temp->lchild;
			}
			else
			{
				temp = temp->rchild;
			}
		}
		if(temp == NULL)
		{
			printf("Node is not present");
		}
		else
		{
			printf("\nThe delete node is %d\n",temp->info);
			if(temp->lchild != NULL && temp->rchild != NULL)//both children
			{
				case_both(temp,ptr);
			}
			else if(temp->lchild == NULL && temp->rchild == NULL)
			{
				case_zero(temp,ptr);//Zero child or leaf node
			}
			else
			{
				case_one(temp,ptr);//One child either left or right
			}
		}
	}	
}
void main()
{
	int choice;
	while(1)		
	{
		printf("\nBST Operations\n");
		printf("\n1.TRAVERSE\n2.CREATE\n3.SEARCH\n4.INSERT\n5.DELETE\n6.SORTING\n7.LARGEST\n8.SMALLEST\n9.EXIT\n");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:traverse();
				   break;
			case 2:create();
					break;
			case 3:search();
					break;
			case 4:insert();
					break;
			case 5:delete1();
					break;
			case 6:sort();
					break;
			case 7:largest();
					break;
			case 8:smallest();
					break;
			case 9:exit(0);
			default:printf("\nWrong choice");
		}
	}
}