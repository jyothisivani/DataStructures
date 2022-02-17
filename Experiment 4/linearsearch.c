#include <stdio.h>
int linearsearch(int [],int,int);
int main(){
	int a[10],n,key,i,pos;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	pos = linearsearch(a,n,key);
	if(pos>0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}
int linearsearch(int a[],int n,int key){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}
