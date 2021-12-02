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
//找一个和N最接近的素数
int NextPrime(int N)
{
	while(!IsPrime(N))
	{
		N++;	
	}
	return N;	
} 


//判断是不是素数
bool IsPrime(int N)
{
	for(int i=2;i*i<N;i++)
	{
		if(N%i==0)
		{
			return false;//不是素数	
		}	
	}
	return true;//是素数	
} 

//哈希函数的简单设置
Index Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
} 

//哈希表的初始化
HashTable InitTable(int TableSize)
{
	if(TableSize<MinTableSize)
	{
		printf("哈希表长太短了，不行！！");
		return 	NULL;
	}
	HashTable H=(struct HashTbl*)malloc(sizeof(struct HashTbl));
	//想给哈希表整一个素数表长，这样不易产生冲突
	H->TableSize=NextPrime(TableSize);//结构体指针类型 
	//开辟结构体数组 
	H->TheCells=(Cell*)malloc(sizeof(struct HashEntry)*H->TableSize);
	//初始化结构体数组
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheCells[i].Info=Empty;
	}
	return H;	
}


//返回可以存放数值的位置
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

//在哈希表中插入值
void Insert(ElementType X,HashTable &H)
{
	Position p=Find(X,H);
	H->TheCells[p].Element=X;
	H->TheCells[p].Info=Legitimate;
}

//重构一个哈希表, 重构的意思是，在原来的基础上进行！！！ 
HashTable ReHash(HashTable H)
{
	int OldSize=H->TableSize;
	Cell* OldCell=H->TheCells;
	
	H=InitTable(OldSize*2);
	//将原来的元素搬过来
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

//获取一个位置的值 
ElementType Retrieve(Position p,HashTable H)
{
	return H->TheCells[p].Element; 
}

//销毁这个哈希表
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
//			printf("此单元为空!\n");
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

