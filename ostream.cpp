/*************************************************

	program to implement ostream operator
	Author-- Partha Pratim Dey
	
*************************************************/

#include <iostream>
using namespace std;
class Test{
	int x,y;
	public:
		int z;
		friend void operator >> (Test& t, istream& tin){
			tin >> t.x >> t.y >> t.z;
		}
		friend void operator << (Test& t, ostream& tout){
			tout<< "Ostream and Istream is working and the values are:\n"<<endl;
			tout<< t.x <<" "<<t.y<<" "<<t.z <<endl;
		}
};  
  
int main() 
{ 
  Test t;
  cout<<"Enter the value of x and y:\n";
  t >> cin;
  t << cout;
  return 0;   
} 
