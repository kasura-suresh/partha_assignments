/************************************************
	Simple Basic Calculator Using Switch Case
	Author-- Partha Pratim Dey
	
**************************************************/

#include<stdio.h>

void add(float i,float j)
{
	float r;
	r = i+j;
	printf("Result:%f\n",r);
	
}

void sub(float i,float j)
{
	float r;
	r = i-j;
	printf("Result:%f\n",r);
	
}

void mul(float i,float j)
{
	float r;
	r = i*j;
	printf("Result:%f\n",r);
	
}

void div(float i,float j)
{
	float r;
	if(j==0)
		printf("\n Error \n");
	else
	{
		r = i/j;
		printf("Result:%f\n",r);
	}
	
}

int main()
{
	while(1)
	{

			float num1,num2;
			int opp;
			
			printf("\n___Operations__\n");
			printf("\n1.ADD(+)\n");
			printf("\n2.SUB\n");
			printf("\n3.MULTIPLICATION\n");
			printf("\n4.DIVITION\n");
			printf("\n5.Exit\n");
			
			printf("Enter the operation number:\n");
			scanf("%d",&opp);
			
			switch(opp)
			{
				case 1:
						printf("Enter the numbers:\n");
						scanf("%f%f",&num1,&num2);
						add(num1,num2);
						break;
				case 2:
						printf("Enter the numbers:\n");
						scanf("%f%f",&num1,&num2);
						sub(num1,num2);
						break;
				case 3:
						printf("Enter the numbers:\n");
						scanf("%f%f",&num1,&num2);
						mul(num1,num2);
						break;
				case 4:
						printf("Enter the numbers:\n");
						scanf("%f%f",&num1,&num2);
						div(num1,num2);
						break;
					
				case 5:
						printf("\nHappy To See You Again\n");
						exit(0);
				default:
						printf("\nPlease make a right choice..\n");	
			}
	}
	
	return 0;
}
