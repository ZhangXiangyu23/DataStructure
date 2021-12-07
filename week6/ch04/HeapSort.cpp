#include <stdio.h>
#define LeftChild(i)  (2*(i)+1)

void Show(int A[],int n);
void HeapSort(int A[],int N);
int main()
{
	int A[7]={97,53,59,26,41,58,31};
	printf("排序之前:\n");
	Show(A,7);
	printf("\n");
	printf("排序之后:\n");
	HeapSort(A,7);
	Show(A,7);
	return 0;
}

void Show(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",A[i]);	
	}	
} 



void PercDown(int A[],int i,int N)
{
	int Child;
	int Temp;
	for(Temp=A[i];LeftChild(i)<N;i=Child)
	{
		Child = LeftChild(i);
		if(Child!=N-1&&A[Child+1]>A[Child])
		{
			Child++;
		}
		if(Temp<A[Child])
		{
			A[i]=A[Child];
		}
		else
		{
			break;
		}
	}
	A[i]=Temp;
}

void HeapSort(int A[],int N)
{
	for(int i=N/2;i>=0;i--)
	{
		PercDown(A,i,N);
	}
	
	for(int i=N-1;i>0;i--)
	{
		int Temp=A[0];
		A[0]=A[i];
		A[i]=Temp;
		PercDown(A,0,i);
	}
}



