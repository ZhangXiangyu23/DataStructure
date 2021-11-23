#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//ָ������ͨ�ڵ�
typedef struct TreeNode* SearchTree;//ָ���Ƕ��������� 




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

//����һ��ֵ���ĸ��ڵ�
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

//�ݹ�����Сֵ
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

//ѭ����ȥ�Ҷ��������������ֵ
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


//������������в���һ��ֵX
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
//			��֪��ΪʲôҪ��ôд�ˣ���Ϊ������������һ��������������
			T->Left=Insert(X,T->Left);	 
		}
		else
		{
			T->Right=Insert(X,T->Right);	
		}	
	}
	//������ֵ�Ѿ��������ˣ��Ǿ�ɶҲ������ֱ�ӷ���T 
	return T;	
} 


//�ڶ�����������ɾ��һ��ֵ
SearchTree Delete(ElementType X,SearchTree T)
{
	Position temp;
	if(T==NULL)
	{
		printf("û���ҵ�!\n");
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

//ȡһ���ڵ��е�ֵ
ElementType Retrieve(Position P)
{
	return P->Element;	
}
 
 
int main()
{
	SearchTree T;
	Position p;
	int j=0; 
	//���һ�ö�����
	T=MakeEmpty(NULL); 
	
	//��������������
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);
	}
	//����һ��0~49�Ƿ��Ѿ�ȫ��������
	//��������ˣ��ͻ������ﱨ�� 
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||Retrieve(p)!=i)
		{
			printf("��������%d\n",i);	
		}		
	} 
	
	//ɾ�������������е�ż��ֵ
	//ÿ�ε��޸ģ��������Ƿ���ֵ��Ҳ����ʹ��C++�е�����&,���޸�֮��Ӱ���˵����ݣ��������������� 
	for(int i=0;i<50;i=i+2)
	{
		T=Delete(i,T);		
	}
	//�ټ���һ�£��Ƿ���ż�����������ż���ͱ����ˣ�
	for(int i=0;i<50;i=i+2)
	{
		if((p=Find(i,T))!=NULL)
		{
			printf("����%dֵ����ż��!\n",i);	
		}	
	} 
	
	//Ѱ�Ҷ����������е���Сֵ�����ֵ
	printf("�����������е���Сֵ��%d,���ֵ��%d\n",Retrieve(FindMin(T)),Retrieve(FindMax(T))); 
	return 0;
}



 
