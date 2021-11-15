#include <stdio.h>

int Gcd(int a,int b);
int main()
{
	printf("45和35的最大公因数是%d\n",Gcd(35,45)); 
}

int Gcd(int a,int b)
{
	int n;
	while(b>0)
	{
		n=a%b;
		a=b;
		b=n;	
	}	
	return a;
}
