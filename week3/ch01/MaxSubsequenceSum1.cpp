#include <stdio.h>
 
 
//��ٷ�����������к� 
//O(N^3) 
int MaxSubsequenceSum1(int a[],int N);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum1(a,6);
	printf("��������к�Ϊ:%d",result);
}


int MaxSubsequenceSum1(int a[],int N)
{
	int MaxSum=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
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
