/*****************************************************************
	Program to implement pairs
	Author -- Partha Pratim Dey
	Date -- 12/03/2020
	
******************************************************************/

#include<iostream>
#include<utility>
using namespace std;

int main(){
	pair<int,int> pair1;
	pair<int,int> pair2;
	
	pair1.first = 12;
	pair1.second = 23;
	
	pair2.first = 10;
	pair2.second = 52;
	
	cout <<"Before swapping:\n " ; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "Contents of pair2 = " << pair2.first << " " << pair2.second ;
    
    pair1.swap(pair2);
    
    cout <<endl<<"After swapping:\n " ; 
    cout << "Contents of pair1 = " << pair1.first << " " << pair1.second ; 
    cout << "Contents of pair2 = " << pair2.first << " " << pair2.second ;
	return 0;
}
