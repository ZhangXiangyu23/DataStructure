#include <stdio.h>

int main()
{
	printf("������һ����:\n");
	int x;
	scanf("%d",&x);
	int count=0;
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			count++; 
			printf("%d��������!\n",x);
			break;	
		}	
	}
	
	if(count==0)
	{
		printf("%d������!\n",x);	
	}
	return 0; 
		
} 
