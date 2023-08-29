/*Modify the above program and define following new function and test it using driver
function.
Function originalMatrix(b[][3]) where it will convert to a general matrix form and display.
Where b[][3] is the triplet form matrix.*/
#include<stdio.h>
#define max 10
void inputMatrix(int b[][3],int m);
void printMatrix(int b[][3],int m);
void originalMatrix(int b[][3]);
void main()
{
    int tripletMatrix[10][3];
    // int sparseMatrix[10][10];
    int r;
    printf("Enter the no. of rows of triplet matrix:");
    scanf("%d",&r);
    inputMatrix(tripletMatrix,r);
    printMatrix(tripletMatrix,r);
    originalMatrix(tripletMatrix);
    return ;  
}
    void inputMatrix(int b[][3],int m)
    {
        int i,j;
        printf("Enter the Tripletmatrix:\n");
        for(i=0;i<=m;i++){
           for(j=0;j<3;j++){
           scanf("%d",&b[i][j]);
        }
     }
    }
 void printMatrix(int b[][3],int m)
    {
         int i,j;
          printf("The Tripletmatrix is:\n");
          for(i=0;i<=m;i++){
             for(j=0;j<3;j++){
             printf("%d ",b[i][j]);
        }
        printf("\n");
     }
    }
    void originalMatrix(int b[][3])
    {   
        int a[max][max];
        int rows,cols,i,j;
        rows=b[0][0];
        cols=b[0][1];
        int nzero=b[0][2];
        for(i=0;i<rows;i++){
          for(j=0;j<cols;j++){
            a[i][j]=0;
        }
    }
    for(i=1;i<=b[0][2];i++){
        a[b[i][0]][b[i][1]]=b[i][2]; 
     }
     printf("The sparse matrix is:\n");
     for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
      }  
    }
