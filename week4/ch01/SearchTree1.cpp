#include <stdio.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct Node* Left;
	struct Node* Right;
};

typedef struct TreeNode* Position;//ָ������ͨ�ڵ�
typedef struct TreeNode* SearchTree;//ָ���Ƕ��������� 

/* 
*/


//���һ�ö���������
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

 
