#include <stdio.h>

int BinarySearch(int a[],int low,int high,int x);
int main()
{
	int a[6]={1,3,5,8,10,12};
	int index= BinarySearch(a,0,5,100);
	printf("�������е��±�Ϊ:%d",index);
	
	
} 

//low�����  high�ҽ��� 
int BinarySearch(int a[],int low,int high,int x)
{
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x)
		{
			return mid;
		}
		if(x>a[mid])
		{
			low=mid+1;	
		}
		else
		{
			high=mid-1;
		}	
	}
	return -1;//û���ҵ� 
}
