/*************************************************
	program to swap two different array
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
using namespace std;
int main()
{
	int *array1,*array2,t,i,n;
	cout << "Enter the number of elements : ";
	cin>>n;
	array1=new int[n];
	array2=new int[n];
	cout << "Enter the elements in the first array : ";
	for(i=0;i<n;i++) {
		cin>>array1[i];
	}
	cout << "Enter the elements in the second array : ";
	for(i=0;i<n;i++) {
		cin>>array2[i];
		t=array2[i];
		array2[i]=array1[i];
		array1[i]=t;
	}
	cout << "Elements in the first array are : ";
	for(i=0;i<n;i++) {
		cout << array1[i] << " ";
	}
	cout << endl;
	cout << "Elements in the second array are : ";
	for(i=0;i<n;i++) {
		cout << array2[i] << " ";
	}
	cout << endl;
}
