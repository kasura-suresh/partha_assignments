/*************************************************

	program to implement new and delete key word
	Author-- Partha Pratim Dey
	
*************************************************/

#include <iostream>
#include<stdlib.h>
using namespace std;
int main () 
{
   int *ptr1  = NULL; 
   ptr1 = new int; 
   float *ptr2 = new float(29.11);
   int *ptr3 = new int[10];
   *ptr1 = 8; 
   cout << "Value of pointer variable 1 : " << *ptr1 << endl;
   cout << "Value of pointer variable 2 : " << *ptr2 << endl;
   if (!ptr3) 
      cout << "Allocation of memory failed\n"; 
   else 
   { 
      	for (int i = 0; i < 10; i++) 
         	ptr3[i] = i+1; 
      	cout << "Value of store in block of memory: "; 
      	for (int i = 0; i < 10; i++) 
         	cout << ptr3[i] << " "; 
   } 
   delete ptr1;
   delete ptr2;
   delete[] ptr3;
   return 0;
}
