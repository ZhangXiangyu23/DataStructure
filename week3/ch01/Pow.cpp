#include <stdio.h>

int Pow(int x,int n);
bool IsEven(int N);
int main()
{
	printf("2��6������%d\n",Pow(2,6));	
}

//���õݹ�
int Pow(int x,int n)
{
	//��׼������ݹ���� 
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

