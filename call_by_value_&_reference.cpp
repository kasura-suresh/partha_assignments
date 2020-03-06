/***********************************************************
	program to implement call by value and call by reference
	Author-- Partha Pratim Dey
*************************************************************/

#include<iostream>
using namespace std;

void swap(int num1,int num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout<<num1<<" "<<num2<<endl;
}

void swap_ref(int &num1,int &num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
int main(){
	int num1,num2;
	cout<<"Enter the numbers:\n";
	cin>>num1>>num2;
	cout<<"After call by value:\n";
	swap(num1,num2);
	cout<<"After call by reference:\n";
	swap_ref(num1,num2);
	cout<<num1<<" "<<num2;
	return 0;
}
