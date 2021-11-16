#include <stdio.h>
typedef int ElementType;
#define SpaceSize 100
typedef int PtrToNode;
typedef PtrToNode List;     //特指链表，模拟指针变量 
typedef PtrToNode Position; //特指元素，模拟指针变量 
struct Node{
	ElementType Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];

//初始化游标，用游标来模拟指针！ 
void InitializeCursorSpace()
{
	for(int i=0;i<SpaceSize;i++)
	{
		CursorSpace[i].Next=i+1; 
	}
	CursorSpace[SpaceSize-1].Next=0; 
}

//模拟malloc函数来分配空间
//malloc函数用来分配一片空间，最终返回一个指向这片空间的指针
Position CursorAlloc()
{
	Position p;//最终要返回的指针
	p=CursorSpace[0].Next;
	
	CursorSpace[0].Next=CursorSpace[p].Next;
	return p;	
} 

//回收一片空间，模拟free()函数
void CursorFree(Position p)
{
	CursorSpace[p].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=p;			
} 

//创建一个空表
List MakeEmpty()
{
	List L=CursorAlloc();
	CursorSpace[L].Next=0;
	return L;
			
}

//判断一张表是否是空表
//这个程序我们说的表，都是带有头结点的
//表头要是最后一个节点，那么就是空表 
bool IsEmpty(List L)
{
	if(CursorSpace[L].Next==0)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
} 

//判断一个节点：传入一个节点，看是否是最后一个节点 
bool IsLast(Position p)
{
	if(CursorSpace[p].Next==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//在链表中查找指定元素
Position Find(ElementType X,List L)
{
	Position p=CursorSpace[L].Next;//第一个节点
	while(p!=0&&CursorSpace[p].Element!=X)
	{
		p=CursorSpace[p].Next;	
	}
	return p;	
} 

//在链表中删除指定元素
void Delete(ElementType X,List L)
{
	//函数声明 
	Position FindPrevious(ElementType X,List L); 
	Position p=FindPrevious(X,L);
	Position term;
	if(!IsLast(p))
	{
		term=CursorSpace[p].Next;
		CursorSpace[p].Next=CursorSpace[term].Next;
		CursorFree(term);	
	}	
}

//通过元素值，查找上一个元素
Position FindPrevious(ElementType X,List L)
{
	Position p=L;
	while(CursorSpace[p].Next!=0&&CursorSpace[CursorSpace[p].Next].Element!=X)
	{
		p=CursorSpace[p].Next;
	}
	return p;	
}

//在指定位置后插入 
void Insert(Position p,ElementType X,List L)
{
	Position y=CursorAlloc();
	CursorSpace[y].Element=X;
	CursorSpace[y].Next=CursorSpace[p].Next;
	CursorSpace[p].Next=y;
}

//删除一个表
void DeletList(List L)
{
	Position x=CursorSpace[L].Next;
	CursorSpace[L].Next=0;//让表头指空 
	while(x!=0)
	{
		Position term=CursorSpace[x].Next;
		CursorFree(x);
		x=term;
		 
	}
} 
 
//返回表头
Position Header(List L)
{
	return L;	
}

//求第一个元素
Position First(List L)
{
	return CursorSpace[L].Next;	
}

//求下一个元素
Position Advance(Position p)
{
	return 	CursorSpace[p].Next;
} 

//获取某个元素的值
ElementType GetValue(Position p)
{
	return 	CursorSpace[p].Element;
}

 
//打印表中的元素
void PrintList(List L)
{
	Position p=Header(L);
	if(IsEmpty(L))
	{
		printf("这个表是个空表!\n");	
	}	
	Position term=CursorSpace[p].Next;
	while(term!=0)
	{
		printf("%d\t",GetValue(term));
		term=CursorSpace[term].Next;	
	}
	printf("\n");	
} 

 
 
//链表的游标实现 
//链表是带有头结点的链表 
int main()
{
	//初始化内容空间
	InitializeCursorSpace();
	//制造一张空表 
	List L=MakeEmpty();
	//打印
	PrintList(L); 
	//往表里插入元素，边插入边打印
	Position p=Header(L);
	for(int i=0;i<10;i++)
	{
		Insert(p,i,L);
		PrintList(L);
		p=Advance(p);	
	} 
	
	//将偶数删掉
	for(int i=0;i<10;i+=2)
	{
		Delete(i,L);	
	}
	//打印表 
	PrintList(L); 
	//删除整个表
	DeletList(L);
	//打印表
	PrintList(L);  
	return 0;
	 
}


