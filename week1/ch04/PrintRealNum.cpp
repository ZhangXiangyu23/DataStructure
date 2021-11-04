#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//函数声明
void PrintOut(int n);
void  PrintDigit(int n); 

 
int main()
{

	double a;
	printf("请输入一个实数\n");
	scanf("%lf",&a);
	
	printf("输出:\n"); 
	//符号处理 
	if(a<0)
	{
		printf("-");
	}
	//整数部分 
	int intpart=(int)a;
	PrintOut(abs(intpart));
	
	//小数部分 
	double decpart=a-intpart; 
	//有小数部分时，转化成整数输出 
	if(decpart!=0)
	{
		printf(".");
		//小数后六位转化成整数
		decpart*=1000000;	
		PrintOut(abs((int)decpart)); 
	}
	
	return 0;	
}


//输出整数 
void PrintOut(int n)
{
	if(n>=10)
		PrintOut(n/10);
	PrintDigit(n%10);	
}


//PrintDigit函数:只能输出单个数字 
void  PrintDigit(int n)
{
	printf("%d",n);	
}


 
 
 
  
