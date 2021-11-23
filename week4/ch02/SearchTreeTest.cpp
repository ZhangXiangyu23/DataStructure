#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	struct TreeNode* Left;
	struct TreeNode* Right;
};

typedef struct TreeNode* Position;//ָ���ǽڵ�
typedef struct TreeNode* SearchTree;//ָ���Ƕ���������

//����
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
		//����ֵ���ڽڵ�ֵ 
		if(X<T->Element)
		{
			T->Left=Insert(X,T->Left);		
		}
		//����ֵС�ڽڵ�ֵ 
		if(X>T->Element)
		{
			T->Right=Insert(X,T->Right);	
		}	
		//����ֵ���ڽڵ�ֵ��ɶҲ���ùܣ� 
	}
	return T;	
}


//��ȡ�ڵ��Ԫ��ֵ
ElementType GetValue(Position p)
{
	return p->Element;
}


//������Ѱ��һ��ֵ��λ�ã�ָ�룩
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		return NULL;//û�Ҽ����� 
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

//Ѱ�Ҷ����������е���Сֵλ��(�ݹ�˼·)
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

//Ѱ�Ҷ�������������Сֵ(ѭ��˼·)
Position FindMin2(SearchTree T)
{
	if(T==NULL)
	{
		printf("һ�ÿ���������ʲô��Сֵ����Ц!\n");
	}
	Position p=T;
	while(p->Left!=NULL)
	{
		p=p->Left;	
	}
	return p;	
}


//�ݹ������ֵ
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

//ѭ���Ҷ����������е����ֵ
Position FindMax2(SearchTree T)
{
	if(T==NULL)
	{
		printf("һ�ÿ���������ʲô���ֵ����Ц!\n");
	}
	Position p=T;
	while(p->Right!=NULL)
	{
		p=p->Right;	
	}
	return p;
		
} 

//ɾ��Ԫ��ֵ��Ӧ�Ľڵ㣬ɾ��֮�󣬷�������
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
			//�����������е����
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
				else if(T->Right==NULL)  //�����ˣ������� 
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
	//����0~49
	int j=0;
	for(int i=0;i<50;i++,j=(j+7)%50)
	{
		T=Insert(j,T);
	}
	//�����Ƿ��Ѿ�������
	//���û�в����Ӧ��ֵ�ͻᱨ��
	for(int i=0;i<50;i++)
	{
		if((p=Find(i,T))==NULL||GetValue(p)!=i)
		{
			printf("������%d\n",i);	
		}	
	}
	
	//��һ�����е���Сֵ
	printf("��������������Сֵ��:%d\n",GetValue(FindMin1(T)));
	printf("��������������Сֵ��:%d\n",GetValue(FindMin2(T)));	
	printf("���������������ֵ��:%d\n",GetValue(FindMax1(T)));	
	printf("���������������ֵ��:%d\n",GetValue(FindMax2(T)));
	
	
	
	//ɾ��ż��
	for(int i=0;i<50;i=i+2)
	{
		T=Delete(i,T);	
	}
	//�ж�һ�°���
	for(int i=1;i<50;i=i+2)
	{
		if((p=Find(i,T))==NULL||GetValue(p)!=i)
		{
			printf("����ĵط�����%d\n",i);	
		}	
	}
	 
	printf("��������������Сֵ��:%d\n",GetValue(FindMin1(T)));
	printf("��������������Сֵ��:%d\n",GetValue(FindMin2(T)));	
	printf("���������������ֵ��:%d\n",GetValue(FindMax1(T)));	
	printf("���������������ֵ��:%d\n",GetValue(FindMax2(T)));
	
	 
} 
