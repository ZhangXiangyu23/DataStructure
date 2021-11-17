#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node* Next;	
};

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

//�ж�ջ�ǲ��ǿ�ջ
bool IsEmpty(Stack S)
{
	if(S->Next==NULL)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

//ջҲ�Ǵ���ͷ����
Stack CreatStack()
{
	Stack  S=(Stack)malloc(sizeof(struct Node));
	if(S==NULL)
	{
		printf("����ռ�ʧ��!\n");	
	}
	else
	{
		S->Next=NULL;
		return S;	
	}	
} 

//ѹջ����
void Push(ElementType X,Stack S)
{
	//��ʵ������ջ����ͷ��㴦���в������ 
	PtrToNode p=(PtrToNode)malloc(sizeof(struct Node));	
	p->Element=X;
	p->Next=S->Next;
	S->Next=p;
}

//��ջ������������
void Pop(Stack S)
{
	PtrToNode p=S->Next;
	if(p==NULL)
	{
		printf("��ջΪ��ջ!\n");	
	}
	else
	{
		S->Next=p->Next;
		free(p);	
	}		
}

//���ջ,��ջ���һ����ջ 
void MakeEmpty(Stack S)
{
	if(S==NULL)
	{
		printf("���ȴ���һ��ջ�ɣ����Ǹ���ָ�밡!\n");	
	}
	else
	{
		while(!IsEmpty(S))
		{
			Pop(S);	
		}	
	}	
}

//����ջ
void DisposeStack(Stack S)
{
	//����ջ���һ����ջ�����ջ�ڵ�Ԫ��
	MakeEmpty(S);
	//����ջ�� 
	free(S);	
}

//��ȡջ��Ԫ�ص�ֵ
ElementType Top(Stack S)
{
	if(IsEmpty(S))
	{
		printf("��ջΪ��ջ!\n");	
	}
	else
	{
		return S->Next->Element;	
	}	
}

int main()
{
	//����һ��ջ
	Stack S=CreatStack();
	//ѹջ 
	for(int i=0;i<10;i++)
	{
		Push(i,S); 
	}
	//��ջ
	while(!IsEmpty(S))
	{
		printf("%d\n",Top(S));
		Pop(S);	
	} 
	//����ջ
	DisposeStack(S); 
	return 0;
}
 


