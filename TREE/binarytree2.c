#include <stdio.h>
#include <stdlib.h>

struct n {
  int item;
  struct n* left;
  struct n* right;
};
typedef struct n node;
node* foundNode=NULL;

void searchNode( node* root,int parentValue) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  if(root->item==parentValue) {foundNode=root;return;};
  searchNode(root->left,parentValue);
  searchNode(root->right,parentValue);
}
// Create a new Node
node* createNode(int value) {
  node* newNode = malloc(sizeof(node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
// Insert on the left of the node
void insertLeft(node* parent, int value) {
  parent->left = createNode(value); 
}
// Insert on the right of the node
void insertRight(node* parent, int value) {
  parent->right = createNode(value);
  return;
}
void inorderTraversal( node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

int main() {
	node* root = createNode(3);
	int p,found=0;
	int newItem;
	char more='y',pos;
	
	while(1){
		printf("Inorder traversal \n");
		inorderTraversal(root);
		printf("\nEnter parent node value -");
		scanf("%d",&p);
		searchNode(root,p);
		node* parent, *new;
		if(foundNode !=NULL){
			if(foundNode->left != NULL && foundNode->right != NULL){
				printf("\nUnder node %d new node can not be inserted\n",foundNode->item);
			}
			else{
				if(foundNode->left == NULL) {
					printf("left is free");
				}
				if(foundNode->right == NULL){
						printf(" right is free");
				}
				printf("\nEnter L for left R for right -");
				scanf(" %c",&pos);
				printf("\nenter new node item-");
				scanf("%d",&newItem);
				if(pos == 'L' && foundNode->left==NULL){
					insertLeft(foundNode, newItem);
				}
				else if(pos == 'R' && foundNode->right==NULL){
					insertRight(foundNode,newItem);
					}
					else { 
						printf("\n Wrong position entered");
					}
			}
		}
		else{
			printf("\nnode not found");
		}
		printf("\nInsert more item (y/n)-");
		scanf(" %c",&more);
		if(more=='n') break;
	}
	printf("\nInorder traversal \n");
	inorderTraversal(root);
}
	