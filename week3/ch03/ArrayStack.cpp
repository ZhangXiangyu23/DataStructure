#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;  //改名 
#define EmptyTOS (-1)     //宏定义 
#define MinStackSize (5) 
struct StackRecord{
	int Capacity;  //自己定义的栈大小 
	int TopOfStack;  //现在所处的数组的下标位置 
	ElementType* Array;//指向int的指针类型 
};

typedef struct StackRecord* Stack;
 
//栈的数组实现

//判断一个栈是不是空栈
bool IsEmpty(Stack S)
{
	if(S->TopOfStack==EmptyTOS)
	{
		return true;	
	}	
	else
	{
		return false;
	}
}

//判断栈是否是满的
bool IsFull(Stack S)
{
	if(S->TopOfStack==S->Capacity-1)
	{
		return true;	
	}	
	else
	{
		return false;
	}
} 

//清空栈中的内容
void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyTOS;	
} 

//创建一个栈
//其实是用动态开辟数组空间，来模拟栈 
Stack CreatStack(int MaxElement)
{
	//小于规定的栈空间的最小值 
	if(MaxElement<MinStackSize)
	{
		printf("栈空间太小了!\n"); 
	}
	Stack S=(Stack)malloc(sizeof(struct StackRecord));
	if(S==NULL)
	{
		printf("分配空间失败!\n");	
	}
	
	S->Capacity=MaxElement;
	S->TopOfStack=EmptyTOS;//表示内容为空
	S->Array=(ElementType*)malloc(sizeof(ElementType)*MaxElement);
	return S;		
} 

//销毁栈
void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
} 

//压栈
void Push(ElementType X,Stack S)
{
	if(IsFull(S))
	{
		printf("栈已将满了!\n");	
	}
	else
	{
		S->TopOfStack++;
		S->Array[S->TopOfStack]=X;
	}	
} 

//出栈(弹出)
void Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("该栈为空!\n");	
	}
	S->TopOfStack--;		
}




int main()
{
	//创建一个栈容量是12的栈
	Stack S=CreatStack(12);
	//开始压栈 
	for(int i=0;i<10;i++)
	{
		Push(i,S);	
	}
	
	//一边弹出栈，一边打印元素
	while(!IsEmpty(S))
	{
		printf("%d\n",S->Array[S->TopOfStack]); 
		Pop(S);
	}	 
	//销毁栈
	DisposeStack(S);
	return 0; 
}


 
