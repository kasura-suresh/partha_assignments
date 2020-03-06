/*************************************************
	program to implememnt class inheritance
	Author-- Partha Pratim Dey
*************************************************/

#include<iostream>
using namespace std;
class Animal
{
	public:
	void description()
	{
		cout<<"Dog is also an animal";
	}
};

class Dog : public Animal
{
	public:
		char colour[10];
		
};
int main()
{
    Dog pet;
    cout<<"Enter the colour of the dog:\n";
    cin>>pet.colour;
    cout<<"color of the dog is:\n";
    cout<<pet.colour<<"\n";
    pet.description();
   
    return 0;
}

