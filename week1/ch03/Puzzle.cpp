#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dictsize 4    //字典中单词数 
#define wordsize 17   //单词最大长度 



//字谜
char puzzle[4][4]={{'t','h','i','s'},{'w','a','t','s'},{'o','a','h','g'},{'f','g','d','t'}};

//字典
char* dictionary[dictsize]={"this","two","fat","that"};
 
int main()
{
	//声明函数 
	int match(int x,int y,int dir,int n,char* word); 	
	char word[wordsize];
	for(int i=0;i<4;i++)  //行 
	{
		for(int j=0;j<4;j++)  //列
		{
			for(int dir=0;dir<8;dir++)  //八个方向
			{
				for(int n=1;n<=4;n++)  //查找单词的字符长度 
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


//匹配
int match(int x,int y,int dir,int n,char* word)
{
	 char str[wordsize];
	 int m=0;
	 for(int i=0;i<n;i++)  //要匹配的单词长度 
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
				y++;  break;  //向右移动
			case 1: 
				x++;  break;  //向下移动
			case 2: 
				y--;  break;  //向左移动
			case 3: 
				x--;  break;  //向上移动
			case 4: 
				x++;  y++;  break;  //从左上到右下 
			case 5: 
				x--;  y--;  break;  //从右下到左上 
			case 6: 
				x++;  y--;  break;  //从右上到左下
			case 7: 
				x--;  y++;  break;  //从左下到右上 
			default: 
				printf("direction error！");	 return 0;
	 	}
	 
	 
	 }
	 return 0;	  	
} 
