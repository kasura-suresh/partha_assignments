#include<iostream> 
#include<forward_list>  
using namespace std;

int main()
{
	forward_list<int> fl;
	fl.assign({1, 2, 3});
	for(int&x: fl)
	{
		cout<<x<<" ";	
	}
	fl.push_front(56);
	fl.push_front(63);
	cout<<"\n after push_fornt function:\n";
	for(int&x: fl)
	{
		cout<<x<<" ";	
	}
	fl.pop_front();
	fl.pop_front();
	cout<<"\n after pop_frony function:\n";
	for(int&x: fl)
	{
		cout<<x<<" ";	
	}
	return 0;
}
