#include <stdio.h>
#include <stdlib.h>

//�ö���ʵ��ѧ����Ϣ����ϵͳ 
struct Node{
	int StuNum;//ѧ�� 
	char Name[20]; //����
	char  Sex;  //�Ա�   m�����У�f����Ů 
	int Age; //���� 
	struct Node* Next;
};

typedef struct Node* Queue;
typedef struct Node* QNode;

//����ͷ���Ķ��� 
Queue CreatQueue()
{
	Queue Q=(Queue)malloc(sizeof(struct Node));
	Q->Next=NULL;
	return Q; 
}


//�ж��Ƿ�����Ƿ�Ϊ��
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


//Ѱ�Ҷ�βԪ��
QNode Rear(Queue Q)
{
	QNode v=Q;
	while(v->Next!=NULL)
	{
		v=v->Next;	
	}
	return v;	
} 



//���
Queue EnQueue(Queue Q)
{
	QNode p=(QNode)malloc(sizeof(struct Node));
	printf("������ѧ��:\n");
	scanf("%d",&p->StuNum);
	printf("����������:\n");
	scanf("%s",p->Name);
	getchar();
	printf("�������Ա�:��m�����У�f����Ů��\n");
	scanf("%c",&p->Sex);
	printf("����������:\n");
	scanf("%d",&p->Age);
	
	QNode r=Rear(Q);
	p->Next=NULL;
	r->Next=p;
	return Q;
} 


//����
Queue DeQueue(Queue Q)
{
	QNode p=Q->Next;
	Q->Next=p->Next;
	free(p);
	return Q; 
}




//���������Ϣ
void PrintQueue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("�ö���Ϊ��!\n");	
	}
	else
	{
		QNode d=Q->Next;
		while(d!=NULL)
		{
			printf("ѧ��:%d\t����:%s\t�Ա�:%c(m�����У�f����Ů)\t����:%d\n",d->StuNum,d->Name,d->Sex,d->Age);
			d=d->Next;	
		}	
	}	
}

 
QNode Findprevious(Queue Q,int StuNum)
{
	if(IsEmpty(Q))
	{
		printf("�ö���Ϊ��!\n");
		exit(0);	
	}
	QNode j=Q;
	while(j->Next->StuNum!=StuNum)   //����j->NextΪ�գ��Ͳ�����->,����ֱ�ӱ��� 
	{
		j=j->Next;
		if(j->Next==NULL)
		{
			return NULL;
		}
	}
	return j;
} 

//����ѧ�Ž���ɾ��ĳ����¼
bool Delete(Queue Q,int StuNum)
{
	
	if(Findprevious(Q,StuNum)==NULL)
	{
		printf("�޴�����¼��������ȷ��!\n");
		return false;	
	}
	QNode u=Findprevious(Q,StuNum);
	QNode k=u->Next;
	u->Next=k->Next;
	free(k);
	return true;
}

//������Ž��в�����Ϣ
QNode Query(int StuNum,Queue Q)
{
	QNode y;
	if(IsEmpty(Q))
	{
		printf("�˶���Ϊ��!\n");
		return 0;	
	}
	else
	{
		y=Q->Next;
		while(y->StuNum!=StuNum)  //�����˿�ָ��ĵ�->  �ͻᱨ��    
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
	//��������
	Queue Q=CreatQueue();
//	if(Q==NULL)
//	{
//		printf("�ڴ����ʧ�ܣ���������ʧ��!\n");
//		exit(0);	
//	}
//	else
//	{
//		printf("�ڴ����ɹ�!\n");	
//	}
	
	//¼����Ϣ
	printf("*************************************ѧ����Ϣ����ϵͳ***********************************************\n"); 
	while(1)
	{
		printf("��B��ʼ¼��,��E����¼��!\n");
		printf("��S�鿴ϵͳ����Ϣ!\n");
		printf("��Dִ��ɾ������\n");
		printf("��F����ѧ�Ž��в���\n"); 
		char m=getchar();
		if(m=='F')
		{
			printf("����Ҫ���ҵ�ѧ��:\n");
			int n;
			scanf("%d",&n);
			QNode k=Query(n,Q);
			if(k==NULL)
			{
				printf("ϵͳ��û�в鵽�����Ϣ!\n");	
			}
			else
			{
				printf("ѧ��:%d\t����:%s\t�Ա�:%c(m�����У�f����Ů)\t����:%d\n",k->StuNum,k->Name,k->Sex,k->Age);	
			}		
		} 
		if(m=='D')
		{
			int DNum;
			printf("������Ҫɾ���ļ�¼��ѧ��:\n");
			scanf("%d",&DNum);
			if(Delete(Q,DNum))
			{
				printf("ɾ���ɹ�!\n");
			}
			else
			{
				printf("ɾ��ʧ��!\n");
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
				printf("��E�˳�¼�룬���س�����¼��!\n");
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
