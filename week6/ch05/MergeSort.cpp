#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[],int N);
void Show(int A[],int N);
int main()
{
	int A[6]={8,-2,10,0,3,99};
	printf("����֮ǰ:\n");
	Show(A,6);
	printf("\n");
	MergeSort(A,6);
	printf("����֮��:\n");
	Show(A,6);
}


void Show(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d\t",A[i]);
	}
}



void Merge(int A[],int TempArray[],int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,TempPos;
	LeftEnd=Rpos-1;//�����ֹ 
	TempPos=Lpos;//�����ռ�ָ�� 
	NumElements=RightEnd-Lpos+1;//�����ܸ��� 
	while(Lpos<=LeftEnd&&Rpos<=RightEnd)
	{
		if(A[Lpos]<=A[Rpos])
		{
			TempArray[TempPos++]=A[Lpos++];	
		}
		else
		{
			TempArray[TempPos++]=A[Rpos++];	
		}	
	}
	
	while(Lpos<=LeftEnd)
	{
		TempArray[TempPos++]=A[Lpos++];	
	}	
	while(Rpos<=RightEnd)
	{
		TempArray[TempPos++]=A[Rpos++];
	}
	
	//�������ռ������е�Ԫ���ٴηŻ�ԭ����
	for(i=0;i<NumElements;i++)
	{
		A[i]=TempArray[i];	
	} 
}




void MSort(int A[],int TempArray[],int Left,int Right)
{
	int Center;
	if(Left<Right)
	{
		Center=(Left+Right)/2;
		MSort(A,TempArray,Left,Center);   //���ݹ�ʽ�Ĺ鲢���� 
		MSort(A,TempArray,Center+1,Right); //�Ҳ�ݹ�ʽ�Ĺ鲢���� 
		Merge(A,TempArray,Left,Center+1,Right); //�����кϲ� 
	}
}



void MergeSort(int A[],int N)
{
	int* TempArray;
	TempArray=(int*)malloc(N*sizeof(int)); //�������� 
	if(TempArray!=NULL)
	{
		MSort(A,TempArray,0,N-1);//����Χ0~N-1 
		free(TempArray);
	}
	else
	{
		printf("û������ռ�!\n");
	}
}
