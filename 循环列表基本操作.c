#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 6

typedef  int  datatype;
typedef  struct
{
	datatype queue[MAX];
	int front;
	int rear;
	int count;
} sequeue;

void initiate(sequeue *s );
int  addqueue (sequeue *s, int n);
int  delqueue (sequeue *s, int n );
int  gettop(sequeue *s );
void print(sequeue *s );

int main()
{
	sequeue *s;
	int sel,n; /* sel ѡ�����룬 n ��ջ���ջ���ݵĸ���*/
	if ((s=( sequeue *)malloc(sizeof(sequeue)))==NULL)
	{
		printf("����ռ����\n");
		return 0;
	}
	initiate(s);
	printf("��ɳ�ʼ�� !\n");
	printf("\n���������ѡ��: 1:initiate,2:addqueue,3:delqueue,4:gettop,5:print,6:exit\nyour choice=");
	scanf("%d",&sel);
	while(sel!=6)
	{
		if(sel==1)
		{
			initiate(s );
			printf("��ɳ�ʼ�� !\n");
		}
		else if(sel==2)
		{
			printf("\n���������ӵ����ݸ���:");
			scanf("%d",&n);
			addqueue(s,n);
			print(s);
		}
		else if(sel==3)
		{
			printf("\n����������ӵ����ݸ���:");
			scanf("%d",&n);
			delqueue(s,n);
			print(s);
		}
		else if(sel==4)
		{
			gettop(s);
			print(s);
		}
		else if(sel==5)
			print(s);
		else
			printf("���ѡ���Ǵ����!\n ");
	printf("\n���������ѡ��: 1:initiate,2:addqueue,3:delqueue,4:gettop,5:print,6:exit\nyour choice=");
		scanf("%d",&sel);
	}
	return 1;
}

void initiate (sequeue *s)/*��ʼ��*/
{
	s->front=0;
	s->rear=0;
	s->count=0;
}

/*���*/
int addqueue(sequeue *s,int n)
{
    int m;
    datatype x;
    m=n;
    if((s->rear+1)%MAX==s->front)
    {
        printf("��������");
        return 0;
    }
      while(n!=0){
        printf("�������%d���������\n",m-n+1);
        scanf("%d",&x);
        s->rear=(s->rear+1)%MAX;
        s->queue[s->rear]=x;
        n--;
        s->count++;
        }
        return 1;
}

int delqueue(sequeue *s,int n)     /*����*/
{
	int i=1;                       /*��ʾ�ǵڼ������ݳ���*/
	datatype x;                    /*���ӵ�����*/

		if(s->count==0)            /*�жӿ�����*/
		{
			printf("�ӿ�!\n");
			return 0;
		}
		else{
		while(n)
	{
		s->front=(s->front+1)%MAX;
        x= (s->queue[s->front]);
		printf("��%d�����ӵ�����Ϊ��%d\n",i,x);
		i++;
		n--;
		s->count--;
	}
	return 1;
		}
}

int gettop(sequeue *s )/*ȡ��ͷԪ��*/
{
   int *t;
   datatype x;
   //s->front=(s->front+1)%MAX;
   x=s->queue[(s->front+1)%MAX];
   printf("��ͷ����Ϊ%d\n",x);
   return 0;
}

void print(sequeue *s)   /*��ʾ���*/
{
	int m,i;
	m=(s->front+1)% MAX;
	if(s->count==0)    /*�жӿ�����*/
		printf("�ӿ�!����ʾ���!\n");
	else
	{
		for(i=1;i<=s->count;i++)
		{
			printf("queue[%d]����Ϊ�� %d\n",m,s->queue[m]);
			m=(m+1)%MAX;
		}
	}
}
