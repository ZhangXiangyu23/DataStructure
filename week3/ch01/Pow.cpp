#include <stdio.h>

int Pow(int x,int n);
bool IsEven(int N);
int main()
{
	printf("2的6次幂是%d\n",Pow(2,6));	
}

//利用递归
int Pow(int x,int n)
{
	//基准情况，递归出口 
	if(n==0)
	{
		return 1;	
	}	
	if(n==1)
	{
		return x;
	}
	
	if(IsEven(n))
	{
		return Pow(x*x,n/2);
	} 
	else
	{
		return Pow(x*x,n/2)*x;	
	} 
	
	
} 


bool IsEven(int N)
{
	if(N%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

