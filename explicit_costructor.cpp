/*************************************************

	program to implement explicit constructor
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;

class Base
{
	int a;
	public:
		explicit Base(int var)
		{
			a = var;
		}
		void print()
		{
			cout<<"value is:"<<a<<"\n";
		}
};

int main()
{
	Base obj1(100);
	obj1.print();
	
	return 0;
}
