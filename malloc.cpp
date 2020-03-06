/*************************************************

	program to implement malloc() function
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *ptr = NULL;
	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)
	{
		cout<<"ERROR: memory allocatin fail\n";
		return 1;
	}
	*ptr = 5;
	 cout<<*ptr<<"\n";
	 free(ptr);
	 return 0;
}
