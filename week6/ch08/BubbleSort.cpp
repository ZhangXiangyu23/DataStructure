#include <stdio.h>

void Show(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

//√∞≈›≈≈–Ú 
void BubbleSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int term=a[j];
				a[j]=a[j+1];
				a[j+1]=term;
			}
		}
	}
}


//—°‘Ò≈≈–Ú
void SelectSort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int term=a[j];
				a[j]=a[i];
				a[i]=term;
			}
		}	
	}		
} 

int main()
{
	int a[6]={12,0,13,-5,99,14};
	printf("≈≈–Ú÷Æ«∞:\n");
	Show(a,6);	
	printf("\n");
//	BubbleSort(a,6);
	SelectSort(a,6);
	printf("≈≈–Ú÷Æ∫Û:\n");
	Show(a,6);
} 
