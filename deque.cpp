/*************************************************

	program to implement dqueue
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
	deque<int> de;
	de.push_back(30);
	de.push_front(50);
	de.push_back(60);
	de.push_front(70);
	for(auto i = de.begin();i!=de.end();i++)
	{
		cout<<*i<<" ";
	}
	de.pop_front();
	de.pop_back();
	cout<<"\nAfter doing pop:\n";
	for(auto i = de.begin();i!=de.end();i++)
	{
		cout<<*i<<" ";
	}
	return 0;
}
