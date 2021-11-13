#include <stdio.h>


//时间复杂度O(N) 
int main()
{
	printf("请输入一个数:\n");
	int N;
	scanf("%d",&N);
	int count=0;
	for(int i=2;i<N;i++)
	{
		if(N%i==0)
		{
			count++; 
			printf("%d不是素数!\n",N);
			break;	
		}	
	}
	
	if(count==0)
	{
		printf("%d是素数!\n",N);	
	}
	return 0; 
		
} 
