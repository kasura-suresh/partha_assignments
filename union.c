/*********************************************
 Program to check the sizeof the union and it
 is vary
 (Given by Suresh sir)
 Author-- Partha Pratim Dey
 
*********************************************/

#include<stdio.h>
union node1{
	short s1;
	short s2;     /*Union variable will allocate common memory for all the union members*/
	char c1;
	int i1;
};
union node2{
	short s1;
	char c1;
	short s2;
};
int main(){
	union node1 n1;
	union node2 n2;
	printf("sizeof union1 is: %d\n",sizeof(n1));
	printf("sizeof union2 is: %d",sizeof(n2));
	return 0;
}
