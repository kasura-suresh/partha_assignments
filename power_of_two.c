/*********************************************
 Program to check a number is power of teo oe not
 using bitwise operator 
 (Given by Suresh sir)
 Author-- Partha Pratim Dey
 
*********************************************/

#include<stdio.h>

void isPowerOfTwo(int num){
	if((num&(num-1))==0){
		printf("Holla..!its power of two");
	}
	else
		printf("Opps..!its not the power of two");
}
int main(){
	int number;
	printf("Enter the number:\n");
	scanf("%d",&number);
	isPowerOfTwo(number);
	return 0;
}
