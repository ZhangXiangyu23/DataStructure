#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int RandInt(int i,int j);
bool judge(int a[],int y,int u);
int main()
{
	//���� 
	srand((unsigned)time(NULL));
	int a[n];
	for(int i=0;i<n;i++)
	{
		int u=RandInt(1,n);
		while(judge(a,i,u))
		{
			u=RandInt(1,n);	
		}
		a[i]=u;	
	} 
	
	//������������
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);	
	} 
}

//�ж�
//y�ǽ��� 
bool judge(int a[],int y,int u)
{
	for(int i=0;i<y;i++)
	{
		if(a[i]==u)
		{
			return true;	
		}	
	}
	return false;	
} 


//���������
int RandInt(int i,int j)
{
	int x=j-i+1;
	int a=rand()%x+1;
	return a;	
} 
