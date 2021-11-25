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

//清空一棵AVL树
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


//在AVL树中寻找值的位置
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

//递归寻找最小值
Position FindMin(AvlTree T)
{
	if(T==NULL)
	{
		printf("树都是空树了，你找什么最小值!\n");
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

//循环寻找最大值
Position FindMax(AvlTree T)
{
	if(T==NULL)
	{
		printf("树都为空了，你找什么最小值!\n");
		return NULL;	
	}	
	while(T->Right!=NULL)
	{
		return FindMax(T->Right);
	}
	return T;
} 

//求一个节点的高度
int Height(Position p)
{
	if(p==NULL)
	{
		return -1;//节点不存在，返回高度为-1	
	}
	else
	{
		return p->Height;	
	}	
} 

//求两个值中较大的一个
int Max(int Lhs,int Rhs)
{
	return Lhs>Rhs?Lhs:Rhs;	
}

//带有左侧节点的一次旋转
static Position SingleRotateWithLeft(Position K2)
{
	//旋转 
	Position K1=K2->Left;
	K2->Left=K1->Right;//K1右侧有子树时，一定比K2值小，应该挂到K2的左侧
	K1->Right=K2;
	
	//修改高度值
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	return K1;
	 
		
} 







//带有右侧节点的一次旋转
static Position SingleRotateWithRight(Position K1)
{
	Position K2=K1->Right;
	
	//旋转
	K1->Right=K2->Left;
	K2->Left=K1;
	//修改高度
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	return K2;	
} 

//情况三的处理
Position DoubleRotateWithLeft(Position K3)
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return 	SingleRotateWithLeft(K3);
}

//情况四的处理
Position DoubleRotateWithRight(Position K1)
{
	Position K3=K1->Right;
	K1->Right=SingleRotateWithLeft(K3);
	return 	SingleRotateWithRight(K1);
}

AvlTree Delete(ElementType X,AvlTree T)
{
	printf("对不起，删除操作还没有实现!\n");
	return T;  //其实啥也不干，返回那个	
}

//获取节点的值 
ElementType Retrieve(Position P)
{
	return P->Element;	
} 


//向AVL树中插入值X
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
	T=MakeEmpty(NULL);//清空一棵树
	int j=0;
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);	
	}
	
	//看看值都插进去了没有
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||Retrieve(p)!=i)
		{
			printf("错误在于%d\n",i);	
		}		
	}
	
	
	//寻找最大值和最小值
	printf("树中的最大值是%d,树中的最小值是%d\n",Retrieve(FindMax(T)),Retrieve(FindMin(T))); 
	
	
	 
}

