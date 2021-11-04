#include <stdio.h>
#include <stdlib.h>


//方法一 
int main()
{
	printf("请输入总个数N\n");
	int N;
	scanf("%d",&N);
	int k=N/2;
	int a[N];
	
	
	//产生随机数进行测试
	for(int i=0;i<N;i++)
	{
		a[i]=rand();	
	} 
	
	
	
	//对N个数进行冒泡排序（降序）
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int term=a[j];
				a[j]=a[j+1];
				a[j+1]=term;
			}	
		}	
	}
	
	printf("产生的随机数排序之后:\n");
	for(int i=0;i<N;i++)
	{
		printf("%d\n",a[i]);	
	} 
	
	
	printf("N/2=%d,第%d大的数是%d\n",k,k,a[k-1]);
	
} 
