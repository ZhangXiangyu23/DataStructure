#include <stdio.h>

int MaxSubsequenceSum4(int a[],int N);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum4(a,6);
	printf("最大子序列和为:%d",result);	
}

//联机算法，线性时间复杂度,O(N)
int MaxSubsequenceSum4(int a[],int N)
{
	int ThisSum=0;
	int MaxSum=0;
	for(int i=0;i<N;i++)
	{
		ThisSum+=a[i];
		if(ThisSum>0)
		{
			if(ThisSum>MaxSum)
			{
				MaxSum=ThisSum;
			}
		}
		else
		{
			ThisSum=0;
		}
	}
	return MaxSum;
}
