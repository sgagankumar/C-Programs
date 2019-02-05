/* Consider the series of numbers 1,2,1,3,2,5,3,7,5,11,8,13,13,17..... 
In this series the odd position numbers form fibonacci series and even position numbers form prime numbers.
Given 'n' a +ve number print the nth element in the series */

#include<stdio.h>
#include<conio.h>
// FUNCTION TO GENERATE Nth FIBONACCI SERIES
void fib(int n)
{
	int a=0;
	int b=1;
	int i;
	int temp;
	for(i=0;i<n;i++)
	{
		temp=b;
		b=a+b;
		a=temp;
	}  
	printf("%d ",a);
}
// FUNCTION	TO CHECK FOR PRIME
int prim(int n)
{
	int a=0;
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
// FUNCTION TO GENERATE Nth PRIME
void primgen(int n)
{
	int x=1;
	int i=2;
	while(x<=n)
	{
		if(prim(i))
		{
			//printf("%d",i);
			x++;
		}
		i++;
	}
	printf("%d ",--i);
}

void main()
{
	int no;
	printf("Enter N:");
	scanf("%d",&no);
	if(no%2==0)
	{
		primgen(no/2);
	}
	else
	{
		no=(no+1)/2;
		fib(no);
	}
}