#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node* Next;	
};

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

//判断栈是不是空栈
bool IsEmpty(Stack S)
{
	if(S->Next==NULL)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

//栈也是带有头结点的
Stack CreatStack()
{
	Stack  S=(Stack)malloc(sizeof(struct Node));
	if(S==NULL)
	{
		printf("分配空间失败!\n");	
	}
	else
	{
		S->Next=NULL;
		return S;	
	}	
} 

//压栈操作
void Push(ElementType X,Stack S)
{
	//其实就是在栈顶，头结点处进行插入操作 
	PtrToNode p=(PtrToNode)malloc(sizeof(struct Node));	
	p->Element=X;
	p->Next=S->Next;
	S->Next=p;
}

//出栈操作（弹出）
void Pop(Stack S)
{
	PtrToNode p=S->Next;
	if(p==NULL)
	{
		printf("该栈为空栈!\n");	
	}
	else
	{
		S->Next=p->Next;
		free(p);	
	}		
}

//清空栈,让栈变成一个空栈 
void MakeEmpty(Stack S)
{
	if(S==NULL)
	{
		printf("请先创建一个栈吧，这是个空指针啊!\n");	
	}
	else
	{
		while(!IsEmpty(S))
		{
			Pop(S);	
		}	
	}	
}

//销毁栈
void DisposeStack(Stack S)
{
	//先让栈变成一个空栈，清空栈内的元素
	MakeEmpty(S);
	//销毁栈顶 
	free(S);	
}

//获取栈顶元素的值
ElementType Top(Stack S)
{
	if(IsEmpty(S))
	{
		printf("该栈为空栈!\n");	
	}
	else
	{
		return S->Next->Element;	
	}	
}

int main()
{
	//创建一个栈
	Stack S=CreatStack();
	//压栈 
	for(int i=0;i<10;i++)
	{
		Push(i,S); 
	}
	//出栈
	while(!IsEmpty(S))
	{
		printf("%d\n",Top(S));
		Pop(S);	
	} 
	//销毁栈
	DisposeStack(S); 
	return 0;
}
 


