#include <stdio.h>

int MaxSubsequenceSum2(int a[],int N);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum2(a,6);
	printf("最大子序列和为:%d",result);	
}

//对穷举法进行优化
//时间复杂度是O(N^2) 
int MaxSubsequenceSum2(int a[],int N)
{
	int MaxSum=0;
	for(int i=0;i<N;i++)
	{
		int ThisSum=0;
		for(int j=i;j<N;j++)
		{
			ThisSum+=a[j];
			if(ThisSum>MaxSum)
			{
				MaxSum=ThisSum;
			}
		}
		
	}
	return MaxSum;
}


