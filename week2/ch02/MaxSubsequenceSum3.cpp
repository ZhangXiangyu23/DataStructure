#include <stdio.h>

//"����"+�ݹ� 
//ʱ�临�Ӷ���O(NlogN) 
int MaxSum(int a[],int left,int right);
int Max(int a,int b,int c);
int main()
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	int result=MaxSum(a,0,7);
	printf("��������к�Ϊ:%d",result); 
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
	//���ݹ�
	LeftMaxSum=MaxSum(a,left,center);
	//�Ҳ�ݹ�
	RightMaxSum=MaxSum(a,center+1,right);
	
	//��Խ�м���������� 
	//�м����� 
	for(int i=center;i>=left;i--)
	{
		LeftBorderSum+=a[i];
		if(LeftBorderSum>LeftBorderMaxSum)	
		{
			LeftBorderMaxSum=LeftBorderSum;	
		}	
	}
	//�м�����
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

