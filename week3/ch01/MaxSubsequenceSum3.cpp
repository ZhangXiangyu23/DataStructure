#include <stdio.h>

int MaxSubsequenceSum3(int a[],int left,int right);
int Max(int a,int b,int c);
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int result=MaxSubsequenceSum3(a,0,5);
	printf("��������к�Ϊ:%d",result);		
}


//���η�O(NlogN) 
int MaxSubsequenceSum3(int a[],int left,int right)
{
	//��׼������˵�еݹ���� 
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
	//������࣬���� 
	int LeftMax=MaxSubsequenceSum3(a,left,center);
	//�����Ҳ࣬���� 
	int RightMax=MaxSubsequenceSum3(a,center+1,right);
	
	//��Խ�м�����ڵ�������
	//������
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
	
	//������
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

//���������е����ֵ 
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
