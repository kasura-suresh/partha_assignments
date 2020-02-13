#include <stdio.h> 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min; 
  
     
    for (i = 0; i < n-1; i++) 
    { 
        
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
  
         
        swap(&arr[min], &arr[i]); 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
   /* int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); */
    int size,i;
    printf("Enter the number of element:\n");
    scanf("%d",&size);
    int arr[size];
    printf("now enter your elements:\n");
    for(i = 0; i < size ; i++)
	{
		scanf("%d",&arr[i]);		
	}
    selectionSort(arr, size); 
    printf("Sorted array: \n"); 
    printArray(arr, size); 
    return 0; 
} 
