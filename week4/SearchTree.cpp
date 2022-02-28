#include <stdio.h>
typedef int ElementType;

struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//节点
typedef struct TreeNode* SearchTree;//树

//制造一棵空树
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

//在二叉搜索树中去找相应的元素X
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

//递归形式 
//寻找二叉搜索树中最小值的位置
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

//寻找二叉搜索树中最大值的位置
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

//插入操作
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

//删除操作
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
	//找到了 并且有左右两个孩子 
	else if(T->Left&&T->Right)
	{
		Position temp=FindMin(T->Right);
		T->Element=temp->Element;
		T->Right=Delete(T->Element,T->Right);  //在右子树，递归删除X，但是为什么要指向T->Right 
	}
	//只有一个孩子 
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

//获取节点的值
ElementType GetValue(Position p)
{
	return p->Element;
} 


