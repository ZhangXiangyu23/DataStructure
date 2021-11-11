#include <stdio.h>

//欧几里得算法 
int Gcd(int a,int b);
int main()
{
	printf("最大公约数为:%d",Gcd(45,35));	
} 

int Gcd(int a,int b)
{
	while(b>0)
	{
		int n=a%b;
		a=b;
		b=n;	
	}
	return a;		
} 
