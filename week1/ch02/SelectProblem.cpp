#include <stdio.h>
#include <stdlib.h>


//����һ 
int main()
{
	printf("�������ܸ���N\n");
	int N;
	scanf("%d",&N);
	int k=N/2;
	int a[N];
	
	
	//������������в���
	for(int i=0;i<N;i++)
	{
		a[i]=rand();	
	} 
	
	
	
	//��N��������ð�����򣨽���
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<N-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int term=a[j];
				a[j]=a[j+1];
				a[j+1]=term;
			}	
		}	
	}
	
	printf("���������������֮��:\n");
	for(int i=0;i<N;i++)
	{
		printf("%d\n",a[i]);	
	} 
	
	
	printf("N/2=%d,��%d�������%d\n",k,k,a[k-1]);
	
} 
