/*************************************************

	program to implement function pointer
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
using namespace std;
int show_multiple(int x,int y){
	int result;
	result = x*y;
	//printf("result is:%d",result);
	return result;
}

int main(){
	int (*fun)(int,int),result;
	fun = &show_multiple;
	result =    fun(2,30);
	cout<<"Result is: "<<result;
	return 0;
}
