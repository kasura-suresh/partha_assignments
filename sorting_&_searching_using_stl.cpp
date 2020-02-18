#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[] = {5,6,7,1,2,45},i;
	cout<<"\nArray Before sorting:\n";
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		cout<<a[i]<<"\t";
	}
	sort(a,a+(sizeof(a)/sizeof(a[0])));
	cout<<"\nArray Before sorting:\n";
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		cout<<a[i]<<"\t";
	}
	int search;
	cout<<"\nEnter the element for search:\n";
	cin>>search;
	if(binary_search(a,a+(sizeof(a)/sizeof(a[0])),search))
	{
		cout<<"Element is present\n";
	}
	else
	{
		cout<<"Element is not present\n";
	}
	return 0;
}
