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
        if(!L->data) exit(1);//�洢����ʧ��
           L->len= n;//�ձ���Ϊ0
        L->listsize= n; //��ʼ�洢����
    }

void in_sq(SeqList *L)
    {
        node *newbase;
        int i,n;
        printf("������ѡ�ָ���:");
        scanf("%d",&n);
        in_seqList(L,n);
        printf("������ѡ�������ͱ��\n");
        printf("����\t ���\t\n");
        for(i=1;i<=L->len;i++)
        {
            scanf("%s%d",L->data[i].name,&L->data[i].num);
            L->data[i].score=L->data[i].tax =0;
        }
    }

void vote(SeqList *L)
    {
        int i,num;
        printf("��������ҪΪ����ѡ��ͶƱ:( 0 ����)\n");
        do
        {
            scanf("%d",&num);
            if(num < 0||num > L->len)
            {
                printf("������ı�Ŵ�������������(1--%d)n",L->len);
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
                    L->data[j+increment]=L->data[j]; /* ��¼���ƣ����Ҳ���λ��*/
                L->data[j+increment]=L->data[0];/* ����*/
            }
        }
    }while(increment>1);
    }

/* ����ѡ������*/
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
        printf("���ڼ���ѡ���������Ժ�\n ����ɹ�\n\n\n");

    }

void show(SeqList *L)
    {
        int i;
        system("cls");
        printf("����\t ���\t Ʊ��\t ����\t\n");
        for(i=1;i<=L->len;i++)
        printf("%s\t%d\t%d\t%d\t\n",L->data[i].name,L->data[i].num,L->data[i].score,L->data[i].tax);
        printf("\n\n\n");

    }

void Save(SeqList *L)
    {
        FILE *fp;
        int i;
        char filename[20];
        printf("������Ŀ���ļ���:\n");
        scanf("%s",&filename);
        fp=fopen(filename,"w");
        fprintf(fp,"����\t ���\t Ʊ��\t ����\n");
        for(i=1;i<=L->len;i++)
        fprintf(fp,"%s\t%d\t%d\t%d\t\n",L->data[i].name,L->data[i].num,L->data[i].score,L->data[i].tax);
        fclose(fp);
        printf("�����ѳɹ�����!\n");
    }

void Meun()
    {
        printf("**********************************\n");
        printf("****    1----����ѡ����Ϣ(���������)    ****\n");
        printf("****    2----��ʼͶƱ                     ****\n");
        printf("****    3----����                         ****\n");
        printf("****    4----�鿴���                     ****\n");
        printf("****    5----���浽�ļ�                   ****\n");
        printf("****    0----�˳�                         ****\n");
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

            printf("����������ѡ��: ");
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


