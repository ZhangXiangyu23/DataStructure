#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int RandInt(int i,int j);
bool judge(int a[],int y,int u);
int main()
{
	//播种 
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
	
	//最后产生的序列
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);	
	} 
}

//判断
//y是界限 
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


//产生随机数
int RandInt(int i,int j)
{
	int x=j-i+1;
	int a=rand()%x+1;
	return a;	
} 
