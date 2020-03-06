/*************************************************

	program to implement queue using STL
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	int i;
	queue<int> q;
	for(i=1;i<=10;i++)
	{
		q.push(i);
	}
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
