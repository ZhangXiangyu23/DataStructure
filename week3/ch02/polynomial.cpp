#include <stdio.h>
#include <stdlib.h>

#define  Error(Str)  FatalError(Str)
#define  FatalError(Str)  fprintf(stderr,"%s\n",Str),exit(1)
#define MaxDegree 100
int Max(int A,int B){return A>B?A:B;}

typedef struct Node{
	int CoeffArray[MaxDegree+1]; //用数组来存储多项式系数，从系数0到系数100 
	int HighPower;      //多项式的最高次项系数 
}* Polynomial;

//清空多项式
void ZeroPolynomial(Polynomial Poly)
{
	for(int i=0;i<=MaxDegree;i++)
	{
		Poly->CoeffArray[i]=0;
	}
	Poly->HighPower=0;	
} 

//两个多项式的加法
void AddPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial PolySum)
{
	//清空多项式PolySum
	ZeroPolynomial(PolySum); 
	//先求两个多项式加和之后的，最高次幂
	PolySum->HighPower=Max(Poly1->HighPower,Poly2->HighPower);
	//各项进行加和
	for(int i=0;i<=PolySum->HighPower;i++)
	{
		PolySum->CoeffArray[i]=Poly1->CoeffArray[i]+Poly2->CoeffArray[i];	
	}	
} 

//两个多项式的乘法
void MultPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial PolyProd)
{
	//清空多项式
	ZeroPolynomial(PolyProd);
	//乘积之后的最高次幂
	PolyProd->HighPower=Poly1->HighPower+Poly2->HighPower;
	//判断是否溢出
	if(PolyProd->HighPower>MaxDegree) 
	{
		Error("内存空间溢出!\n");
	}
	else
	{
		for(int i=0;i<=Poly1->HighPower;i++)
		{
			for(int j=0;j<=Poly2->HighPower;j++)
			{
				PolyProd->CoeffArray[i+j]+=Poly1->CoeffArray[i]*Poly2->CoeffArray[j];
			}
		}
	}
}

//打印多项式
void PrintPoly(Polynomial Q)
{
	for(int i=Q->HighPower;i>0;i--)
	{
		printf("%dX^%d+",Q->CoeffArray[i],i);	
	}
	printf("%d\n",Q->CoeffArray[0]);	
} 



int main()
{
	//创建一个多项式X+1
	Polynomial P=(Polynomial)malloc(sizeof(struct Node)); 
	P->HighPower=1;
	P->CoeffArray[1]=1;
	P->CoeffArray[0]=1;
	printf("多项式P:");
	PrintPoly(P); 
	Polynomial Q=(Polynomial)malloc(sizeof(struct Node));  //sizeof()括号中写指针会有问题 
	//乘法 
	MultPolynomial(P,P,Q);
	PrintPoly(Q);
	//加法 
	AddPolynomial(Q,Q,P);
	PrintPoly(P); 
	return 0;
}




