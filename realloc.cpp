#include<iostream>
using namespace std;
int main()
{
	int *ptr = NULL;
	int i =0;
	ptr = (int *)malloc(sizeof(int));
	*ptr = 5;
	cout<<*ptr<<"\n"; 
    ptr = (int *) realloc(ptr, sizeof(int)*5);
   	for (i = 1; i < 5; i++) 
	{
		ptr[i] = i;
	}
   	for (i = 1; i < 5; i++) 
	{
		cout<<ptr[i]<<"\n";
	}
	free(ptr);

	return 0;
}

