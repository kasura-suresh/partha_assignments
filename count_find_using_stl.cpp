/*************************************************
	program to use count and find function in stl
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int i,nmbr;
	vector<int> v;
	for(i=1;i<=10;i++)
	{
		v.push_back(i);
	}
	cout<<"enter the number you want to count and find the position:\n";
	cin>>nmbr;
	cout<<count(v.begin(),v.end(),nmbr)<<" time\n";
	vector<int>::iterator p;
	p = find(v.begin(),v.end(),nmbr);
	cout<<nmbr<<" found at position:"<<p-v.begin()+1; 
	return 0;
}
