#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//指的是普通节点
typedef struct TreeNode* SearchTree;//指的是二叉搜索树 




//清空一棵二叉搜索树
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

//查找一个值在哪个节点
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;	
	}
	else
	{
		if(X<T->Element)
		{
			return Find(X,T->Left);
		}
		if(X>T->Element)
		{
			return Find(X,T->Right);
		}
		if(X==T->Element)
		{
			return T;	
		}	
	}		
} 

//递归找最小值
Position FindMin(SearchTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	else if(T->Left==NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
} 

//循环地去找二叉搜索树的最大值
Position FindMax(SearchTree T)
{
	if(T!=NULL)
	{
		while(T->Right!=NULL)
		{
			T=T->Right;
		}
	}
	return T;
} 


//向二叉搜索树中插入一个值X
SearchTree Insert(ElementType X,SearchTree T)
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
//			return Insert(X,T->Left);
//			我知道为什么要这么写了！因为这样才能连成一棵树啊！！！！
			T->Left=Insert(X,T->Left);	 
		}
		else
		{
			T->Right=Insert(X,T->Right);	
		}	
	}
	//如果这个值已经在树中了，那就啥也操作，直接返回T 
	return T;	
} 


//在二叉搜索树中删除一个值
SearchTree Delete(ElementType X,SearchTree T)
{
	Position temp;
	if(T==NULL)
	{
		printf("没有找到!\n");
	}
	else if(X<T->Element)
	{
		T->Left=Delete(X,T->Left);
	}
	else if(X>T->Element)
	{
		T->Right=Delete(X,T->Right);
	}
	else if(T->Left&&T->Right)
	{
		temp=FindMin(T->Right);
		T->Element=temp->Element;
		T->Right=Delete(T->Element,T->Right);
	}
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

//取一个节点中的值
ElementType Retrieve(Position P)
{
	return P->Element;	
}
 
 
int main()
{
	SearchTree T;
	Position p;
	int j=0; 
	//清空一棵二叉树
	T=MakeEmpty(NULL); 
	
	//建立二叉搜索树
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);
	}
	//检验一下0~49是否已经全部插入了
	//哪里出错了，就会在哪里报错 
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||Retrieve(p)!=i)
		{
			printf("错误在于%d\n",i);	
		}		
	} 
	
	//删除二叉搜索树中的偶数值
	//每次的修改，依赖的是返回值，也可以使用C++中的引用&,将修改之后，影响了的数据，带回来！！！！ 
	for(int i=0;i<50;i=i+2)
	{
		T=Delete(i,T);		
	}
	//再检验一下，是否还有偶数，如果还有偶数就报错了！
	for(int i=0;i<50;i=i+2)
	{
		if((p=Find(i,T))!=NULL)
		{
			printf("还有%d值，是偶数!\n",i);	
		}	
	} 
	
	//寻找二叉搜索树中的最小值和最大值
	printf("二叉搜索树中的最小值是%d,最大值是%d\n",Retrieve(FindMin(T)),Retrieve(FindMax(T))); 
	return 0;
}



 
