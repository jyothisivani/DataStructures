#include <stdio.h>
int rlinearsearch(int [],int,int);
int main(){
	int pos,a[10],n,i,key;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched:");
	scanf("%d",&key);
	pos = rlinearsearch(a,n,key);
	if(pos>0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}
int rlinearsearch(int a[],int n,int key){
	int rec;
	if(n>0){
		if(a[n-1]==key){
			return n-1;
		}
		else{
			return rlinearsearch(a,n-1,key);
		}
	}
	return -1;
}
