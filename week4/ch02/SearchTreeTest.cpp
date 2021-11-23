#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//指的是节点
typedef struct TreeNode* SearchTree;//指定是二叉搜索树

//插入
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
		//插入值大于节点值 
		if(X<T->Element)
		{
			T->Left=Insert(X,T->Left);		
		}
		//插入值小于节点值 
		if(X>T->Element)
		{
			T->Right=Insert(X,T->Right);	
		}	
		//插入值等于节点值，啥也不用管！ 
	}
	return T;	
}


//获取节点的元素值
ElementType GetValue(Position p)
{
	return p->Element;
}


//在树中寻找一个值的位置（指针）
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;//没找见啊！ 
	}
	else
	{
		if(X==T->Element)
		{
			return T;	
		}
		if(X<T->Element)
		{
			return Find(X,T->Left);	
		}
		if(X>T->Element)
		{
			return Find(X,T->Right);
		}		
	} 

		
} 

//寻找二叉搜索树中的最小值位置(递归思路)
Position FindMin1(SearchTree T)
{
	if(T!=NULL)
	{
		if(T->Left==NULL)
		{
			return T;
		}
		else
		{
			return FindMin1(T->Left);		
		}
		
	}
}

//寻找二叉搜索树的最小值(循环思路)
Position FindMin2(SearchTree T)
{
	if(T==NULL)
	{
		printf("一棵空树，你找什么最小值，搞笑!\n");
	}
	Position p=T;
	while(p->Left!=NULL)
	{
		p=p->Left;	
	}
	return p;	
}


//递归找最大值
Position FindMax1(SearchTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	if(T->Right==NULL)
	{
		return T;	
	}
	if(T->Right!=NULL)
	{
		FindMax1(T->Right);	
	}	
} 

//循环找二叉搜索树中的最大值
Position FindMax2(SearchTree T)
{
	if(T==NULL)
	{
		printf("一棵空树，你找什么最大值，搞笑!\n");
	}
	Position p=T;
	while(p->Right!=NULL)
	{
		p=p->Right;	
	}
	return p;
		
} 

//删除元素值对应的节点，删除之后，返回新树
SearchTree Delete(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;
	}
	if(T!=NULL)
	{
		if(X<T->Element)
		{
			T->Left=Delete(X,T->Left);	
		}
		if(X>T->Element)
		{
			T->Right=Delete(X,T->Right);	
		}
		if(X==T->Element)
		{
			//左右子树都有的情况
			if(T->Left!=NULL&&T->Right!=NULL)
			{
				Position temp=FindMin1(T->Right);
				T->Element=temp->Element;
				T->Right=Delete(T->Element,T->Right);	
			}
			else
			{
				Position temp;
				if(T->Left==NULL)
				{
					temp=T;
					T=T->Right;
				}
				else if(T->Right==NULL)  //我悟了！！！！ 
				{
					temp=T;
					T=T->Left;	
				}
				free(temp);	
			}	
		}	
	}
	return T;
} 
 



int main()
{
	SearchTree T=NULL;
	Position p;
	//插入0~49
	int j=0;
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);
	}
	//看看是否已经插入了
	//如果没有插入对应的值就会报错
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||GetValue(p)!=i)
		{
			printf("错误在%d\n",i);	
		}	
	}
	
	//求一棵树中的最小值
	printf("二叉搜索树的最小值是:%d\n",GetValue(FindMin1(T)));
	printf("二叉搜索树的最小值是:%d\n",GetValue(FindMin2(T)));	
	printf("二叉搜索树的最大值是:%d\n",GetValue(FindMax1(T)));	
	printf("二叉搜索树的最大值是:%d\n",GetValue(FindMax2(T)));
	
	
	
	//删除偶数
	for(int i=0;i<50;i=i+2)
	{
		T=Delete(i,T);	
	}
	//判断一下啊！
	for(int i=1;i<50;i=i+2)
	{
		if((p=Find(i,T))==NULL||GetValue(p)!=i)
		{
			printf("出错的地方在于%d\n",i);	
		}	
	}
	 
	printf("二叉搜索树的最小值是:%d\n",GetValue(FindMin1(T)));
	printf("二叉搜索树的最小值是:%d\n",GetValue(FindMin2(T)));	
	printf("二叉搜索树的最大值是:%d\n",GetValue(FindMax1(T)));	
	printf("二叉搜索树的最大值是:%d\n",GetValue(FindMax2(T)));
	
	 
} 
