#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 400

int RandInt(int i,int j);

int main()
{
	int a[n];
	int used[n];
	
	//初始化used数组
	for(int i=0;i<n;i++)
	{
		used[i]=0;	
	} 
	
	//播种
	srand((unsigned)time(NULL)); 
	
	for(int i=0;i<n;i++)
	{
		int u=RandInt(1,n);
		while(used[u]==1)
		{
			u=RandInt(1,n);
		}
		a[i]=u;
		used[u]=1;
	}
	
	//随机序列
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}



//生成随机数
int RandInt(int i,int j)
{
	int x=j-i+1;
	int a=rand()%x+i;
	return a;	
} 
