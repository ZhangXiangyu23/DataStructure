#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dictsize 4    //�ֵ��е����� 
#define wordsize 17   //������󳤶� 



//����
char puzzle[4][4]={{'t','h','i','s'},{'w','a','t','s'},{'o','a','h','g'},{'f','g','d','t'}};

//�ֵ�
char* dictionary[dictsize]={"this","two","fat","that"};
 
int main()
{
	//�������� 
	int match(int x,int y,int dir,int n,char* word); 	
	char word[wordsize];
	for(int i=0;i<4;i++)  //�� 
	{
		for(int j=0;j<4;j++)  //��
		{
			for(int dir=0;dir<8;dir++)  //�˸�����
			{
				for(int n=1;n<=4;n++)  //���ҵ��ʵ��ַ����� 
				{
					if(match(i,j,dir,n,word))
					{
						printf("%s\n",word);
						break;				
					} 
				}	
			}	
		} 
	}
	
	return 0;
} 


//ƥ��
int match(int x,int y,int dir,int n,char* word)
{
	 char str[wordsize];
	 int m=0;
	 for(int i=0;i<n;i++)  //Ҫƥ��ĵ��ʳ��� 
	 {
	 	str[m]=puzzle[x][y];
	 	str[m+1]='\0';
	 	
	 	for(int j=0;j<dictsize;j++)
	 	{
	 		if(strcmp(str,dictionary[j])==0)
	 		{
	 			strcpy(word,dictionary[j]);
				return 1;	
			}
		
		}
		
		m++;
	 	switch(dir)
	 	{
	 		case 0: 
				y++;  break;  //�����ƶ�
			case 1: 
				x++;  break;  //�����ƶ�
			case 2: 
				y--;  break;  //�����ƶ�
			case 3: 
				x--;  break;  //�����ƶ�
			case 4: 
				x++;  y++;  break;  //�����ϵ����� 
			case 5: 
				x--;  y--;  break;  //�����µ����� 
			case 6: 
				x++;  y--;  break;  //�����ϵ�����
			case 7: 
				x--;  y++;  break;  //�����µ����� 
			default: 
				printf("direction error��");	 return 0;
	 	}
	 
	 
	 }
	 return 0;	  	
} 
