/*************************************************

	program to implement bubble sort
	Author-- Partha Pratim Dey
	
*************************************************/

#include <stdio.h>

int main()
{
  int n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%d", &n);
  int arr[n];

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (arr[d] > arr[d+1]) 
      {
        swap       = arr[d];
        arr[d]   = arr[d+1];
        arr[d+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
     printf("%d\t", arr[c]);

  return 0;
}
