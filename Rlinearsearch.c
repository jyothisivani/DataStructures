#include<stdio.h>
int linearsearchrec(int a[], int search, int n)
{
	 int i;
	  static int temp=0;
	   if(n>0)
		    {
			      i=n-1;
			         if(a[i] == search)
					     temp=1;
				    linearsearchrec(a, search, i);
				     }
	   return temp;
}

int main()
{
	 int n,j;
	  printf("Enter your array size:");
	   scanf("%d", &n);
	    int a[n];
	     printf("Enter the array element:");
	      for(j=0;j<n;j++)
		       {
			         scanf("%d", &a[j]);
				  }
	       
	       int search;
	        printf("Enter the search element:");
		 scanf("%d", &search);
		  
		  if(linearsearchrec(a, search, n)==1)
			    printf("Element Found");
		   else
			     printf("Element Not Found");
		     
		    return 0;
}

