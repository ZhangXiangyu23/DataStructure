#include <stdio.h>

int main()
{
	int k;
	printf("������k\n");
	scanf("%d",&k);
	int a[k];
	printf("����������Ԫ��\n");
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
	}
	//ѡ�����򣨵ݼ���
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
	
	
	
	printf("������������֣�����999��ʾ����\n");
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
			
			//�ƶ�
			for(int i=m-1;i>=f;i--)
			{
				a[i+1]=a[i];	
			} 
			//Ԫ��eӦ�÷��õ�λ�� 
			a[f]=e;
			
		}
		scanf("%d",&e);
	}
	
	printf("��%d�������%d",k,a[k-1]);
	
}
