/*************************************************
	program to implement copy constructor
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
using namespace std;
class A
{
	public:
		int i;
		A(int a)
		{
			i = a;
		}
		A(A &j)
		{
			i = j.i;
		}
};

int main()
{
	A obj1(15);
	cout<<"value of obj1:"<<obj1.i<<"\n";
	A obj2(obj1);
	cout<<"after applying copy constuctor:\n";
	cout<<"Value of obj2:"<<obj2.i;
	return 0;
}
