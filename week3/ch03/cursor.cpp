#include <stdio.h>
typedef int ElementType;
#define SpaceSize 100
typedef int PtrToNode;
typedef PtrToNode List;     //��ָ����ģ��ָ����� 
typedef PtrToNode Position; //��ָԪ�أ�ģ��ָ����� 
struct Node{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];

//��ʼ���α꣬���α���ģ��ָ�룡 
void InitializeCursorSpace()
{
	for(int i=0;i<SpaceSize;i++)
	{
		CursorSpace[i].Next=i+1; 
	}
	CursorSpace[SpaceSize-1].Next=0; 
}

//ģ��malloc����������ռ�
//malloc������������һƬ�ռ䣬���շ���һ��ָ����Ƭ�ռ��ָ��
Position CursorAlloc()
{
	Position p;//����Ҫ���ص�ָ��
	p=CursorSpace[0].Next;
	
	CursorSpace[0].Next=CursorSpace[p].Next;
	return p;	
} 

//����һƬ�ռ䣬ģ��free()����
void CursorFree(Position p)
{
	CursorSpace[p].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=p;			
} 

//����һ���ձ�
List MakeEmpty()
{
	List L=CursorAlloc();
	CursorSpace[L].Next=0;
	return L;
			
}

//�ж�һ�ű��Ƿ��ǿձ�
//�����������˵�ı����Ǵ���ͷ����
//��ͷҪ�����һ���ڵ㣬��ô���ǿձ� 
bool IsEmpty(List L)
{
	if(CursorSpace[L].Next==0)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
} 

//�ж�һ���ڵ㣺����һ���ڵ㣬���Ƿ������һ���ڵ� 
bool IsLast(Position p)
{
	if(CursorSpace[p].Next==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�������в���ָ��Ԫ��
Position Find(ElementType X,List L)
{
	Position p=CursorSpace[L].Next;//��һ���ڵ�
	while(p!=0&&CursorSpace[p].Element!=X)
	{
		p=CursorSpace[p].Next;	
	}
	return p;	
} 

//��������ɾ��ָ��Ԫ��
void Delete(ElementType X,List L)
{
	//�������� 
	Position FindPrevious(ElementType X,List L); 
	Position p=FindPrevious(X,L);
	Position term;
	if(!IsLast(p))
	{
		term=CursorSpace[p].Next;
		CursorSpace[p].Next=CursorSpace[term].Next;
		CursorFree(term);	
	}	
}

//ͨ��Ԫ��ֵ��������һ��Ԫ��
Position FindPrevious(ElementType X,List L)
{
	Position p=L;
	while(CursorSpace[p].Next!=0&&CursorSpace[CursorSpace[p].Next].Element!=X)
	{
		p=CursorSpace[p].Next;
	}
	return p;	
}

//��ָ��λ�ú���� 
void Insert(Position p,ElementType X,List L)
{
	Position y=CursorAlloc();
	CursorSpace[y].Element=X;
	CursorSpace[y].Next=CursorSpace[p].Next;
	CursorSpace[p].Next=y;
}

//ɾ��һ����
void DeletList(List L)
{
	Position x=CursorSpace[L].Next;
	CursorSpace[L].Next=0;//�ñ�ͷָ�� 
	while(x!=0)
	{
		Position term=CursorSpace[x].Next;
		CursorFree(x);
		x=term;
		 
	}
} 
 
//���ر�ͷ
Position Header(List L)
{
	return L;	
}

//���һ��Ԫ��
Position First(List L)
{
	return CursorSpace[L].Next;	
}

//����һ��Ԫ��
Position Advance(Position p)
{
	return 	CursorSpace[p].Next;
} 

//��ȡĳ��Ԫ�ص�ֵ
ElementType GetValue(Position p)
{
	return 	CursorSpace[p].Element;
}

 
//��ӡ���е�Ԫ��
void PrintList(List L)
{
	Position p=Header(L);
	if(IsEmpty(L))
	{
		printf("������Ǹ��ձ�!\n");	
	}	
	Position term=CursorSpace[p].Next;
	while(term!=0)
	{
		printf("%d\t",GetValue(term));
		term=CursorSpace[term].Next;	
	}
	printf("\n");	
} 

 
 
//������α�ʵ�� 
//�����Ǵ���ͷ�������� 
int main()
{
	//��ʼ�����ݿռ�
	InitializeCursorSpace();
	//����һ�ſձ� 
	List L=MakeEmpty();
	//��ӡ
	PrintList(L); 
	//���������Ԫ�أ��߲���ߴ�ӡ
	Position p=Header(L);
	for(int i=0;i<10;i++)
	{
		Insert(p,i,L);
		PrintList(L);
		p=Advance(p);	
	} 
	
	//��ż��ɾ��
	for(int i=0;i<10;i+=2)
	{
		Delete(i,L);	
	}
	//��ӡ�� 
	PrintList(L); 
	//ɾ��������
	DeletList(L);
	//��ӡ��
	PrintList(L);  
	return 0;
	 
}


