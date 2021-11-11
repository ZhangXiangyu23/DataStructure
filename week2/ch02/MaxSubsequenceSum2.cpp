#include <stdio.h>

/*
算法二：优化一个for循环，对穷举法进行改进
时间复杂度是:O(N^2) 
*/
int MaxSubsequenceSum(int a[],int n);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum(a,6);
	printf("最大子序列和为:%d",result);
		
}

int MaxSubsequenceSum(int a[],int n)
{
	int MaxSum=0;
	for(int i=0;i<n;i++)
	{
		int ThisSum=0;
		for(int j=i;j<n;j++)
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
