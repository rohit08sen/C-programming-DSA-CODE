/*Transpose of sparsematrix*/
#include<stdio.h>
int main()
{
    int triplet[50][3],colmajor[50][3],row,col,temp=1,i,j,nzero;
    printf("Enter the no. nonzero value:");
    scanf("%d",&nzero);
    /*input triplet matrix*/
    for(i=0;i<=nzero;i++){
        for(j=0;j<3;j++){
            printf("Enter the value");
            scanf("%d",&triplet[i][j]);
        }
    }
    /*display triplet matrix*/
    for(i=0;i<=nzero;i++){
        for(j=0;j<3;j++){
            printf("%d\t",triplet[i][j]);
        }
        printf("\n");
    }
    row=triplet[0][0];
    col=triplet[0][1];
    colmajor[0][0]=col;
    colmajor[0][1]=row;
    colmajor[0][2]=nzero;
    for(j=0;j<col;j++){
        for(i=1;i<=nzero;i++){
            if(triplet[i][1]==j){
                colmajor[temp][0]=j;
                colmajor[temp][1]=triplet[i][0];
                colmajor[temp++][2]=triplet[i][2];
            }
        }
    }
    printf("the transpose matrix is:\n");
      for(i=0;i<=nzero;i++){
        for(j=0;j<3;j++){
            printf("%d\t",colmajor[i][j]);
        }
        printf("\n");
    }
    return 0;
}
