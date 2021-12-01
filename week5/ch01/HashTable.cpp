#include <stdio.h>
#include <stdlib.h>
#define MinTableSize (10)      //��С�� 
#define NumItem  400 
typedef unsigned int Index;     
typedef int ElementType;
struct ListNode{
	ElementType Element;
	struct ListNode* Next;
};

typedef  struct ListNode* Position;//�ڵ� 
typedef Position List;//����
 
struct HashTbl{
	int TableSize; 
	List* TheLists; 
};

typedef struct HashTbl* HashTable;//���������˾��Ĺ�ϣ�� 



 

//���ַ����е��ַ���ASCII����� 
Index Hash1(char* Key,int TableSize)
{
	unsigned int HashVal=0;
	while(*Key!='\0')
	{
		HashVal+= *Key++;	
	}
	return HashVal%TableSize; 
}

//u1s1���Ҳ�֪��������ô��� 
Index Hash2(char* Key,int TableSize)
{
	return (Key[0]+Key[1]*27+Key[2]*729)%TableSize;
}

//�Ҹ㲻��Hash2������Hash3���� 
Index Hash3(char* Key,int TableSize)
{
	unsigned int HashVal=0;
	while(*Key!='\0')
	{
		HashVal=(HashVal<<5)+*Key++;	
	}
	return HashVal%TableSize;
}

bool IsPrime(int n);
//����N������һ�����ڵ���N������
int NextPrime(int N)
{
	while(!IsPrime(N))
	{
		N++;	
	}
	return N;	
}


//�ж�һ�����Ƿ�������
bool IsPrime(int n)
{
	for(int i=2;i*i<n;i++)
	{
		if(n%i==0)
		{
			return false;	
		}	
	}
	return true;	
}


//�ܼ򵥵�Hash����
Index Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
}

//��ʼ����ϣ�� 
//��������������ˣ����� 
HashTable InitTable(int TableSize)
{
	HashTable H=(struct HashTbl*)malloc(sizeof(struct HashTbl));
	//�����ϣ���һ������������
	H->TableSize=NextPrime(TableSize);
	//����һ����������
	H->TheLists=(List*)malloc(sizeof(struct ListNode)*H->TableSize);		
	//���������鰤������ͷ���ռ� 
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheLists[i]=(List)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next=NULL;
	}	
	return H;
}  

//�ڹ�ϣ����Ѱ��һ��ֵ���ڵĽڵ�λ��
Position Find(ElementType X,HashTable &H)
{
	List L=H->TheLists[Hash(X,H->TableSize)];//���ҵ�ֵ���ڵ���������������Ȼ���ҵ���Ӧ������
	Position p=L->Next;
	while(p!=NULL)
	{
		if(p->Element!=X)
		{
			p=p->Next;	
		}	
	}
	return p;	
} 

//��һ��ֵ���뵽��ϣ����
//˼·��ʵû��ɶ����ʵ���Ǹ�һ��ֵ��ͨ����ϣ����ӳ�䵽��Ӧ����������������Ȼ���ڶ�Ӧ�������н��б�ͷ����
void Insert(ElementType X,HashTable H)
{

	Position p=Find(X,H);
	//������ڣ��Ͳ��ù���
	//��������ڣ����ڶ�Ӧ�ı�ͷ���в���
	Position NewCell;
	if(p==NULL)
	{
		List L=H->TheLists[Hash(X,H->TableSize)]; 
		NewCell=(struct ListNode*)malloc(sizeof(struct ListNode));
		NewCell->Element=X;
		NewCell->Next=L->Next;
		L->Next=NewCell;
	}	
} 

//��ȡ�ڵ��е�ֵ
ElementType Retrieve(Position p)
{
	return p->Element;	
} 

//���ٱ�
void  DestroyTable(HashTable H)
{
	Position p;
	for(int i=0;i<H->TableSize;i++)
	{
		p=H->TheLists[i];  //Ϲ�룬�����������ӣ�ֻҪ���ҵ������ڵ����ɾ���� 
		while(p!=NULL)
		{
			Position term=p->Next;
			free(p);
			p=term;
		}
	}
	free(H->TheLists);
	free(H);	
} 

	
int main()
{
	HashTable H=InitTable(13);
	int j=0;
	//����400��ֵ����ϣ����
	for(int i=0;i<NumItem;i++)
	{
		Insert(i,H);	
	}
	//������˳�����δ�ӡ�����е�ֵ
	for(int i=0;i<H->TableSize;i++)
	{
		Position p=H->TheLists[i]->Next;
		while(p!=NULL)
		{
			printf("%d\t",p->Element);
			p=p->Next;	
		}
		printf("\n");	
	}		 
	return 0;	
} 
 

