#include <stdio.h>
#include <malloc.h>
#define MAXLEN 50
typedef int datatype;

typedef struct
{
	datatype List[MAXLEN];
	int len;
}Seqlist;

Seqlist *initq()
{	Seqlist *L;
	L=(Seqlist*)malloc(sizeof(Seqlist));
	L->len=0;
	return L;
}

int insertq(Seqlist *la,int n)
{
    int i,j,p=0;
    datatype x;
    printf("����������λ��\n");
    scanf("%d",&i);
    la->len=la->len+n;
while(n)
    {if(la->len>=MAXLEN-1)
        {printf("���������޷����в��룡");
        return 0;}
    else
        if(i<0)
        {printf("����λ�ò��Ϸ���");
        return 0;}
    else
        {printf("����������������");
           scanf("%d",&x);
           for(j=i+p;j<la->len;j++)
         la->List[j+1]=la->List[j];
         }
         la->List[i+p]=x;
         n--;
         p++;}
        return 1;
}

int deleteq(Seqlist *la,int n)
{
	int i,j;
	while(n)
	{
		if (la->len==0)
		{
			printf ("\n ��գ�����ɾ����\n");
			return 0;
		}
		printf("������ɾ����λ��:");
		scanf("%d",&i);
		if (i<1||i>la->len)
		{
			printf ("\n ɾ��λ�ô���!\n");
		}
		else
		{
			for ( j=i+1; j<=la->len; j++)
				la->List[j-1]=la->List[j];
			la->len--;
			n--;
		}
	}
	printf("ɾ����ɣ�\n");
	return 1;
}

int print (Seqlist *la)
{
	int m;
	if (la->len==0)
	{
		printf("˳���Ϊ��!\n");
		return 0;
	}
	else
	{
		printf("��ǰ��˳���Ϊ:\n");
		for(m=1;m<=la->len;m++)
			printf("List[%d]=%d \n ",m,la->List[m]);
		printf("\n��Ϊ%d\n",la->len);
		return 1;
	}
}
void main()
{
	Seqlist *la;
	int s,n;
	printf("���������ѡ��: \n 1---initiate 2---insert 3---delete 4---print 5---exit\nyour choice =");
	scanf("%d",&s);
	while(s!=5)
	{
		if(s==1)
		{
		  la=initq ();
        printf("��ɳ�ʼ�� !\n");
		}
		else if(s==2)
		{
			printf("���������������ݸ���:");
			scanf("%d",&n);
			insertq(la,n);
			print(la);
		}
		else if(s==3)
		{
			printf("�������ɾ�������ݸ���:");
			scanf("%d",&n);
			deleteq(la,n);
			print(la);
		}
		else if(s==4)
		{
			print(la);
		}

		else
	        printf("���ѡ���Ǵ����!\n ");

		printf("���������ѡ��: 1---initiate 2---insert 3---delete 4---print 5---exit\nyour choice =");
		scanf("%d",&s);
	}
}
