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
    printf("请输入插入的位置\n");
    scanf("%d",&i);
    la->len=la->len+n;
while(n)
    {if(la->len>=MAXLEN-1)
        {printf("表已满，无法进行插入！");
        return 0;}
    else
        if(i<0)
        {printf("输入位置不合法！");
        return 0;}
    else
        {printf("请输入待插入的数据");
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
			printf ("\n 表空，不能删除！\n");
			return 0;
		}
		printf("请输入删除的位置:");
		scanf("%d",&i);
		if (i<1||i>la->len)
		{
			printf ("\n 删除位置错误!\n");
		}
		else
		{
			for ( j=i+1; j<=la->len; j++)
				la->List[j-1]=la->List[j];
			la->len--;
			n--;
		}
	}
	printf("删除完成！\n");
	return 1;
}

int print (Seqlist *la)
{
	int m;
	if (la->len==0)
	{
		printf("顺序表为空!\n");
		return 0;
	}
	else
	{
		printf("当前的顺序表为:\n");
		for(m=1;m<=la->len;m++)
			printf("List[%d]=%d \n ",m,la->List[m]);
		printf("\n表长为%d\n",la->len);
		return 1;
	}
}
void main()
{
	Seqlist *la;
	int s,n;
	printf("请输入你的选择: \n 1---initiate 2---insert 3---delete 4---print 5---exit\nyour choice =");
	scanf("%d",&s);
	while(s!=5)
	{
		if(s==1)
		{
		  la=initq ();
        printf("完成初始化 !\n");
		}
		else if(s==2)
		{
			printf("请输入待插入的数据个数:");
			scanf("%d",&n);
			insertq(la,n);
			print(la);
		}
		else if(s==3)
		{
			printf("请输入待删除的数据个数:");
			scanf("%d",&n);
			deleteq(la,n);
			print(la);
		}
		else if(s==4)
		{
			print(la);
		}

		else
	        printf("你的选择是错误的!\n ");

		printf("请输入你的选择: 1---initiate 2---insert 3---delete 4---print 5---exit\nyour choice =");
		scanf("%d",&s);
	}
}
