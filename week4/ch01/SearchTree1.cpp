#include <stdio.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct Node* Left;
	struct Node* Right;
};

typedef struct TreeNode* Position;//指的是普通节点
typedef struct TreeNode* SearchTree;//指的是二叉搜索树 

/* 
*/


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

 
