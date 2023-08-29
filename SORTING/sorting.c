#include<stdio.h>
void bubble(int a[],int);
void selection(int a[],int);
void insertion(int a[],int);
void mergeSort(int a[],int,int);
void merge(int a[],int,int,int);
void display(int a[],int);
void quickSort(int a[],int,int);
int partion(int a[],int,int);
void swap(int a[],int,int);
void main(){
	int a[20],n,choice,i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the array element:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nWelcome to sorting mechanism\n");

	while(1){
		printf("\n1.BUBBLE-SORT\n \n2.INSERTION-SORT\n \n3.SELECTION-SORT\n \n4.MERGE-SORT\n \n5.QUICK-SORT\n \n6.EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:bubble(a,n);
			       break;
			case 2:insertion(a,n);
			       break;
			case 3:selection(a,n);
			       break;
            case 4:mergeSort(a,0,n-1);
                   printf("The merge sorted array is:");
                   display(a,n);
                   break;
            case 5:quickSort(a,0,n-1);
                   printf("The quick sorted array is:");
                   display(a,n);
                   break;
			case 6:return;
			       break;
			default:printf("Enter correct option!!!!\n");
		}
	}
}
void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
    }
    printf("\n");
}
void bubble(int a[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
		if(a[i]>a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	}
	printf("\nBubble sorted array is:");
	display(a,n);
}
void insertion(int a[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("\nInsertion sorted array is:");
	display(a,n);
}
void selection(int a[],int n){
	int i,j,min,temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(min!=i){
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("\nSelection sorted array is:");
    display(a,n);
}
void mergeSort(int a[],int l,int r){
    int mid;
    if(l<r){
        mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void merge(int a[],int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int k=l;
    int b[20];
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    if(i>mid){
        while(j<=r){
            b[k++]=a[j++];
        }
    }
    else{
        while(i<=mid){
            b[k++]=a[i++];
        }
    }
    for(k=l;k<=r;k++){
        a[k]=b[k];
    }
}
void swap(int a[],int c, int d){
    int temp;
    temp=a[c];
    a[c]=a[d];
    a[d]=temp;
}
int partion(int a[],int l,int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(a,i,j);
        }
    }
    if(j>i){
        swap(a,l,j);
    }
    return j;
}
void quickSort(int a[],int l,int h){
    if(l<h){
        int pivot=partion(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }
}
