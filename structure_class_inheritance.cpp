/*************************************************

	program to implement structure and class inheritance
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

class A{
	public:
		int i;
		struct structure{
		int a;
		int b;
	};
	structure s1;
};
class B:public A{
	public:
		B(){
			cout<<"Default Construcor called\n";
		}
};
int main(){
	B obj;
	cout<<"Enter the value of i(instance variaable):\n"<<endl;
	cin>>obj.i;
	cout<<"Enter the value of a(variaable inside a structure):\n"<<endl;
	cin>>obj.s1.a;
	cout<<"Value of i:"<<obj.i<<"\n";
	cout<<"Value of a:"<<obj.s1.a;
	return 0;
}
