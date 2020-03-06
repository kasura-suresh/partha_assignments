/*************************************************

	program to implement virtual destructor
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout<<"Base constructed"<<"\n";
		}
		virtual ~Base()
		{
			cout<<"Base Destroied"<<"\n";
		}
};
class child : public Base
{
	public:
	child()
	{
		cout<<"child constructed"<<"\n";
	}
	~child()
	{
		cout<<"child Destroied"<<"\n";
	}
};

int main()
{
	child *c = new child();
	Base *b = c;
	delete b;
	return 0;
}
