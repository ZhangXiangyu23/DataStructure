#include <stdio.h>

//ŷ������㷨 
int Gcd(int a,int b);
int main()
{
	printf("���Լ��Ϊ:%d",Gcd(45,35));	
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
