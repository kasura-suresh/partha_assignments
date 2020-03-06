/*************************************************

	program to implement map (STL)
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> m1;
	m1.insert(pair<int,int>(1,45));
	m1.insert(pair<int,int>(2,35));
	m1.insert(pair<int,int>(3,98));
	m1.insert(pair<int,int>(4,4));
	cout<<"Keys and the values of map1:\n";
	for(auto i = m1.begin();i!=m1.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	map<int,int> m2(m1.begin(),m1.end());
	cout<<"\nAfter copying from map 1 key and values are:\n";
	for(auto i = m2.begin();i!=m2.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	cout<<"\nErase the value with key value 4:\n";
	m2.erase(4);
	for(auto i = m2.begin();i!=m2.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	return 0;
}
