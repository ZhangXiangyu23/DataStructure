#include <stdio.h>


//ʱ�临�Ӷ�O(N) 
int main()
{
	printf("������һ����:\n");
	int N;
	scanf("%d",&N);
	int count=0;
	for(int i=2;i<N;i++)
	{
		if(N%i==0)
		{
			count++; 
			printf("%d��������!\n",N);
			break;	
		}	
	}
	
	if(count==0)
	{
		printf("%d������!\n",N);	
	}
	return 0; 
		
} 
