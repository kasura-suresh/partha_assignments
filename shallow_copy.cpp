/*************************************************

	program to implement shallow_copy()
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;
class Base
{
	int a,b;
	public:
		void setData(int x,int y)
		{
			a = x;
			b = y;
		}
		void show()
		{
			cout<<"value of a:"<<a<<"\n";
			cout<<"value of b:"<<b<<"\n";
		}
};

int main()
{
	Base ob1;
	ob1.setData(5,6);
	Base ob2 = ob1;
	cout<<"After shallow copy:"<<"\n";
	ob2.show();
	return 0;
}
