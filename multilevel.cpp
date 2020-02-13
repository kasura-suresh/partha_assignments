#include<iostream>
using namespace std;

class Animal
{
	public:
		void eat()
		{
			cout<<"Eating..!"<<"\n";
		}
};

class Cat:public Animal
{
	public:
		void play()
		{
			cout<<"Playing"<<"\n";
		}
};

class BabyCat:public Cat
{
	public:
		void sleep()
		{
			cout<<"Sleeping"<<"\n";
		}
};

int main()
{
	BabyCat obj;
	obj.sleep();
	obj.play();
	obj.eat();
	return 0;
}

