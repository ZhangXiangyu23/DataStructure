#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	printf("������N��ֵ��\n");
	scanf("%d",&N);
	int k=N/2;
	int a[k];
	
	for(int i=0;i<k;i++)
	{
		a[i]=rand();
	}
	
	//ѡ������
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(a[j]>a[i])
			{
				int term=a[i];
				a[i]=a[j];
				a[j]=term;	
			}	
		}	
	}
	
	printf("ѡ��������ֵ:\n");
	for(int i=0;i<k;i++)
	{
		printf("%d\n",a[i]);
	}
	
	printf("-------------------\n");
	
	//����ʣ�µ�k����
	int m=k-1; 
	for(int i=0;i<k;i++)
	{
		int e=rand();
		printf("%d\n",e);
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
			
			//�ƶ�
			for(int v=m-1;v>=f;v--)
			{
				a[v+1]=a[v];	
			} 
			
			//e��Ӧ��λ��
			a[f]=e; 
		}
	}
	
	printf("��%d�����Ϊ:%d",k,a[k-1]); 
	 
}
