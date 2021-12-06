#include <stdio.h>
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)
#define MaxSize1 (1000)
typedef int ElementType;
struct HeapStruct{
	int Capacity;    //总共的容量 
	int Size;        //当前所用掉的容量 
	ElementType* Elements; //一片存储空间的起始地址 
};


typedef struct HeapStruct* PriorityQueue;

  
//初始化一个优先队列
PriorityQueue Initialize(int MaxSize)
{
	if(MaxSize<MinPQSize)
	{
		printf("队列长度也太短了吧！！！\n");
	}
	PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Capacity=MaxSize;  
	H->Size=0;//当前里面存放了0个元素
	H->Elements=(ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));//加一的原因是，需要将数组索引为0的位置空出来，充当哨兵
	//将数组中的哨兵值设定为MinData
	H->Elements[0]=MinData;
	return H;	
} 

//将优先队列置空
void MakeEmpty(PriorityQueue H)
{
	H->Size=0;
} 

//判断队列是否满了 
bool IsFull(PriorityQueue H)
{
	if(H->Size==H->Capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//在优先队列中插入一个值（上滤操作）
void Insert(ElementType X,PriorityQueue H)
{
	if(IsFull(H))
	{
		printf("队列已经满了，插不进去了！！\n");
		return;	
	}
	int i;
	for(i=++H->Size;X<H->Elements[i/2];i=i/2)
	{ 
		H->Elements[i]=H->Elements[i/2];		
	}
	H->Elements[i]=X;	 //最后将其放在合适位置 
} 


//判断是否为空
bool IsEmpty(PriorityQueue H)
{
	if(H->Size==0)
	{
		return true;	
	}
	else
	{
		return false;	
	}			
} 



//删除最小值，并且返回它
ElementType DeleteMin(PriorityQueue H)
{
	if(IsEmpty(H))
	{
		printf("队列为空，无法进行删除!\n");
		return 	MinData;
	}
	int Min=H->Elements[1];
	int Last=H->Elements[H->Size];
	H->Size--;//删除之后，缩小其大小
	int child;
	int i;
	for(i=1;i*2<=H->Size;i=child) 
	{
		child=i*2;
		if(child!=H->Size&&H->Elements[child+1]<H->Elements[child])
		{
			child++;	
		}
		if(Last>H->Elements[child])
		{
			H->Elements[i]=H->Elements[child];						
		}
		else
		{
			break;
		}
	}
	
	H->Elements[i]=Last;
	return Min;	
}


//找最小值
ElementType FindMin(PriorityQueue H)
{
	if(!IsEmpty(H))
	{
		return H->Elements[1];	
	}
	else
	{
		printf("优先队列为空！\n");
		return 	MinData;	
	}	
}

//销毁有限队列
void Destroy(PriorityQueue H)
{
	free(H->Elements);
	free(H);	
} 

int main()
{
	PriorityQueue H;
	int i,j=0;
	H=Initialize(MaxSize1);
	for(int i=0,j=MaxSize1/2;i<MaxSize1;i++,j=(j+71)%MaxSize1)
	 Insert(j,H);
	 
	j=0;
	while(!IsEmpty(H))
		if(DeleteMin(H)!=j++)
		printf("错误出在%d\n",j);
	printf("Done...\n");
	return 0;
		
}

