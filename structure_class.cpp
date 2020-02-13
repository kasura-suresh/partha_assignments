#include <iostream>
using namespace std;
struct Person
{
    char name[50];
    int age;
    
};

class Dog
{
	public:
		char colour[10];
		
};
int main()
{
    Person p1;
    cout << "Enter Full name: ";
    cin.get(p1.name, 50);
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    
    Dog pet;
    cout<<"Enter the colour of the dog:\n";
    cin>>pet.colour;
    cout<<"color of the dog is:\n";
    cout<<pet.colour;
   
    return 0;
}
