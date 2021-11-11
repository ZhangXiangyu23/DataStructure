#include <stdio.h>

/*
穷举法 
时间复杂度是O(N^3) 
*/
int MaxSubsequenceSum(int a[],int n);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum(a,6);
	printf("最大子序列和为:%d\n",result);	
} 

int MaxSubsequenceSum(int a[],int n)
{
	int MaxSum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int ThisSum=0;
			for(int k=i;k<=j;k++)
			{
				ThisSum+=a[k];
			}
			if(ThisSum>MaxSum)
			{
				MaxSum=ThisSum;
			}
		}	
	}
	return MaxSum;
}
