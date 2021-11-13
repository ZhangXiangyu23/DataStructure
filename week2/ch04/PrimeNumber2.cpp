#include <stdio.h>

//时间复杂度是O(N^1/2) 
bool IsPrime(int N);
int main()
{
	printf("请输入一个整数:\n");
	int N;
	scanf("%d",&N);
	if(IsPrime(N))
	{
		printf("%d是素数!\n",N);	
	}
	else
	{
		printf("%d不是素数!\n",N);	
	}	
} 

//判断是否素数
bool IsPrime(int N)
{
	if(N==1)
	{
		return false;	
	}
	if(N==2)
	{
		return true;	
	}
	if(N%2==0)
	{
		return false;	
	}	
	
	for(int i=3;i*i<=N;i+=2)
	{
		if(N%i==0)
		{
			return false;
		}
	}
	return true;
} 
