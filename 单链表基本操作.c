#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}slnode;
int l;

slnode *initiate ( );
int append(slnode *h);
int clean(slnode*h);
int Return(slnode *h,int n);
int insert(slnode *h, int n);
int deletet(slnode *h, int n);
slnode * search(slnode *h, datatype x);
void print(slnode *h);

void main()
{
	slnode *h,*s;
	int sel,n,x;

	printf("���������ѡ��: 1---initiate 2---append 3---insert 4---delete  5--- search 6---print 7---exit 8---clean 9---return\nyour choice =");
	scanf("%d",&sel);
	while(sel!=7)
	{
		if(sel==1)
		{
			h=initiate( );
		}
		else if(sel==2)
		{
			append(h);
			print(h);
		}
		else if(sel==3)
		{
			printf("�����������Ľ�����:");
		    scanf("%d",&n);
		    insert(h,n);
		    print(h);
		}
		else if(sel==4)
		{
			printf("�������ɾ���Ľ�����:");
			scanf("%d",&n);
			deletet(h,n);
			print(h);
		}
		else if(sel==5)
		{
			printf("������Ҫ���ҵĽ������:");
			scanf("%d",&x);
			s=search(h,x);
			if(s!=NULL)
				printf("���ҳɹ������λ��Ϊ��%d\n",s->data);
		}
		else if(sel==6)
		{
			print(h);
		}
		else if(sel==8)
        {
            clean(h);
            print(h);
        }
        else if(sel==9)
        {
            Return(h,n);
            print(h);
        }
		else
			printf("���ѡ���Ǵ����!\n ");
		printf("���������ѡ��: 1---initiate 2---append 3---insert 4---delete  5--- search 6---print 7---exit 8---clean 9---return\nyour choice =");
		scanf("%d",&sel);
	}
}

/*��ʼ��*/
slnode *initiate( )
 { slnode *head;
    head = (slnode *)malloc(sizeof(slnode));
    head->next = NULL;
    return (head);
 }

/*����������*/
int append (slnode *h)
{
	slnode *p,*q;
	int n,i;         /* n ������������Ľ����*/
	datatype a[10];       /* a �����������������*/
	if(h==NULL)
	{
		printf("������δ��ʼ����\n");
		return 0;
	}
	printf("�����뵥��������Ľ����n=");
	scanf("%d",&n);
	printf("�������������������ֵ:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=h;
	for(i=0;i<=n-1;i++)
	{
		if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
		{
			printf("�½��ռ�����ʧ�ܣ�\n");
			return 0;
		}
		q->data=a[i];
		q->next=NULL;
		p->next=q;
		p=q;
	}
	return 1;
}

/*����*/
int  insert (slnode *h, int n)
{
	slnode *p, *q;
	int i, j;              /* i �������λ��*/
	datatype x;          /* x �����������*/
	while(n)
	{
		printf("������������λ�ü�������ݣ�");
		scanf("%d%d",&i,&x);
        p=h;
        j=0;
		while((p->next!=NULL)&&(j<i-1))
		{
			p=p->next;
			j++;
		}
		if(j!=i-1)
		{
			printf("\n����λ�ò�����\n");
		}
		else
		{
			if ((q=( slnode * )malloc(sizeof(slnode)))==NULL)
			{
				printf("�½��ռ�����ʧ�ܣ�\n");
				return 0;
			}
			q->data=x;
			q->next=p->next;
			p->next=q;
			n--;
		}
	}
	printf("�������!\n");
	return 1;
}

/*ɾ��*/
int deletet (slnode *h, int n)
{
	slnode *p,*s;
	int m;            /*m ���汻ɾ�����ĸ��� */
	datatype x;          /* x ��ɾ������ǰһ����������*/
	p=h;
	m=n;
	while(n!=0)
	{
		printf("�������%d����ɾ������ǰһ���������ݣ�",m-n+1);
		scanf("%d",&x);
		s=search(h,x);
		if(s==NULL)
			continue;
		p=s->next;
		s->next=p->next;
		free(p);
		n--;
	}
	return 1;
}

/*����*/
slnode * search(slnode *h, datatype x)
{
   slnode *p=h->next;
   while(p!=NULL&&p->data!=x)
   {
       p=p->next;
   }
   return p;
}

/*��ʾ���*/
void print(slnode *h)
{
    slnode *p=h->next;
    while(p!=NULL)
{
    printf("%d",p->data);
    p=p->next;
}
    printf("\n");
}
int clean(slnode *h)
{
    slnode *p,*q,*t;
    int i=0;
    p=h->next;
    q=p->next;
    while(p!=NULL)
    {
        while(q!=NULL)
        {t=p;
        if(p->data==q->data)
           {
            for(;i>0;i--)
            t=t->next;
            t->next=q->next;
            free(q);}
         else
          q=q->next;
          i++;}
          p=p->next;
          q=p->next;
    }
    return 0;
}
int Return(slnode *h,int n)
{
    slnode *p,*t;
    int x,i;
    p=h->next;
    i=n/2;
    x=p->data;
    while(t!=NULL)
    {t=p->next;
     t=t->next;}
    p->data=t->data;
    t->data=x;
      /*for(;i>0;i--)
    {

    }*/
   return 0;
}
