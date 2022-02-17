#include <stdio.h>
int binarysearch(int [],int,int,int);
int main(){
	int a[10],pos,i,n,key;
	printf("Enter size of array:");
	scanf("%d",&n);
	
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("Enter element to be searched:");
        scanf("%d",&key);

	pos = binarysearch(a,0,n-1,key);
	
	if(pos>0){
		printf("Element found at position %d",pos);
	}
	else{
	printf("Element not found");
	}
        return 0;
}
int binarysearch(int a[],int l,int h, int key){
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(key==a[mid]){
			return mid;
		}
		else if(key > a[mid]){
			l = mid+1;
		}
		else{
			h=mid-1;
		}
	}
	if(l>h){
		return -1;
	}
}
	
