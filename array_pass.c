/*********************************************
 Program to pass an array within a function
 (Given by Suresh sir)
 Author-- Partha Pratim Dey
 
*********************************************/

#include<stdio.h>
void print_array(int arr[],int n)
{
	int i;
	printf("Your array is:\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);		
	}
}

int main()
{
	int i,n;
	printf("Enter the number of element:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Now enter the element:\n");
	for(i = 0 ; i < n ;i++)
	{
		scanf("%d",&arr[i]);
	}
	print_array(arr,n);
	return 0;
}
