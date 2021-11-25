#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct AvlNode{
	ElementType Element;
	struct AvlNode* Left;
	struct AvlNode* Right;
	int Height;
};

typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

//���һ��AVL��
AvlTree MakeEmpty(AvlTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);	
	}
	return NULL;	
} 


//��AVL����Ѱ��ֵ��λ��
Position Find(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	if(T!=NULL)
	{
		if(X==T->Element)
		{
			return T;
		}
		if(X<T->Element)
		{
			return	Find(X,T->Left);
		}
		if(X>T->Element)
		{
			return  Find(X,T->Right);	
		}	
	}				
} 

//�ݹ�Ѱ����Сֵ
Position FindMin(AvlTree T)
{
	if(T==NULL)
	{
		printf("�����ǿ����ˣ�����ʲô��Сֵ!\n");
		return NULL; 
	}
	if(T!=NULL)
	{
		if(T->Left==NULL)
		{
			return T;	
		}
		else
		{
			return FindMin(T->Left);	
		}	
	}	
} 

//ѭ��Ѱ�����ֵ
Position FindMax(AvlTree T)
{
	if(T==NULL)
	{
		printf("����Ϊ���ˣ�����ʲô��Сֵ!\n");
		return NULL;	
	}	
	while(T->Right!=NULL)
	{
		return FindMax(T->Right);
	}
	return T;
} 

//��һ���ڵ�ĸ߶�
int Height(Position p)
{
	if(p==NULL)
	{
		return -1;//�ڵ㲻���ڣ����ظ߶�Ϊ-1	
	}
	else
	{
		return p->Height;	
	}	
} 

//������ֵ�нϴ��һ��
int Max(int Lhs,int Rhs)
{
	return Lhs>Rhs?Lhs:Rhs;	
}

//�������ڵ��һ����ת
static Position SingleRotateWithLeft(Position K2)
{
	//��ת 
	Position K1=K2->Left;
	K2->Left=K1->Right;//K1�Ҳ�������ʱ��һ����K2ֵС��Ӧ�ùҵ�K2�����
	K1->Right=K2;
	
	//�޸ĸ߶�ֵ
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	return K1;
	 
		
} 







//�����Ҳ�ڵ��һ����ת
static Position SingleRotateWithRight(Position K1)
{
	Position K2=K1->Right;
	
	//��ת
	K1->Right=K2->Left;
	K2->Left=K1;
	//�޸ĸ߶�
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	return K2;	
} 

//������Ĵ���
Position DoubleRotateWithLeft(Position K3)
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return 	SingleRotateWithLeft(K3);
}

//����ĵĴ���
Position DoubleRotateWithRight(Position K1)
{
	Position K3=K1->Right;
	K1->Right=SingleRotateWithLeft(K3);
	return 	SingleRotateWithRight(K1);
}

AvlTree Delete(ElementType X,AvlTree T)
{
	printf("�Բ���ɾ��������û��ʵ��!\n");
	return T;  //��ʵɶҲ���ɣ������Ǹ�	
}

//��ȡ�ڵ��ֵ 
ElementType Retrieve(Position P)
{
	return P->Element;	
} 


//��AVL���в���ֵX
//AvlTree Insert(ElementType X,AvlTree T)
//{
//	if(T==NULL)
//	{
//		T=(AvlTree)malloc(sizeof(struct AvlNode));
//		T->Element=X;
//		T->Height=0;
//		T->Left=NULL;
//		T->Right=NULL;
//	}
//	else if(X<T->Element)
//	{
//		T->Left=Insert(X,T->Left);
//		if(Height(T->Left)-Height(T->Right)==2)
//		{
//			if(X<T->Left->Element)
//			{
//				T=SingleRotateWithLeft(T);	
//			}
//			else
//			{
//				T=DoubleRotateWithLeft(T);
//			}
//		}
//	}
//	else if(X>T->Element)
//	{
//		T->Right=Insert(X,T->Right);
//		if(Height(T->Right)-Height(T->Left)==2)
//		{
//			if(X>T->Right->Element)
//			{
//				T=SingleRotateWithRight(T);
//			}
//			else
//			{
//				T=DoubleRotateWithRight(T);
//			}
//		}
//	}
//	T->Height=Max(Height(T->Left),Height(T->Right))+1;
//	return T;
//} 

AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)
	{
		T=(AvlTree)malloc(sizeof(struct AvlNode));
		T->Element=X;
		T->Height=0;
		T->Left=NULL;
		T->Right=NULL;
	}
	else
	{
		if(X<T->Element)
		{
			T->Left=Insert(X,T->Left);
			if(Height(T->Left)-Height(T->Right)==2)
			{
				if(X<T->Left->Element)
				{
					T=SingleRotateWithLeft(T);		
				}
				else
				{
					T=DoubleRotateWithLeft(T);	
				}	
			}	
		}
		else if(X>T->Element)
		{
			T->Right=Insert(X,T->Right);
			if(Height(T->Right)-Height(T->Left)==2)
			{
				if(X>T->Right->Element)
				{
					T=SingleRotateWithRight(T);	
				}
				else
				{
					T=DoubleRotateWithRight(T);	
				}	
			}	
		}	
	}
	T->Height=Max(Height(T->Left),Height(T->Right))+1;
	return T;	
} 

int main()
{
	Position p;
	AvlTree T;
	T=MakeEmpty(NULL);//���һ����
	int j=0;
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);	
	}
	
	//����ֵ�����ȥ��û��
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||Retrieve(p)!=i)
		{
			printf("��������%d\n",i);	
		}		
	}
	
	
	//Ѱ�����ֵ����Сֵ
	printf("���е����ֵ��%d,���е���Сֵ��%d\n",Retrieve(FindMax(T)),Retrieve(FindMin(T))); 
	
	
	 
}

