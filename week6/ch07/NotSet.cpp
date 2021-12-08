#include <stdio.h>
#define NumSets 11
typedef int DisjSet[NumSets+1];
typedef int SetType;
typedef int ElementType;
 
 

//��ʼ��
void Initialize(DisjSet S)
{
	for(int i=NumSets;i>0;i--)
	{
		S[i]=0;	
	}	
} 


//�ϲ�
void SetUnion(DisjSet S,SetType Root1,SetType Root2)
{
	//��Root2�ҵ�Root1���棬˵��Root1�Ǹ��ڵ� 
	S[Root2]=Root1;
		
} 

//��һ��ֵ�Ľڵ㣬��Ӧ�ĸ��ڵ� 
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

//�ϲ�ʱ���Ż������С�Ĺ�����ȴ�����棩 
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
			S[Root1]--;//����--,��ʵ���ǽ�����ȼ���	
		}	
		S[Root1]=Root2; 
	} 
}


/*
·��ѹ����ʵ���Ͼ��Ǹı��ҵ��Ľڵ�ĸ��ڵ㣬����ֱ��ָ����ڵ� 
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
