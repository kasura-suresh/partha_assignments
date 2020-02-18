#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	list<int> li;
	li.push_back(30);
	li.push_front(40);
	li.push_back(45);
	li.push_front(62);
	for(auto i=li.begin();i!=li.end();i++)
	{
		cout<<*i<<" ";
	}
	li.pop_back();
	li.pop_front();
	cout<<"\nAfter pop back and pop front:\n";
	for(auto i=li.begin();i!=li.end();i++)
	{
		cout<<*i<<" ";
	}
	return 0;
}
