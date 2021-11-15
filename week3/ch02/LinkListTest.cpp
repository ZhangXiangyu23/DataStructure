#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node{
	ElementType Element;
	Node* Next;
}Node;

//其实是一码事 
typedef Node* List;      //专指链表 
typedef Node* Position;  //专指节点 
List makeEmpty();


//创建一个带有头结点的链表 
List makeEmpty()
{
	//头结点 
	List L=(Node*)malloc(sizeof(Node));
	L->Next=NULL;
	return L;	
}

//判断一个链表是不是空表
bool IsEmpty(List L)
{
	if(L->Next==NULL)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

//判断一个节点是不是最后一个节点
bool IsLast(Position P)
{
	if(P->Next==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//查找元素值对应的那个地址，请返回指针
Position Find(ElementType x,List L)
{
	Position p=L->Next;
	while(p!=NULL&&p->Element!=x)
	{
		p=p->Next;
	}
	return p;
}

//删除指定元素值所在的节点
bool Delete(ElementType x,List L)
{
	Position  FindPrevious(int x,List L);
	Position p=FindPrevious(x,L);
	Position term;
	if(!IsLast(p))
	{
		term=p->Next;
		p->Next=term->Next;	
		free(term);
	}
	return true;		
}

//查找指定元素值的上一个节点 
Position  FindPrevious(int x,List L)
{
	Position p=L;
	while(p->Next!=NULL&&p->Next->Element!=x)
	{
		p=p->Next;
	}
	return p;
}

//在指定节点p后面，插入元素x 
void Insert(ElementType x,List L,Position p)
{
	Position h=(Position)malloc(sizeof(Node));
	h->Element=x;
	
	h->Next=p->Next;
	p->Next=h;	
} 

//删除一个链表
void DeleteList(List L)
{
	Position p=L->Next;
	L->Next=NULL; 
	Position term;
	while(p!=NULL)
	{
		term=p->Next;
		free(p);
		p=term;
	}
}

//返回表头
Position Header(List L)
{
	return L;	
} 

//返回第一个元素
Position First(List L)
{
	return L->Next;	
} 

//求下一个元素
Position Advance(Position p)
{
	return p->Next;	
}

//获取对应节点的元素值 
ElementType getValue(Position p)
{
	return p->Element;	
} 

//打印链表中的值
void PrintList(List L)
{
	if(IsEmpty(L))
	{
		printf("该链表是空的!\n");
	}
	Position p=Header(L);//获取头结点
	Position r=p->Next;//第一个节点 
	while(r!=NULL)
	{
		printf("%d\t",r->Element);
		r=Advance(r);
	}
	printf("\n");
}
 

 
int main()
{
	//创建一个带有头结点的空表
	List L=makeEmpty();
	if(L==NULL)
	{
		printf("创建失败!\n");	
	}
	else
	{
		printf("创建成功!\n");	
	}
	PrintList(L);
	
	//一边插入，一遍打印
	Position p=Header(L);
	for(int i=0;i<10;i++)
	{
		Insert(i,L,p);
		PrintList(L);
		p=Advance(p);
	} 
	
	//将0~9的偶数，全部删除
	for(int i=0;i<10;i+=2)
	{
		Delete(i,L);
	}
	//展示链表内的元素
	printf("删除之后:\n");
	PrintList(L); 
	
	//删除这个表
	DeleteList(L);
	PrintList(L);
	return 0; 	 
				
} 

