#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 640000

int RandInt(int i,int j);
void swap(int* m,int* n);
int main()
{
	int a[N]; 
	//�ȶ������ʼ��
	for(int i=0;i<N;i++)
	{
		a[i]=i+1;	
	}
	//����
	srand((unsigned)time(NULL)); 
	//����
	for(int i=1;i<N;i++)
	{
		int u=RandInt(0,i);
		swap(&a[i],&a[u]);	
	}
	
	//�������������
	for(int i=0;i<N;i++)
	{
		printf("%d\n",a[i]);	
	} 
	
	 
}

//���������
int RandInt(int i,int j)
{
	int x=j-i+1;
	int a=rand()%x+i;
	return a;	
} 

//����
void swap(int* m,int* n)
{
	int term;
	term=*m;
	*m=*n;
	*n=term;	
} 
