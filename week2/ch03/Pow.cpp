#include <stdio.h>

int Pow(int x,int n);
bool IsEven(int y);
int main()
{
	int result=Pow(2,5);
	printf("���Ϊ:%d\n",result);
}

//�ݹ� 
int Pow(int x,int n)
{
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

//�ж��Ƿ���ż�� 
bool IsEven(int y)
{
	if(y%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
