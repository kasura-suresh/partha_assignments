/*************************************************

	program to implement object slicing
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;

class Base
{
	int a,b;
	public:
		Base()
		{
			a = 0;
			b = 0;
		}
		Base(int x,int y)
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
class Child:public Base
{
	int c;
	public:
	Child(int x,int y,int z):Base(x,y)
	{
		c = z;
	}
	void dispaly()
	{
		show();
		cout<<"Value of C:"<<c<<"\n";
	}
};

int main()
{
	Child ob1(12,24,36);
	Base ob2;
	ob2.show();
	ob2 = ob1;
	ob2.show();
	
	return 0;
}
