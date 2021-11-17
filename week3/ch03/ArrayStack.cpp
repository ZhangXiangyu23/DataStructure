#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;  //���� 
#define EmptyTOS (-1)     //�궨�� 
#define MinStackSize (5) 
struct StackRecord{
	int Capacity;  //�Լ������ջ��С 
	int TopOfStack;  //����������������±�λ�� 
	ElementType* Array;//ָ��int��ָ������ 
};

typedef struct StackRecord* Stack;
 
//ջ������ʵ��

//�ж�һ��ջ�ǲ��ǿ�ջ
bool IsEmpty(Stack S)
{
	if(S->TopOfStack==EmptyTOS)
	{
		return true;	
	}	
	else
	{
		return false;
	}
}

//�ж�ջ�Ƿ�������
bool IsFull(Stack S)
{
	if(S->TopOfStack==S->Capacity-1)
	{
		return true;	
	}	
	else
	{
		return false;
	}
} 

//���ջ�е�����
void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyTOS;	
} 

//����һ��ջ
//��ʵ���ö�̬��������ռ䣬��ģ��ջ 
Stack CreatStack(int MaxElement)
{
	//С�ڹ涨��ջ�ռ����Сֵ 
	if(MaxElement<MinStackSize)
	{
		printf("ջ�ռ�̫С��!\n"); 
	}
	Stack S=(Stack)malloc(sizeof(struct StackRecord));
	if(S==NULL)
	{
		printf("����ռ�ʧ��!\n");	
	}
	
	S->Capacity=MaxElement;
	S->TopOfStack=EmptyTOS;//��ʾ����Ϊ��
	S->Array=(ElementType*)malloc(sizeof(ElementType)*MaxElement);
	return S;		
} 

//����ջ
void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
} 

//ѹջ
void Push(ElementType X,Stack S)
{
	if(IsFull(S))
	{
		printf("ջ�ѽ�����!\n");	
	}
	else
	{
		S->TopOfStack++;
		S->Array[S->TopOfStack]=X;
	}	
} 

//��ջ(����)
void Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("��ջΪ��!\n");	
	}
	S->TopOfStack--;		
}




int main()
{
	//����һ��ջ������12��ջ
	Stack S=CreatStack(12);
	//��ʼѹջ 
	for(int i=0;i<10;i++)
	{
		Push(i,S);	
	}
	
	//һ�ߵ���ջ��һ�ߴ�ӡԪ��
	while(!IsEmpty(S))
	{
		printf("%d\n",S->Array[S->TopOfStack]); 
		Pop(S);
	}	 
	//����ջ
	DisposeStack(S);
	return 0; 
}


 
