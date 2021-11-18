#include <stdio.h>
#include <stdlib.h>

//用队列实现学生信息管理系统 
struct Node{
	int StuNum;//学号 
	char Name[20]; //姓名
	char  Sex;  //性别   m代表男，f代表女 
	int Age; //年龄 
	struct Node* Next;
};

typedef struct Node* Queue;
typedef struct Node* QNode;

//带有头结点的队列 
Queue CreatQueue()
{
	Queue Q=(Queue)malloc(sizeof(struct Node));
	Q->Next=NULL;
	return Q; 
}


//判断是否队列是否为空
bool IsEmpty(Queue Q)
{
	if(Q->Next==NULL)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}


//寻找队尾元素
QNode Rear(Queue Q)
{
	QNode v=Q;
	while(v->Next!=NULL)
	{
		v=v->Next;	
	}
	return v;	
} 



//入队
Queue EnQueue(Queue Q)
{
	QNode p=(QNode)malloc(sizeof(struct Node));
	printf("请输入学号:\n");
	scanf("%d",&p->StuNum);
	printf("请输入姓名:\n");
	scanf("%s",p->Name);
	getchar();
	printf("请输入性别:（m代表男，f代表女）\n");
	scanf("%c",&p->Sex);
	printf("请输入年龄:\n");
	scanf("%d",&p->Age);
	
	QNode r=Rear(Q);
	p->Next=NULL;
	r->Next=p;
	return Q;
} 


//出队
Queue DeQueue(Queue Q)
{
	QNode p=Q->Next;
	Q->Next=p->Next;
	free(p);
	return Q; 
}




//输出队列信息
void PrintQueue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("该队列为空!\n");	
	}
	else
	{
		QNode d=Q->Next;
		while(d!=NULL)
		{
			printf("学号:%d\t姓名:%s\t性别:%c(m代表男，f代表女)\t年龄:%d\n",d->StuNum,d->Name,d->Sex,d->Age);
			d=d->Next;	
		}	
	}	
}

 
QNode Findprevious(Queue Q,int StuNum)
{
	if(IsEmpty(Q))
	{
		printf("该队列为空!\n");
		exit(0);	
	}
	QNode j=Q;
	while(j->Next->StuNum!=StuNum)   //出现j->Next为空，就不能用->,这样直接报错 
	{
		j=j->Next;
		if(j->Next==NULL)
		{
			return NULL;
		}
	}
	return j;
} 

//根据学号进行删除某条记录
bool Delete(Queue Q,int StuNum)
{
	
	if(Findprevious(Q,StuNum)==NULL)
	{
		printf("无此条记录，请重新确认!\n");
		return false;	
	}
	QNode u=Findprevious(Q,StuNum);
	QNode k=u->Next;
	u->Next=k->Next;
	free(k);
	return true;
}

//根据序号进行查找信息
QNode Query(int StuNum,Queue Q)
{
	QNode y;
	if(IsEmpty(Q))
	{
		printf("此队列为空!\n");
		return 0;	
	}
	else
	{
		y=Q->Next;
		while(y->StuNum!=StuNum)  //出现了空指针的的->  就会报错    
		{
			y=y->Next;
			if(y==NULL)
			{
				return NULL;
			}
		}
	}
	return y;
} 


 



int main()
{
	//创建队列
	Queue Q=CreatQueue();
//	if(Q==NULL)
//	{
//		printf("内存分配失败，创建队列失败!\n");
//		exit(0);	
//	}
//	else
//	{
//		printf("内存分配成功!\n");	
//	}
	
	//录入信息
	printf("*************************************学生信息管理系统***********************************************\n"); 
	while(1)
	{
		printf("按B开始录入,按E结束录入!\n");
		printf("按S查看系统内信息!\n");
		printf("按D执行删除操作\n");
		printf("按F根据学号进行查找\n"); 
		char m=getchar();
		if(m=='F')
		{
			printf("输入要查找的学号:\n");
			int n;
			scanf("%d",&n);
			QNode k=Query(n,Q);
			if(k==NULL)
			{
				printf("系统中没有查到相关信息!\n");	
			}
			else
			{
				printf("学号:%d\t姓名:%s\t性别:%c(m代表男，f代表女)\t年龄:%d\n",k->StuNum,k->Name,k->Sex,k->Age);	
			}		
		} 
		if(m=='D')
		{
			int DNum;
			printf("请输入要删除的记录的学号:\n");
			scanf("%d",&DNum);
			if(Delete(Q,DNum))
			{
				printf("删除成功!\n");
			}
			else
			{
				printf("删除失败!\n");
			}
		}
		if(m=='S')
		{
			PrintQueue(Q);
		}
		if(m=='B')
		{
			while(m!='E')
			{
				EnQueue(Q);
				printf("按E退出录入，按回车继续录入!\n");
				getchar();
				m=getchar();	
				if(m=='E')
				{
					break;	
				} 
			}
		}
		getchar();
		printf("------------------------------------------\n");
	}

	
	
	 
} 
