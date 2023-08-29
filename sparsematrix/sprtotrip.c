/*Define following 3 functions as per given specification and call these 3 functions in driver
function main().
(i) inputMatrix(a[][max],m,n) to input a sparse matrix in general form.
(ii) createSparse(a[][max],m,n,b[][3]) to create a sparse matrix in triple form.
(iii) printSparse(b[][3]) to display the sparse matrix in triple form*/
#include<stdio.h>
#define max 10
void inputMatrix(int a[][max],int m,int n);
void printMatrix(int a[][max],int m,int n);
void createSparse(int a[][max],int m,int n,int b[][3]);
void printSparse(int b[][3]);
void main()
{
	int sparse[10][10];
	int triplet[18][3];
	int rows,cols;
	printf("Enter the rows and cols no. of original mat:");
    scanf("%d %d",&rows,&cols);
	inputMatrix(sparse,rows,cols);
	printMatrix(sparse,rows,cols);
	createSparse(sparse,rows,cols,triplet);
	printSparse(triplet);
}
void inputMatrix(int a[][max],int m,int n){

	int i,j;
	printf("Enter the matrix element");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void printMatrix(int a[][max],int m,int n){
	int i,j;
	printf("The Original Matrix is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
                      printf("%d ",a[i][j]);
		}
		printf("\n");
	}}
void createSparse(int a[][max],int m,int n,int b[][3])
{
	int i,j,c=0,temp=1;
	b[0][0]=m;
	b[0][1]=n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){
				b[temp][0]=i;
				b[temp][1]=j;
				b[temp++][2]=a[i][j];
				c++;
			}
		}
	}
	b[0][2]=c;
}
void printSparse(int b[][3]){
	int i,j;
	printf("The triplet matrix is:\n");
	for(i=0;i<=b[0][2];i++){
		for(j=0;j<3;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");}
}