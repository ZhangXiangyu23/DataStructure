#include <stdio.h>

int BinarySearch(int a[],int left,int right,int x);
int main()
{
	int a[6]={1,3,8,12,13,36};
	int index=BinarySearch(a,0,5,12);
	printf("下标是%d",index);		
}


int BinarySearch(int a[],int left,int right,int x)
{
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x)
		{
			return mid;
		}
		if(x<a[mid])
		{
			right=mid-1;
		}
		if(x>a[mid])
		{
			left=mid+1;
		}
	}
	
	return -1;//没找到 
}
