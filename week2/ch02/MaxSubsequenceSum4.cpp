#include <stdio.h>


//�����㷨��ʱ�临�Ӷ���O(N) 
int main()
{
	int a[6]={-2,11,-4,13,-5,-2};
	int MaxSum=0;
	int ThisSum=0;
	for(int i=0;i<6;i++)
	{
		ThisSum+=a[i];
		if(ThisSum>MaxSum)
		{
			MaxSum=ThisSum;
		}
		else
		{
			if(ThisSum<0)
			{
				ThisSum=0;
			}
		}
	}
	printf("��������к�Ϊ:%d",MaxSum); 
}
