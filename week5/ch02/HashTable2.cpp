#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define MinTableSize (10)
typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;

enum KindOfEntry{Legitimate,Empty,Deleted}; 
//#define Legitimate 0
//#define Empty 1
//#define Deleted 2


struct HashEntry{
	ElementType Element;
	enum KindOfEntry Info;
//	int Info;
};

typedef struct HashEntry Cell;
struct HashTbl{
	int TableSize;
	Cell* TheCells;
};

typedef struct HashTbl* HashTable;


bool IsPrime(int N);
//��һ����N��ӽ�������
int NextPrime(int N)
{
	while(!IsPrime(N))
	{
		N++;	
	}
	return N;	
} 


//�ж��ǲ�������
bool IsPrime(int N)
{
	for(int i=2;i*i<N;i++)
	{
		if(N%i==0)
		{
			return false;//��������	
		}	
	}
	return true;//������	
} 

//��ϣ�����ļ�����
Index Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
} 

//��ϣ��ĳ�ʼ��
HashTable InitTable(int TableSize)
{
	if(TableSize<MinTableSize)
	{
		printf("��ϣ��̫���ˣ����У���");
		return 	NULL;
	}
	HashTable H=(struct HashTbl*)malloc(sizeof(struct HashTbl));
	//�����ϣ����һ�����������������ײ�����ͻ
	H->TableSize=NextPrime(TableSize);//�ṹ��ָ������ 
	//���ٽṹ������ 
	H->TheCells=(Cell*)malloc(sizeof(struct HashEntry)*H->TableSize);
	//��ʼ���ṹ������
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].Info=Empty;
	}
	return H;	
}


//���ؿ��Դ����ֵ��λ��
Position Find(ElementType X,HashTable H)
{
	Position p=Hash(X,H->TableSize);
	int CollisionNum=0;
	while(H->TheCells[p].Info!=Empty&&H->TheCells[p].Element!=X)
	{
		p+=2*(++CollisionNum)-1;
		if(p>=H->TableSize)
		{
			p=p-H->TableSize;	
		}	
	}
	return p;	
}

//�ڹ�ϣ���в���ֵ
void Insert(ElementType X,HashTable &H)
{
	Position p=Find(X,H);
	H->TheCells[p].Element=X;
	H->TheCells[p].Info=Legitimate;
}

//�ع�һ����ϣ��, �ع�����˼�ǣ���ԭ���Ļ����Ͻ��У����� 
HashTable ReHash(HashTable H)
{
	int OldSize=H->TableSize;
	Cell* OldCell=H->TheCells;
	
	H=InitTable(OldSize*2);
	//��ԭ����Ԫ�ذ����
	for(int i=0;i<OldSize;i++)
	{
		if(OldCell[i].Info==Legitimate)
		{
			Insert(OldCell[i].Element,H);	
		}	
	}
	free(OldCell);
	return H; 
	 				
} 

//��ȡһ��λ�õ�ֵ 
ElementType Retrieve(Position p,HashTable H)
{
	return H->TheCells[p].Element; 
}

//���������ϣ��
void DestroyTable(HashTable H)
{
	free(H->TheCells);
	free(H);	
} 




int main()
{
//	HashTable H=InitTable(13);
//	for(int i=0;i<5;i++)
//	{
//		Insert(i,H);
//	}
//	
//	for(int i=0;i<H->TableSize;i++)	
//	{
//		if(H->TheCells[i].Info==Empty)
//		{
//			printf("�˵�ԪΪ��!\n");
//		}
//		if(H->TheCells[i].Info==Legitimate)
//		{
//			printf("%d\n",H->TheCells[i].Element);
//		}
//		
//	}
	
	int CurrentSize;
	int NumItems=400; 
	int j=0;
	HashTable H=InitTable(CurrentSize=13);
	for(int i=0;i<NumItems;i++,j=j+71)
	{
		if(i>CurrentSize/2)
		{
			printf("ReHashing...\n");
			H=ReHash(H);
			CurrentSize=CurrentSize*2;	
		}
		Insert(j,H);	
	}
	
	 
}

