#include <stdio.h>
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)
#define MaxSize1 (1000)
typedef int ElementType;
struct HeapStruct{
	int Capacity;    //�ܹ������� 
	int Size;        //��ǰ���õ������� 
	ElementType* Elements; //һƬ�洢�ռ����ʼ��ַ 
};


typedef struct HeapStruct* PriorityQueue;

  
//��ʼ��һ�����ȶ���
PriorityQueue Initialize(int MaxSize)
{
	if(MaxSize<MinPQSize)
	{
		printf("���г���Ҳ̫���˰ɣ�����\n");
	}
	PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Capacity=MaxSize;  
	H->Size=0;//��ǰ��������0��Ԫ��
	H->Elements=(ElementType*)malloc(sizeof(ElementType)*(MaxSize+1));//��һ��ԭ���ǣ���Ҫ����������Ϊ0��λ�ÿճ������䵱�ڱ�
	//�������е��ڱ�ֵ�趨ΪMinData
	H->Elements[0]=MinData;
	return H;	
} 

//�����ȶ����ÿ�
void MakeEmpty(PriorityQueue H)
{
	H->Size=0;
} 

//�ж϶����Ƿ����� 
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


//�����ȶ����в���һ��ֵ�����˲�����
void Insert(ElementType X,PriorityQueue H)
{
	if(IsFull(H))
	{
		printf("�����Ѿ����ˣ��岻��ȥ�ˣ���\n");
		return;	
	}
	int i;
	for(i=++H->Size;X<H->Elements[i/2];i=i/2)
	{ 
		H->Elements[i]=H->Elements[i/2];		
	}
	H->Elements[i]=X;	 //�������ں���λ�� 
} 


//�ж��Ƿ�Ϊ��
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



//ɾ����Сֵ�����ҷ�����
ElementType DeleteMin(PriorityQueue H)
{
	if(IsEmpty(H))
	{
		printf("����Ϊ�գ��޷�����ɾ��!\n");
		return 	MinData;
	}
	int Min=H->Elements[1];
	int Last=H->Elements[H->Size];
	H->Size--;//ɾ��֮����С���С
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


//����Сֵ
ElementType FindMin(PriorityQueue H)
{
	if(!IsEmpty(H))
	{
		return H->Elements[1];	
	}
	else
	{
		printf("���ȶ���Ϊ�գ�\n");
		return 	MinData;	
	}	
}

//�������޶���
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
		printf("�������%d\n",j);
	printf("Done...\n");
	return 0;
		
}

