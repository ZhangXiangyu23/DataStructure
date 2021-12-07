#include <stdio.h>

void Show(int A[],int N);
void ShellSort(int A[],int N);
int main()
{
	int A[6]={5,-1,12,3,22,-7};
	printf("排序之前:\n");
	Show(A,6);
	ShellSort(A,6);
	printf("希尔排序之后:\n");
	Show(A,6);	
}

//希尔排序
void ShellSort(int A[],int N)
{
	int Increment;
	int i,j,Temp;
	//先分组 
	for(Increment=N/2;Increment>0;Increment=Increment/2)
	{
		for(i=Increment;i<N;i++)
		{
			Temp=A[i];
			for(j=i;j>=Increment;j=j-Increment)	
			{
				if(Temp<A[j-Increment])
				{
					A[j]=A[j-Increment];	
				}
				else
				{
					break;	
				}	
			}
			A[j]=Temp;
		} 
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


