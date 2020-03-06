/*************************************************

	program to implement ostream operator
	Author-- Partha Pratim Dey
	
*************************************************/

#include <iostream> 
using namespace std; 
  
int main() 
{ 
    char opp;
    cout<<"insert \"h\" to say hii"<<"\n";
    cout<<"insert \"b\" to say bye"<<"\n";
    cin.get(opp);
    
	switch(opp)
	{
		case 'h':
			cout<<"Hi User"<<"\n";
			break;
		case 'b':
			cout<<"Bye User"<<"\n";
			break;
		default:
			cout<<"please make a perfect choice"<<"\n";
			break;
	}
    
	return 0;
} 
