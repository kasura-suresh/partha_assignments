#include<iostream>
using namespace std;

class Singleton
{
	static Singleton *instance;
	int data;
	Singleton()
	{
		cout<<"objected created"<<"\n";
	}
	public:
		static Singleton *Instance()
		{
			if (instance == NULL) 
            	instance = new Singleton(); 
            return instance;
		}
		
		void setData(int value)
		{
			data  = value;
		}
		int GetValue()
		{
			return data;
		}
		
};

Singleton *Singleton::instance = NULL;

int main()
{
	int number;
	cout<<"enter the number:\n";
	cin>>number;
	Singleton::Instance()->setData(number);
	cout<<"Value of the data:"<<Singleton::Instance()->GetValue()<<"\n";
	return 0;
}
