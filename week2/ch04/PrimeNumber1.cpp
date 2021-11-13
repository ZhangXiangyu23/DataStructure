#include <stdio.h>

int main()
{
	printf("请输入一个数:\n");
	int x;
	scanf("%d",&x);
	int count=0;
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			count++; 
			printf("%d不是素数!\n",x);
			break;	
		}	
	}
	
	if(count==0)
	{
		printf("%d是素数!\n",x);	
	}
	return 0; 
		
} 
