/*******************************************************
	Program to know the besic concept of dataType
	(Given by Suresh sir)
	Author--Partha Pratim Dey
************************************************************/  
#include<stdio.h>
int main()
{
//---signed Data Types----
    int i = -5;
	float f = -6.3;
	double d = -6.33;
	char k = 'a';
	long l = -78945612;
//---Unsigned Data Types--
	unsigned int usi = 56;
	unsigned long int usli = 789456;
	unsigned long long int uslli = 7945612369874;

//---Printing the values-----	
	printf("Integer value:%d\n",i);
	printf("Float value:%f\n",f);
	printf("Double value:%lf\n",d);
	printf("Char value:%c\n",k);
	printf("Long value:%ld\n",l);

	printf("Unsigned Integer value:%u\n",usi);
	printf("Unsigned Long Int value:%lu\n",usli);
	printf("Unsigned Long Long Int value:%llu\n",uslli);
	return 0;
}
