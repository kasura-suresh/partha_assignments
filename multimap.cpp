#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> ml1;
	ml1.insert(pair<int,int>(1,45));
	ml1.insert(pair<int,int>(2,35));
	ml1.insert(pair<int,int>(3,98));
	ml1.insert(pair<int,int>(4,4));
	cout<<"Keys and the values of multimap1:\n";
	for(auto i = ml1.begin();i!=ml1.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	map<int,int> ml2(ml1.begin(),ml1.end());
	cout<<"\nAfter copying from multimap 1 key and values are:\n";
	for(auto i = ml2.begin();i!=ml2.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	cout<<"\nErase the value with key value 4 and 2:\n";
	ml2.erase(4);
	ml2.erase(2);
	for(auto i = ml2.begin();i!=ml2.end();i++)
	{
		cout<<i->first<<"-->"<<i->second<<endl;
	}
	return 0;
}
