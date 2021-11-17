#include <stdio.h>
#include <stdlib.h>
#define MinQueueSize 5
typedef int ElementType;

struct QueueRecord{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType* Array;
};

typedef struct QueueRecord* Queue;

//判断队列是否是空
bool IsEmpty(Queue Q)
{
	if(Q->Size==0)
	{
		return true;	
	}	
	else
	{
		return false;
	}
} 

//判断队列是否已经满了
bool IsFull(Queue Q)
{
	if(Q->Capacity==Q->Size)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

//将队列置空
void MakeEmpty(Queue Q)
{
	Q->Front=1;
	Q->Rear=0;
	Q->Size=0;	
}

//创建一个队列
Queue CreatQueue(int MaxElement)
{
	if(MaxElement<MinQueueSize)
	{
		printf("队列的空间太小了!\n");
		exit(0);
	}
	Queue Q=(Queue)malloc(sizeof(struct QueueRecord));
	if(Q==NULL)
	{
		printf("内存分配失败!\n");
		exit(0);
	}
	Q->Array=(ElementType *)malloc(sizeof(ElementType)*MaxElement);
	if(Q->Array==NULL)
	{
		printf("内存分配失败!\n");
		exit(0);
	}
	Q->Capacity=MaxElement;
	MakeEmpty(Q);
	return Q;
}

//销毁队列
void DisposeQueue(Queue Q)
{
	if(Q!=NULL)
	{
		free(Q->Array);
		free(Q);	
	}	
}

//这个函数的作用是：移动队尾指针 
int Succ(int Value,Queue Q)
{
	if(++Value==Q->Capacity)
	{
		Value=0;
	}
	return Value;
}


//入队
void EnQueue(ElementType X,Queue Q)
{
	if(IsFull(Q))
	{
		printf("队列已经满了!\n");
		exit(0);	
	}
	else
	{
		Q->Size++;
		Q->Rear=Succ(Q->Rear,Q);
		Q->Array[Q->Rear]=X;	
	}	
}


//获取队头元素
ElementType Front(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("队列为空!\n");
		exit(0);	
	}
	else
	{
		return Q->Array[Q->Front];	
	} 
}

 
//出队
void DeQueue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("该队列是空队列!\n");	
	}
	else
	{
		Q->Size--;
		Q->Front=Succ(Q->Front,Q);	
	}	
} 

int main()
{
	Queue Q=CreatQueue(12);
	for(int i=0;i<10;i++)
	{
		EnQueue(i,Q);
	}
	
	//边出队，边打印
	while(!IsEmpty(Q))
	{
		printf("%d\n",Front(Q));
		DeQueue(Q);
	}
	
	return 0;
	 
}
 

