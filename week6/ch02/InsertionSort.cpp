#include <stdio.h>

void Show(int A[],int N);
void InsertionSort(int A[],int N);
void InsertSort(int A[],int N);
int main()
{
	int A[6]={12,0,3,-4,0,88};
	printf("排序之前:\n");
	Show(A,6);
	printf("\n");
	printf("排序之后:\n");
//	InsertionSort(A,6);
	InsertSort(A,6);
	Show(A,6);	
	
	
}

//简单插入排序
void InsertionSort(int A[],int N)
{
	int j;
	for(int i=1;i<N;i++)
	{
		int Temp=A[i];
		for(j=i;j>0&&A[j-1]>Temp;j--)
		{
			A[j]=A[j-1];	
		}
		A[j]=Temp;	
	}	
} 

void InsertSort(int A[],int N)
{
	int j;
	for(int i=1;i<N;i++)
	{
		int Temp=A[i];
		for(j=i-1;j>=0&&A[j]>Temp;j--)
		{
			A[j+1]=A[j];
		}
		A[j+1]=Temp;
	}
}



//展示 
void Show(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d\t",A[i]);	
	}	
} 
