#include <stdio.h>

int main()
{
	int a[5]={0,-5,3,6,2};
	//ð�����򣨵ݼ���
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
	printf("������k\n");
	scanf("%d",&k);
	printf("��%d�������:%d\n",k,a[k-1]);
}
