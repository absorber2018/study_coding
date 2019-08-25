#include<stdio.h>
#include<stdlib.h>
#define LIST_in_sq_SIZE 3
#define LIST_INCREMENT 3
typedef struct node
{

  char name[9];
  int num;
  int score;
  int tax;
}node;

typedef struct
{
  node *data;
  int len;
  int listsize;
}SeqList;

void in_seqList(SeqList *L,int n)
    {
        L->data=(node*)malloc(n*sizeof(node));
        if(!L->data) exit(1);//存储分配失败
           L->len= n;//空表长度为0
        L->listsize= n; //初始存储容量
    }

void in_sq(SeqList *L)
    {
        node *newbase;
        int i,n;
        printf("请输入选手个数:");
        scanf("%d",&n);
        in_seqList(L,n);
        printf("请输入选手姓名和编号\n");
        printf("姓名\t 编号\t\n");
        for(i=1;i<=L->len;i++)
        {
            scanf("%s%d",L->data[i].name,&L->data[i].num);
            L->data[i].score=L->data[i].tax =0;
        }
    }

void vote(SeqList *L)
    {
        int i,num;
        printf("请输入您要为几号选手投票:( 0 结束)\n");
        do
        {
            scanf("%d",&num);
            if(num < 0||num > L->len)
            {
                printf("你输入的编号错误请重新输入(1--%d)n",L->len);
                continue;
            }
            else
        for( i=1;i<=L->len;i++)
            if(L->data[i].num== num)
                L->data[i].score += 1;
        }while(num != 0);
    }

void sort(SeqList *L)
    {
        int i,j;
        int increment=L->len;
        do
    {
        increment=increment/3+1;
        for(i=increment+1;i<=L->len;i++)
        {
            if (L->data[i].score>L->data[i-increment].score)
            {
                L->data[0]=L->data[i] ;
                for(j=i-increment; j>0 && L->data[0].score > L->data[j].score;j-=increment)
                    L->data[j+increment]=L->data[j]; /* 记录后移，查找插入位置*/
                L->data[j+increment]=L->data[0];/* 插入*/
            }
        }
    }while(increment>1);
    }

/* 计算选手名次*/
void culculate(SeqList *L)
    {
        int i;
        L->data[1].tax=1;
        for(i=2 ;i<=L->len;i++)
            if(L->data[i-1].score==L->data[i].score)
                L->data[i].tax= L->data[i-1].tax;
            else
                L->data[i].tax= L->data[i-1].tax+1;
        system("cls");
        printf("正在计算选手名次请稍后\n 排序成功\n\n\n");

    }

void show(SeqList *L)
    {
        int i;
        system("cls");
        printf("姓名\t 编号\t 票数\t 名次\t\n");
        for(i=1;i<=L->len;i++)
        printf("%s\t%d\t%d\t%d\t\n",L->data[i].name,L->data[i].num,L->data[i].score,L->data[i].tax);
        printf("\n\n\n");

    }

void Save(SeqList *L)
    {
        FILE *fp;
        int i;
        char filename[20];
        printf("请输入目标文件名:\n");
        scanf("%s",&filename);
        fp=fopen(filename,"w");
        fprintf(fp,"姓名\t 编号\t 票数\t 名次\n");
        for(i=1;i<=L->len;i++)
        fprintf(fp,"%s\t%d\t%d\t%d\t\n",L->data[i].name,L->data[i].num,L->data[i].score,L->data[i].tax);
        fclose(fp);
        printf("数据已成功保存!\n");
    }

void Meun()
    {
        printf("**********************************\n");
        printf("****    1----输入选手信息(姓名、编号)    ****\n");
        printf("****    2----开始投票                     ****\n");
        printf("****    3----排序                         ****\n");
        printf("****    4----查看结果                     ****\n");
        printf("****    5----保存到文件                   ****\n");
        printf("****    0----退出                         ****\n");
        printf("**********************************\n");
    }


void main()
    {
        int sel;
        SeqList L;
        SeqList P;
        Meun();
        do
        {

            printf("请输入您的选择: ");
            scanf("%d",&sel) ;
            switch( sel)
                {
                    case 1:in_sq(&L);system("cls");Meun();break;
                    case 2:vote(&L);system("cls");Meun();break;
                    case 3:sort(&L);culculate(&L);
                             Meun();break;
                    case 4:show(&L);Meun();break;
                    case 5:Save(&L);system("cls");Meun();break;
                }
        }while(sel!=0);
    }


