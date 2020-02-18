#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int i;
	vector<int> v1;
	for(i=1;i<=10;i++)
	{
		v1.push_back(i);
	}
	cout<<"Reverse of the vector is:\n";
	reverse(v1.begin(),v1.end());
	for(auto i=v1.begin();i!=v1.end();i++)
	{
		cout<<*i<<"\t";
	}
	cout<<"\nAfter using accumulate:\n";
	cout<<accumulate(v1.begin(),v1.end(),0);
	cout<<"\nMax element:\n";
	cout<<*max_element(v1.begin(),v1.end());
	cout<<"\nMin element:\n";
	cout<<*min_element(v1.begin(),v1.end());		
	return 0;	
}


