#include<iostream>
using namespace std;

class A
{
	public:
		virtual void show()
		{
			cout<<"Base Class called"<<"\n";
		}
};
class B:public A
{
	public:
		void show()
		{
			cout<<"Derived Class called"<<"\n";
		}
};
int main()
{
	A *a;
	B b;
	a = &b;
	a->show();
	return 0;
}
