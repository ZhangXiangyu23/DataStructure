#include <stdio.h>

int main()
{
	int k;
	printf("请输入k\n");
	scanf("%d",&k);
	int a[k];
	printf("请依次输入元素\n");
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
	}
	//选择排序（递减）
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(a[j]>a[i])
			{
				int term=a[j];
				a[j]=a[i];
				a[i]=term;	
			}	
		}	
	}
	
	
	
	printf("请继续读入数字，输入999表示结束\n");
	int e;
	scanf("%d",&e);
	int m=k-1;
	while(e!=999)
	{
		
		if(e<=a[m])
		{
			
		}
		else
		{
			int f=m;
			for(int j=m-1;j>=0;j--)
			{
				if(e>a[j])
				{
					f--;
				}
				else
				{
					break;
				}
			}
			
			//移动
			for(int i=m-1;i>=f;i--)
			{
				a[i+1]=a[i];	
			} 
			//元素e应该放置的位置 
			a[f]=e;
			
		}
		scanf("%d",&e);
	}
	
	printf("第%d大的数是%d",k,a[k-1]);
	
}
