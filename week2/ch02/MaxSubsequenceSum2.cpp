#include <stdio.h>

/*
�㷨�����Ż�һ��forѭ��������ٷ����иĽ�
ʱ�临�Ӷ���:O(N^2) 
*/
int MaxSubsequenceSum(int a[],int n);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum(a,6);
	printf("��������к�Ϊ:%d",result);
		
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
