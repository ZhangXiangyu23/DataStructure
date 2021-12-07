#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[],int N);
void Show(int A[],int N);
int main()
{
	int A[6]={8,-2,10,0,3,99};
	printf("排序之前:\n");
	Show(A,6);
	printf("\n");
	MergeSort(A,6);
	printf("排序之后:\n");
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
	LeftEnd=Rpos-1;//左侧终止 
	TempPos=Lpos;//辅助空间指针 
	NumElements=RightEnd-Lpos+1;//排序总个数 
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
	
	//将辅助空间数组中的元素再次放回原数组
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
		MSort(A,TempArray,Left,Center);   //左侧递归式的归并排序 
		MSort(A,TempArray,Center+1,Right); //右侧递归式的归并排序 
		Merge(A,TempArray,Left,Center+1,Right); //最后进行合并 
	}
}



void MergeSort(int A[],int N)
{
	int* TempArray;
	TempArray=(int*)malloc(N*sizeof(int)); //辅助数组 
	if(TempArray!=NULL)
	{
		MSort(A,TempArray,0,N-1);//排序范围0~N-1 
		free(TempArray);
	}
	else
	{
		printf("没有数组空间!\n");
	}
}
