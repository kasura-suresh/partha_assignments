/*************************************************

	program to implement set in STL
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> st;
	st.insert(20);
	st.insert(30);
	st.insert(45);
	st.insert(65);
	cout<<"Avlues of set1:\n";
	for(auto i = st.begin();i!=st.end();i++)
	{
		cout<<*i<<"\n";
	}
	cout<<"Values of set2;\n";
	set<int> st2(st.begin(),st.end());
	for(auto i = st2.begin();i!=st2.end();i++)
	{
		cout<<*i<<"\n";
	}
	st.erase(30);
	cout<<"After erase 30 from set 1:"<<"\n";
	for(auto i = st.begin();i!=st.end();i++)
	{
		cout<<*i<<"\n";
	}
	return 0;
}
