#include <stdio.h>

//ʱ�临�Ӷ���O(N^1/2) 
bool IsPrime(int N);
int main()
{
	printf("������һ������:\n");
	int N;
	scanf("%d",&N);
	if(IsPrime(N))
	{
		printf("%d������!\n",N);	
	}
	else
	{
		printf("%d��������!\n",N);	
	}	
} 

//�ж��Ƿ�����
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
