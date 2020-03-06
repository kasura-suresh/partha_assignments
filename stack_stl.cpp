/*************************************************

	program to implement stack using STL
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	st.push(12);
	st.push(45);
	st.push(52);
	st.push(63);
	st.push(78);
	st.push(99);
	cout<<"Size of the stack:"<<st.size()<<endl;
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
