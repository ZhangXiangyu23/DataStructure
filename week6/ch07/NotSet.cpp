#include <stdio.h>
#define NumSets 11
typedef int DisjSet[NumSets+1];
typedef int SetType;
typedef int ElementType;
 
 

//初始化
void Initialize(DisjSet S)
{
	for(int i=NumSets;i>0;i--)
	{
		S[i]=0;	
	}	
} 


//合并
void SetUnion(DisjSet S,SetType Root1,SetType Root2)
{
	//将Root2挂到Root1下面，说明Root1是父节点 
	S[Root2]=Root1;
		
} 

//找一个值的节点，对应的父节点 
SetType Find(ElementType X,DisjSet S)
{	
	if(S[X]<=0)
	{
		return X;	
	}
	else
	{
		Find(S[X],S);	
	}	
} 

//合并时的优化（深度小的挂在深度大的下面） 
void SetUnion1(DisjSet S,SetType Root1,SetType Root2)
{
	if(S[Root1]<S[Root2])
	{
		S[Root2]=Root1;	
	}
	else
	{
		if(S[Root1]==S[Root2])
		{
			S[Root1]--;//将其--,其实就是将其深度加深	
		}	
		S[Root1]=Root2; 
	} 
}


/*
路径压缩：实质上就是改变找到的节点的父节点，将其直接指向根节点 
*/ 
SetType Find1(ElementType X,DisjSet S)
{
	if(S[X]<=0)
	{
		return X;	
	}
	else
	{
		return S[X]=Find(S[X],S);	
	}	
} 



int main()
{
	DisjSet S;
	int i=1,j=1,k=1,Set1,Set2;
	Initialize(S);
	while(k<=3)
	{
		j=1;
		while(j<NumSets)
		{
			Set1=Find(j,S);
			Set2=Find(j+k,S);
			SetUnion(S,Set1,Set2);
			j+=2*k;	
		}
		k=k*2;	
	}
	
	for(i=1;i<=NumSets;i++)
	{
		Set1=Find(i,S);
		printf("%d**",Set1);	
	}
	printf("\n");
	return 0;	
} 
