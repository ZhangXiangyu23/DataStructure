#include <stdio.h>
#include <stdlib.h>
#define MinTableSize (10)      //最小表长 
#define NumItem  400 
typedef unsigned int Index;     
typedef int ElementType;
struct ListNode{
	ElementType Element;
	struct ListNode* Next;
};

typedef  struct ListNode* Position;//节点 
typedef Position List;//链表
 
struct HashTbl{
	int TableSize; 
	List* TheLists; 
};

typedef struct HashTbl* HashTable;//这是正儿八经的哈希表 



 

//将字符串中的字符的ASCII码相加 
Index Hash1(char* Key,int TableSize)
{
	unsigned int HashVal=0;
	while(*Key!='\0')
	{
		HashVal+= *Key++;	
	}
	return HashVal%TableSize; 
}

//u1s1，我不知道这是怎么想的 
Index Hash2(char* Key,int TableSize)
{
	return (Key[0]+Key[1]*27+Key[2]*729)%TableSize;
}

//我搞不懂Hash2函数和Hash3函数 
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
//参数N，返回一个大于等于N的素数
int NextPrime(int N)
{
	while(!IsPrime(N))
	{
		N++;	
	}
	return N;	
}


//判断一个数是否是素数
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


//很简单的Hash函数
Index Hash(ElementType Key,int TableSize)
{
	return Key%TableSize;
}

//初始化哈希表 
//哈哈哈，我理解了！！！ 
HashTable InitTable(int TableSize)
{
	HashTable H=(struct HashTbl*)malloc(sizeof(struct HashTbl));
	//想给哈希表搞一个素数长度了
	H->TableSize=NextPrime(TableSize);
	//开辟一个链表数组
	H->TheLists=(List*)malloc(sizeof(struct ListNode)*H->TableSize);		
	//给链表数组挨个开辟头结点空间 
	for(int i=0;i<H->TableSize;i++)
	{
		H->TheLists[i]=(List)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next=NULL;
	}	
	return H;
}  

//在哈希表中寻找一个值所在的节点位置
Position Find(ElementType X,HashTable &H)
{
	List L=H->TheLists[Hash(X,H->TableSize)];//先找到值所在的链表数组索引，然后找到对应的链表
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

//将一个值插入到哈希表中
//思路其实没个啥，其实就是给一个值，通过哈希函数映射到对应的链表数组索引，然后在对应的链表中进行表头插入
void Insert(ElementType X,HashTable H)
{

	Position p=Find(X,H);
	//如果存在，就不用管了
	//如果不存在，就在对应的表头进行插入
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

//获取节点中的值
ElementType Retrieve(Position p)
{
	return p->Element;	
} 

//销毁表
void  DestroyTable(HashTable H)
{
	Position p;
	for(int i=0;i<H->TableSize;i++)
	{
		p=H->TheLists[i];  //瞎想，沿着这条链子，只要能找到各个节点就能删除了 
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
	//插入400个值到哈希表中
	for(int i=0;i<NumItem;i++)
	{
		Insert(i,H);	
	}
	//按链表顺序，依次打印链表中的值
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
 

