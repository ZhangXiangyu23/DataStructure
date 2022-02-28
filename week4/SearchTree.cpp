#include <stdio.h>
typedef int ElementType;

struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//�ڵ�
typedef struct TreeNode* SearchTree;//��

//����һ�ÿ���
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);	
	}
	return NULL;
}

//�ڶ�����������ȥ����Ӧ��Ԫ��X
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;	
	}	
	if(X<T->Element)
	{
		return Find(X,T->Left);
	}
	else if(X>T->Element)
	{
		return Find(X,T->Right);
	}
	else
	{
		return T;
	}
} 

//�ݹ���ʽ 
//Ѱ�Ҷ�������������Сֵ��λ��
Position FindMin(SearchTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(T->Left==NULL)
	{
		return NULL;
	}
	else
	{
		return FindMin(T->Left);
	}
} 

//Ѱ�Ҷ��������������ֵ��λ��
Position FindMax(SearchTree T)
{
	if(T==NULL)
	{
		return NULL;	
	}
	else if(T->Right==NULL)
	{
		return NULL;
	}
	else
	{
		return FindMax(T->Right);
	}	
} 

//�������
Position Insert(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		T=(Position)malloc(sizeof(struct TreeNode));
		T->Element=X;
		T->Left=NULL;
		T->Right=NULL;	
	}
	else
	{
		if(X<T->Element)
		{
			T->Left=Insert(X,T->Left);	
		}
		else
		{
			T->Right=Insert(X,T->Right);	
		}	
	}	
	return NULL;
} 

//ɾ������
SearchTree Delete(ElementType X,SearchTree T)
{
	Position temp;
	if(T==NULL)
	{
		return NULL;
	}
	else
	{
		if(X<T->Element)
		{
			Delete(X,T->Left);	
		}
		else
		{
			Delete(X,T->Right);
		}
	}
	//�ҵ��� ������������������ 
	else if(T->Left&&T->Right)
	{
		Position temp=FindMin(T->Right);
		T->Element=temp->Element;
		T->Right=Delete(T->Element,T->Right);  //�����������ݹ�ɾ��X������ΪʲôҪָ��T->Right 
	}
	//ֻ��һ������ 
	else
	{
		temp=T;
		if(T->Left==NULL)
		{
			T=T->Right;
		}
		else if(T->Right==NULL)
		{
			T=T->Left;
		}
		free(temp);
	}
	return T; 
	
}

//��ȡ�ڵ��ֵ
ElementType GetValue(Position p)
{
	return p->Element;
} 


