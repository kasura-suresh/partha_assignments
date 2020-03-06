/*************************************************
	program to use calloc 
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
int main ()
{
  int i = 0;
  int * ptr = NULL;  
  ptr = (int*) calloc (5,sizeof(int));
  if (ptr == NULL)
  	{
	  cout<<"ERROR: memory allocatin fail\n";			
	  return 1;
  	}
  cout<<"By defaul, all values are: ";
  for (i = 0; i < 5; i++) 
  	{
	  cout<<ptr[i]<<"\t";
  	}
	cout<<"\n";
  for (i = 0; i < 5; i++) 
  	{
		ptr[i] = i;
	}
  cout<<"After entered values:";
  for (i = 0; i < 5; i++) {
	  cout<< ptr[i]<<"\t";
  }  
  free (ptr);

  return 0;
}
