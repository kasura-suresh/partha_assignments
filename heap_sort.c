/*************************************************

	program to implement heap sort
	Author-- Partha Pratim Dey
	
*************************************************/

#include<stdio.h>  
int temp;  
  
void heapify(int arr[], int size, int i)  
{  
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
	if (left < size && arr[left] >arr[largest])  
		largest = left;  
	if (right < size && arr[right] > arr[largest])  
		largest = right;  
	if (largest != i)  
	{  
		temp = arr[i];  
		arr[i]= arr[largest];   
		arr[largest] = temp;  
		heapify(arr, size, largest);  
	}  
}  
  
void heapSort(int arr[], int size)  
{  
	int i;  
	for (i = size / 2 - 1; i >= 0; i--)  
	heapify(arr, size, i);  
	for (i=size-1; i>=0; i--)  
	{  
		temp = arr[0];  
		arr[0]= arr[i];   
		arr[i] = temp;  
		heapify(arr, i, 0);  
	}  
}  
  
int main()  
{  
	int i,size;
	printf("Enter the number of elemnts:\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the element one by one:\n");
	for(i = 0;i<size;i++)
	{
		scanf("%d",&arr[i]);	
	} 
	  
	heapSort(arr, size);  
	  
	printf("After Sort:\n");  
	for (i=0; i<size; ++i)  
	printf("%d\t",arr[i]);  
} 
