#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��������
void PrintOut(int n);
void  PrintDigit(int n); 

 
int main()
{

	double a;
	printf("������һ��ʵ��\n");
	scanf("%lf",&a);
	
	printf("���:\n"); 
	//���Ŵ��� 
	if(a<0)
	{
		printf("-");
	}
	//�������� 
	int intpart=(int)a;
	PrintOut(abs(intpart));
	
	//С������ 
	double decpart=a-intpart; 
	//��С������ʱ��ת����������� 
	if(decpart!=0)
	{
		printf(".");
		//С������λת��������
		decpart*=1000000;	
		PrintOut(abs((int)decpart)); 
	}
	
	return 0;	
}


//������� 
void PrintOut(int n)
{
	if(n>=10)
		PrintOut(n/10);
	PrintDigit(n%10);	
}


//PrintDigit����:ֻ������������� 
void  PrintDigit(int n)
{
	printf("%d",n);	
}


 
 
 
  
