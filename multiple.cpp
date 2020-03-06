/*************************************************

	program to implement multiple inheritance
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;

class A
{
	public:
		int a = 10;
};
class B
{
	public:
		int b = 20;
};
class C:public A, public B
{
	public:
		int c = a+b;
};

int main()
{
	C obj;
	cout<<"Value is:"<<obj.c<<"\n";
	return 0;
}
