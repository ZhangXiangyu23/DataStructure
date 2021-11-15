#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node{
	ElementType Element;
	Node* Next;
}Node;

//��ʵ��һ���� 
typedef Node* List;      //רָ���� 
typedef Node* Position;  //רָ�ڵ� 
List makeEmpty();


//����һ������ͷ�������� 
List makeEmpty()
{
	//ͷ��� 
	List L=(Node*)malloc(sizeof(Node));
	L->Next=NULL;
	return L;	
}

//�ж�һ�������ǲ��ǿձ�
bool IsEmpty(List L)
{
	if(L->Next==NULL)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

//�ж�һ���ڵ��ǲ������һ���ڵ�
bool IsLast(Position P)
{
	if(P->Next==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����Ԫ��ֵ��Ӧ���Ǹ���ַ���뷵��ָ��
Position Find(ElementType x,List L)
{
	Position p=L->Next;
	while(p!=NULL&&p->Element!=x)
	{
		p=p->Next;
	}
	return p;
}

//ɾ��ָ��Ԫ��ֵ���ڵĽڵ�
bool Delete(ElementType x,List L)
{
	Position  FindPrevious(int x,List L);
	Position p=FindPrevious(x,L);
	Position term;
	if(!IsLast(p))
	{
		term=p->Next;
		p->Next=term->Next;	
		free(term);
	}
	return true;		
}

//����ָ��Ԫ��ֵ����һ���ڵ� 
Position  FindPrevious(int x,List L)
{
	Position p=L;
	while(p->Next!=NULL&&p->Next->Element!=x)
	{
		p=p->Next;
	}
	return p;
}

//��ָ���ڵ�p���棬����Ԫ��x 
void Insert(ElementType x,List L,Position p)
{
	Position h=(Position)malloc(sizeof(Node));
	h->Element=x;
	
	h->Next=p->Next;
	p->Next=h;	
} 

//ɾ��һ������
void DeleteList(List L)
{
	Position p=L->Next;
	L->Next=NULL; 
	Position term;
	while(p!=NULL)
	{
		term=p->Next;
		free(p);
		p=term;
	}
}

//���ر�ͷ
Position Header(List L)
{
	return L;	
} 

//���ص�һ��Ԫ��
Position First(List L)
{
	return L->Next;	
} 

//����һ��Ԫ��
Position Advance(Position p)
{
	return p->Next;	
}

//��ȡ��Ӧ�ڵ��Ԫ��ֵ 
ElementType getValue(Position p)
{
	return p->Element;	
} 

//��ӡ�����е�ֵ
void PrintList(List L)
{
	if(IsEmpty(L))
	{
		printf("�������ǿյ�!\n");
	}
	Position p=Header(L);//��ȡͷ���
	Position r=p->Next;//��һ���ڵ� 
	while(r!=NULL)
	{
		printf("%d\t",r->Element);
		r=Advance(r);
	}
	printf("\n");
}
 

 
int main()
{
	//����һ������ͷ���Ŀձ�
	List L=makeEmpty();
	if(L==NULL)
	{
		printf("����ʧ��!\n");	
	}
	else
	{
		printf("�����ɹ�!\n");	
	}
	PrintList(L);
	
	//һ�߲��룬һ���ӡ
	Position p=Header(L);
	for(int i=0;i<10;i++)
	{
		Insert(i,L,p);
		PrintList(L);
		p=Advance(p);
	} 
	
	//��0~9��ż����ȫ��ɾ��
	for(int i=0;i<10;i+=2)
	{
		Delete(i,L);
	}
	//չʾ�����ڵ�Ԫ��
	printf("ɾ��֮��:\n");
	PrintList(L); 
	
	//ɾ�������
	DeleteList(L);
	PrintList(L);
	return 0; 	 
				
} 

