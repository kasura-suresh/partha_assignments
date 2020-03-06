/*************************************************

	program to implement valarray in STL
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<valarray>
#include<algorithm>
using namespace std;
int main()
{
	valarray<int> val = {1,2,3,4};
	valarray<int> val1;
	
	val1 = val.apply([](int x)
	{
		return x+2;	
	});
	cout<<"After changing the value:\n";
	for (int &x: val1) cout << x << " "; 
    cout << endl;
     cout << "The sum of old valarray is : "; 
    cout << val.sum() << endl; 
    cout << "The sum of new valarray is : "; 
    cout << val1.sum() << endl;
	cout<<"Largest element of valarray:\n";
	cout<<val1.max()<<"\n";
	cout<<"Minimum element of valarray:\n";
	cout<<val1.min()<<"\n";
	cout<<"Before swap:\n";
	for(int &x: val)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	for(int &x: val1)
		cout<<x<<" ";
	val.swap(val1);	
	cout<<"\nAfter swap:\n";
	for(int &x: val)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	for(int &x: val1)
		cout<<x<<" ";
	valarray<int> val2;
	valarray<int> val3;
    val2 = val.shift(2);
    val3 = val1.cshift(3);
    cout<<"\nafter shift\n";
    for(int &x: val2)
	{
		cout<<x<<" ";
	}
	cout<<"\nafter cshift\n";
    for(int &x: val3)
	{
		cout<<x<<" ";
	}
	 return 0;
    
}
