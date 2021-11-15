#include <stdio.h>

int MaxSubsequenceSum3(int a[],int left,int right);
int Max(int a,int b,int c);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum3(a,0,5);
	printf("最大子序列和为:%d",result);		
}


//分治法O(NlogN) 
int MaxSubsequenceSum3(int a[],int left,int right)
{
	//基准，或者说叫递归出口 
	if(left==right)
	{
		if(a[right]>0)
		{
			return a[right];
		}
		else
		{
			return 0;
		}
	}
	
	int center=(left+right)/2;
	//纯在左侧，最大的 
	int LeftMax=MaxSubsequenceSum3(a,left,center);
	//纯在右侧，最大的 
	int RightMax=MaxSubsequenceSum3(a,center+1,right);
	
	//跨越中间而存在的子序列
	//往左走
	int LeftBroadSum=0;
	int LeftBroadMaxSum=0;
	int RightBroadSum=0;
	int RightBroadMaxSum=0;
	
	for(int i=center;i>=left;i--)
	{
		LeftBroadSum+=a[i];
		if(LeftBroadSum>LeftBroadMaxSum)
		{
			LeftBroadMaxSum=LeftBroadSum;	
		}	
	}
	
	//往右走
	for(int i=center+1;i<right;i++)
	{
		RightBroadSum+=a[i];
		if(RightBroadSum>RightBroadMaxSum)
		{
			RightBroadMaxSum=RightBroadSum;	
		}		
	}
	
	return Max(LeftMax,RightMax,LeftBroadMaxSum+RightBroadMaxSum); 
	
}

//求三个数中的最大值 
int Max(int a,int b,int c)
{
	int max=a;
	if(b>a)
	{
		max=b;
		if(c>b)
		{
			max=c;	
		}	
	}
	else
	{
		if(c>a)
		{
			max=c;	
		}	
	}
	return max; 
}
