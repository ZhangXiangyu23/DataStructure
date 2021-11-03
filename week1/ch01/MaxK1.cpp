#include <stdio.h>

int main()
{
	int a[5]={0,-5,3,6,2};
	//冒泡排序（递减）
	for(int i=1;i<5;i++)
	{
		for(int j=0;j<5-i;j++)
		{
			if(a[j+1]>a[j])	
			{
				int term=a[j];
				a[j]=a[j+1];
				a[j+1]=term;
			}
		}	
	}
	
	int k;
	printf("请输入k\n");
	scanf("%d",&k);
	printf("第%d大的数是:%d\n",k,a[k-1]);
}
