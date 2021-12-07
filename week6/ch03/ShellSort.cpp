#include <stdio.h>

void Show(int A[],int N);
void ShellSort(int A[],int N);
int main()
{
	int A[6]={5,-1,12,3,22,-7};
	printf("����֮ǰ:\n");
	Show(A,6);
	ShellSort(A,6);
	printf("ϣ������֮��:\n");
	Show(A,6);	
}

//ϣ������
void ShellSort(int A[],int N)
{
	int Increment;
	int i,j,Temp;
	//�ȷ��� 
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


//չʾ 
void Show(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d\t",A[i]);	
	}	
}


