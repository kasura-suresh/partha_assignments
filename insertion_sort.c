/*************************************************

	program to implement insertion sort
	Author-- Partha Pratim Dey
	
*************************************************/

#include <stdio.h>
void insertionSort(int arr[], int size)
{
  int i,key,j;
  for ( i = 1; i < size; i++)
  {
     key = arr[i];
     j = i - 1;
    while (key < arr[j] && j >= 0)
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}
int main()
{

  
  int size,i;
  printf("Enter the number of element:\n");
  scanf("%d",&size);
  int data[size];
  printf("Now enter the element one by one:\n");
  for(i = 0;i <size ;i++)
  {
  	scanf("%d",&data[i]);
  }
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  for ( i = 0; i < size; i++)
  {
    printf("%d ", data[i]);
  }
  printf("\n");
}

