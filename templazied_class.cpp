/*************************************************

	program to implement templatized class
	Author-- Partha Pratim Dey
	
*************************************************/

  #include<iostream>
using namespace std;

template <class C>
class Calcu
{
	private:
		C num1,num2;
	public:
		Calcu(C n1,C n2)
		{
			num1 = n1;
			num2 = n2;
		}
	void display()
	{
		cout << "Add is: " << add() << endl;
		cout << "Sub is: " << subtract() << endl;
		cout << "Product is: " << multiply() << endl;
		cout << "Division is: " << divide() << endl;
	}
	
	C add()
	{
	 return num1 + num2; 
	}
	C subtract()
	{
	 return num1 - num2;
	}
	C multiply()
	{
	 return num1 * num2;
	}
	C divide()
	{ 
	 return num1 / num2;
	}
};

int main()
{
	Calcu<int> iCal(2,5);
	Calcu<float> fCal(6,5);
	cout<<"Result for interger:"<<"\n";
	iCal.display();
	cout<<"\n"<<"Result for float:"<<"\n";
	fCal.display();
	return 0;
}
