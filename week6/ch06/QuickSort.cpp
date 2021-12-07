#include <stdio.h>
#define Cutoff(3)




void Swap(int* a,int* b)
{
	int term=*a;
	*a=*b;
	*b=term;	
}

int Median3(int A[],int Left,int Right)
{
	int Center=(Left+Right)/2;
	if(A[Left]>A[Center])
	{
		Swap(&A[Left],&A[Center]);	
	}
	if(A[Left]>A[Right])
	{
		Swap(&A[Left],&A[Right]);	
	}
	if(A[Center]>A[Right])
	{
		Swap(&A[Center],&A[Right]);	
	}
	
	Swap(&A[Center],&A[Right-1]);
	return A[Right-1];	
}




void Show(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}


void Qsort(int A[],int Left,int Right)
{
	int i,j;
	int Pivot;	
	if(Left+Cutoff<=Right)
	{
		Pivot=Median3(A,Left,Right);
		i=Left;
		j=Right-1;
		for(;;)
		{
			while(A[++i]<Pivot)
			{
			}
			while(A[--j]>Pivot)
			{
			}
			if(i<j)
			{
				Swap(&A[i],&A[j]);
			}
			else
			{
				break;
			}
		}
	}
	
	
}



void QuickSort(int A[],int N)
{
	Qsort(A,0,N-1);
}

int main()
{
	int a[5]={5,-2,0,-3,6};
	printf("ÅÅÐòÖ®Ç°:\n");
	Show(a,5);
}
