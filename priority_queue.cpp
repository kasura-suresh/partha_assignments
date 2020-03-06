/*************************************************

	program to implement priprity queue
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<queue>

using namespace std;
int main()
{
	priority_queue<int> pq;
	pq.push(45);
	pq.push(25);
	pq.push(12);
	pq.push(63);
	pq.push(89);
	cout<<"size of the priority queue:"<<pq.size()<<endl;
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	

	return 0;
}
