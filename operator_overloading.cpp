/*************************************************

	program to implement operator overloading
	Author-- Partha Pratim Dey
	
*************************************************/

#include <iostream>    
using namespace std;    
class A    
{       
   public:
   	    int num;     
        A(int n)
		{
			num = n;
		}   
        void operator ++() 
		{     
           num = num*2+5;     
        }    
       void Print() {     
           cout<<"The Count is: "<<num;     
       }    
};    
int main()    
{    
    int n;
    cout<<"Enter the number:\n";
    cin>>n;
    A obj(n);
    ++obj;
    obj.Print();
	    
    return 0;    
} 
