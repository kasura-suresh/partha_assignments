/*********************************************
 Program to check the sizeof the structure and it
 is vary
 (Given by Suresh sir)
 Author-- Partha Pratim Dey
 
*********************************************/
#include<stdio.h>
struct node1{
	short s1;
	short s2;
	char c1;
};
struct node2{
	short s1;
	char c1;
	short s2;
};

int main()
{
	struct node1 n1;
	struct node2 n2;
	
	printf("size of struct1 is:%d\n",sizeof(n1));
	printf("size of struct2 is:%d",sizeof(n2));
	return 0;
}
