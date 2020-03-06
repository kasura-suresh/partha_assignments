/*************************************************
	program to implement deep copy
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
using namespace std;

class Base
{
	int a,b,*p;
	public:
		Base()
		{
			p = new int;
		}
		void setData(int x,int y,int z)
		{
			a = x;
			b = y;
			*p = z;
		}
		Base(Base &obj)
		{
			a = obj.a;
			b = obj.b;
			p = new int;
			*p = *(obj.p);
		}
		void show()
		{
			cout<<"Value of a:"<<a<<"\n";
			cout<<"Value of b:"<<b<<"\n";
			cout<<"Value of p:"<<*p<<"\n\n\n";
		}
};

int main()
{
	Base obj1;
	obj1.setData(1,2,3);
	obj1.show();
	cout<<"After Deep Copy:"<<"\n";
	Base obj2(obj1);
	obj2.show();
	
	return 0;
}
