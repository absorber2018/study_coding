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
	int sel,n; /* sel 选择输入， n 进栈或出栈数据的个数*/
	if ((s=( sequeue *)malloc(sizeof(sequeue)))==NULL)
	{
		printf("申请空间错误！\n");
		return 0;
	}
	initiate(s);
	printf("完成初始化 !\n");
	printf("\n请输入你的选择: 1:initiate,2:addqueue,3:delqueue,4:gettop,5:print,6:exit\nyour choice=");
	scanf("%d",&sel);
	while(sel!=6)
	{
		if(sel==1)
		{
			initiate(s );
			printf("完成初始化 !\n");
		}
		else if(sel==2)
		{
			printf("\n请输入待入队的数据个数:");
			scanf("%d",&n);
			addqueue(s,n);
			print(s);
		}
		else if(sel==3)
		{
			printf("\n请输入待出队的数据个数:");
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
			printf("你的选择是错误的!\n ");
	printf("\n请输入你的选择: 1:initiate,2:addqueue,3:delqueue,4:gettop,5:print,6:exit\nyour choice=");
		scanf("%d",&sel);
	}
	return 1;
}

void initiate (sequeue *s)/*初始化*/
{
	s->front=0;
	s->rear=0;
	s->count=0;
}

/*入队*/
int addqueue(sequeue *s,int n)
{
    int m;
    datatype x;
    m=n;
    if((s->rear+1)%MAX==s->front)
    {
        printf("队已满！");
        return 0;
    }
      while(n!=0){
        printf("请输入第%d个入队数据\n",m-n+1);
        scanf("%d",&x);
        s->rear=(s->rear+1)%MAX;
        s->queue[s->rear]=x;
        n--;
        s->count++;
        }
        return 1;
}

int delqueue(sequeue *s,int n)     /*出队*/
{
	int i=1;                       /*显示是第几个数据出队*/
	datatype x;                    /*出队的数据*/

		if(s->count==0)            /*判队空条件*/
		{
			printf("队空!\n");
			return 0;
		}
		else{
		while(n)
	{
		s->front=(s->front+1)%MAX;
        x= (s->queue[s->front]);
		printf("第%d个出队的数据为：%d\n",i,x);
		i++;
		n--;
		s->count--;
	}
	return 1;
		}
}

int gettop(sequeue *s )/*取队头元素*/
{
   int *t;
   datatype x;
   //s->front=(s->front+1)%MAX;
   x=s->queue[(s->front+1)%MAX];
   printf("队头数据为%d\n",x);
   return 0;
}

void print(sequeue *s)   /*显示输出*/
{
	int m,i;
	m=(s->front+1)% MAX;
	if(s->count==0)    /*判队空条件*/
		printf("队空!无显示输出!\n");
	else
	{
		for(i=1;i<=s->count;i++)
		{
			printf("queue[%d]数据为： %d\n",m,s->queue[m]);
			m=(m+1)%MAX;
		}
	}
}
