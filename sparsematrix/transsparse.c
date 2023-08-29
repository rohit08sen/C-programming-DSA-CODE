/*Define following 3 functions as per given specification and call these 3 functions in driver
function main().
(i) inputMatrix(a[][max],m,n) to input a sparse matrix in general form.
(ii) createSparse(a[][max],m,n,b[][3]) to create a sparse matrix in triple form.
(iii) printSparse(b[][3]) to display the sparse matrix in triple form
Modify the Q1 program of Assignment-2 and define following new function and test it
using driver function.
Function transposeSparse(a[][3],b[][3]) to transpose the sparse matrix.
 */
#include<stdio.h>
#define max 10
void inputMatrix(int a[][max],int m,int n);
void printMatrix(int a[][max],int m,int n);
void createSparse(int a[][max],int m,int n,int b[][3]);
void transposeSparse(int b[][3],int c[][3]);
void main()
{
	int sparse[10][10];
	int triplet[18][3];
	int trans[18][3];
	int rows,cols;
	printf("Enter the rows and cols no. of original mat:");
    scanf("%d %d",&rows,&cols);
	inputMatrix(sparse,rows,cols);
	printMatrix(sparse,rows,cols);
	createSparse(sparse,rows,cols,triplet);
	transposeSparse(triplet,trans);
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
	printf("The spasre matrix is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
                      printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("The transpose of sparsematrix is:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",a[j][i]);
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
void transposeSparse(int b[][3],int c[][3]){
	int i,j,k,p;
	printf("The triplet matrix is:\n");
	for(i=0;i<=b[0][2];i++){
		for(j=0;j<3;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");}
	printf("The triplet matrix of transposed matrix:\n");
	for(i=0;i<=b[0][2];i++){
			c[i][0]=b[i][1];
			c[i][1]=b[i][0];
			c[i][2]=b[i][2];
			}
	for(i=1;i<=b[0][2];i++){
		for(j=i+1;j<=b[0][2];j++){
			if(c[i][0]>c[j][0]){
				for(p=0;p<3;p++){
					k=c[j][p];
					c[j][p]=c[i][p];
					c[i][p]=k;
				}}
			}
		}
	
	for(i=0;i<=b[0][2];i++){
		for(j=0;j<3;j++){
			printf("%d ",c[i][j]);}
		printf("\n");
	}
}
	
