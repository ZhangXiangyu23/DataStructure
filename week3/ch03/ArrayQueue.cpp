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

//�ж϶����Ƿ��ǿ�
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

//�ж϶����Ƿ��Ѿ�����
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

//�������ÿ�
void MakeEmpty(Queue Q)
{
	Q->Front=1;
	Q->Rear=0;
	Q->Size=0;	
}

//����һ������
Queue CreatQueue(int MaxElement)
{
	if(MaxElement<MinQueueSize)
	{
		printf("���еĿռ�̫С��!\n");
		exit(0);
	}
	Queue Q=(Queue)malloc(sizeof(struct QueueRecord));
	if(Q==NULL)
	{
		printf("�ڴ����ʧ��!\n");
		exit(0);
	}
	Q->Array=(ElementType *)malloc(sizeof(ElementType)*MaxElement);
	if(Q->Array==NULL)
	{
		printf("�ڴ����ʧ��!\n");
		exit(0);
	}
	Q->Capacity=MaxElement;
	MakeEmpty(Q);
	return Q;
}

//���ٶ���
void DisposeQueue(Queue Q)
{
	if(Q!=NULL)
	{
		free(Q->Array);
		free(Q);	
	}	
}

//��������������ǣ��ƶ���βָ�� 
int Succ(int Value,Queue Q)
{
	if(++Value==Q->Capacity)
	{
		Value=0;
	}
	return Value;
}


//���
void EnQueue(ElementType X,Queue Q)
{
	if(IsFull(Q))
	{
		printf("�����Ѿ�����!\n");
		exit(0);	
	}
	else
	{
		Q->Size++;
		Q->Rear=Succ(Q->Rear,Q);
		Q->Array[Q->Rear]=X;	
	}	
}


//��ȡ��ͷԪ��
ElementType Front(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("����Ϊ��!\n");
		exit(0);	
	}
	else
	{
		return Q->Array[Q->Front];	
	} 
}

 
//����
void DeQueue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("�ö����ǿն���!\n");	
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
	
	//�߳��ӣ��ߴ�ӡ
	while(!IsEmpty(Q))
	{
		printf("%d\n",Front(Q));
		DeQueue(Q);
	}
	
	return 0;
	 
}
 

