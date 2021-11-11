#include <stdio.h>

//"分治"+递归 
//时间复杂度是O(NlogN) 
int MaxSum(int a[],int left,int right);
int Max(int a,int b,int c);
int main()
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	int result=MaxSum(a,0,7);
	printf("最大子序列和为:%d",result); 
}

int MaxSum(int a[],int left,int right)
{
	int LeftMaxSum=0,RightMaxSum=0;
	int LeftBorderSum=0,RightBorderSum=0;
	int LeftBorderMaxSum=0,RightBorderMaxSum=0;
	
	if(left==right)
	{
		if(a[left]>0)
		{
			return a[left];	
		}
		else
		{
			return 0;	
		}	
	}
	
	int center=(left+right)/2;
	//左侧递归
	LeftMaxSum=MaxSum(a,left,center);
	//右侧递归
	RightMaxSum=MaxSum(a,center+1,right);
	
	//跨越中间的两个最大和 
	//中间往左 
	for(int i=center;i>=left;i--)
	{
		LeftBorderSum+=a[i];
		if(LeftBorderSum>LeftBorderMaxSum)	
		{
			LeftBorderMaxSum=LeftBorderSum;	
		}	
	}
	//中间往右
	for(int i=center+1;i<=right;i++)
	{
		RightBorderSum+=a[i];
		if(RightBorderSum>RightBorderMaxSum)	
		{
			RightBorderMaxSum=RightBorderSum;	
		}	
	}	 
	
	
	return Max(LeftMaxSum,RightMaxSum,LeftBorderMaxSum+RightBorderMaxSum);	 
}


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

