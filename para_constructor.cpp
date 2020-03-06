/*************************************************

	program to implement parameterized constructor
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;
class A
{
	public:
		int result;
		A(int a, int b)
		{
			result = a+b;
			cout<<"Sum of the number:"<<result<<"\n";
		}
};

int main()
{
	int num1,num2;
	cout<<"Enter two number:"<<"\n";
	cin>>num1>>num2;
	A obj(num1,num2);
	
	return 0;
}
