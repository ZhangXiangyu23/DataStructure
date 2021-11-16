#include <stdio.h>
#include <stdlib.h>

#define  Error(Str)  FatalError(Str)
#define  FatalError(Str)  fprintf(stderr,"%s\n",Str),exit(1)
#define MaxDegree 100
int Max(int A,int B){return A>B?A:B;}

typedef struct Node{
	int CoeffArray[MaxDegree+1]; //���������洢����ʽϵ������ϵ��0��ϵ��100 
	int HighPower;      //����ʽ����ߴ���ϵ�� 
}* Polynomial;

//��ն���ʽ
void ZeroPolynomial(Polynomial Poly)
{
	for(int i=0;i<=MaxDegree;i++)
	{
		Poly->CoeffArray[i]=0;
	}
	Poly->HighPower=0;	
} 

//��������ʽ�ļӷ�
void AddPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial PolySum)
{
	//��ն���ʽPolySum
	ZeroPolynomial(PolySum); 
	//������������ʽ�Ӻ�֮��ģ���ߴ���
	PolySum->HighPower=Max(Poly1->HighPower,Poly2->HighPower);
	//������мӺ�
	for(int i=0;i<=PolySum->HighPower;i++)
	{
		PolySum->CoeffArray[i]=Poly1->CoeffArray[i]+Poly2->CoeffArray[i];	
	}	
} 

//��������ʽ�ĳ˷�
void MultPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial PolyProd)
{
	//��ն���ʽ
	ZeroPolynomial(PolyProd);
	//�˻�֮�����ߴ���
	PolyProd->HighPower=Poly1->HighPower+Poly2->HighPower;
	//�ж��Ƿ����
	if(PolyProd->HighPower>MaxDegree) 
	{
		Error("�ڴ�ռ����!\n");
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

//��ӡ����ʽ
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
	//����һ������ʽX+1
	Polynomial P=(Polynomial)malloc(sizeof(struct Node)); 
	P->HighPower=1;
	P->CoeffArray[1]=1;
	P->CoeffArray[0]=1;
	printf("����ʽP:");
	PrintPoly(P); 
	Polynomial Q=(Polynomial)malloc(sizeof(struct Node));  //sizeof()������дָ��������� 
	//�˷� 
	MultPolynomial(P,P,Q);
	PrintPoly(Q);
	//�ӷ� 
	AddPolynomial(Q,Q,P);
	PrintPoly(P); 
	return 0;
}




