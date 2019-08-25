#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node*next;

}lNode;
typedef struct
{
    lNode *front,*rear;
}lNodeQueue;
void creat_Line(lNodeQueue **q)
{
  lNode *p;
  *q=(lNodeQueue*)malloc(sizeof(lNodeQueue));
  p=(lNode*)malloc(sizeof(lNode));
  p->next=NULL;
  (*q)->front=p;
  (*q)->rear=p;
}
void in_Line(lNodeQueue *q,int x)
{
    lNode *p;
   p=(lNode*)malloc(sizeof(lNode));
   p->data=x;
   p->next=q->front->next;
   q->rear->next=p;
   q->rear=p;
}
void out_Line(lNodeQueue *q,int x)
{
    lNode *p,*t;
	p=q->front->next;
    if(p->data==x)
	{
        q->front->next=p->next;
        q->rear->next=p->next;
        free(p);}
    else
    {
         while(p!=NULL&&p->next->data!=x)
            p=p->next;
            t=p->next;
		    if(t->next==q->front->next)
		       q->rear->next=p;
            p->next=t->next;
            free(p);
	}
	if(q->front->next==NULL)
           printf("�޷����");
}
int nan,nv,time=1;
lNode *maleNode,*famleNode;
lNodeQueue *male,*famle;
int nantemp,nvtemp;
int menu()
{
     int temp,choice;


    printf("                                  ������\n\n");
    printf("        1.�����������\n        2.��ʼ���\n        3.��;�˳����룬��ʽ���к��룬Ů���루����һ��˳���������棩\n        4.��;������룬��ʽ���к��룬Ů���루����һ��û����;���룬������棩\n        5.�������\n ");
    printf("\t\t\t���������ѡ��");
    scanf("%d",&choice);
    while(choice)
    {
        if(choice==1)
		{printf("\t\t\t��ֱ�������Ů��������������Ů��\t");
               scanf("%d,%d",&nan,&nv);
               creat_Line(&male);
               creat_Line(&famle);

				temp=1;
				while(temp<=nan)
                 {

                    in_Line(male,temp);
                    temp++;
                 }
                temp=1;
               while(temp<=nv)
                 {

                    in_Line(famle,temp);
                    temp++;
                 }
		      maleNode=male->front->next;
              famleNode=famle->front->next;
                system("cls");
                menu();
		}
        else if(choice==2)

		{
			system("cls");

			temp=nv<nan?nv:nan ;
            printf("\t\t��%d�����",time) ;
			time++;
                 while(temp>0)
                 {
                 printf(" %d,%d ",maleNode->data,famleNode->data);
                 maleNode=maleNode->next;
                 famleNode=famleNode->next;
                 temp--;
                 }
				 printf("\n");
                 menu();
        }
         else if(choice==3)
		 {
			 printf("\t\t\t��ֱ������˳�����Ů�����룻������Ů��\t\t\t");
			 scanf("%d,%d",&nantemp,&nvtemp);

               if(nantemp>0)
			   {
				   out_Line(male,nantemp);
                   nan--;

			   }
               if(nvtemp>0)
			   {
				   out_Line(famle,nvtemp);
                   nv--;

			   }
			   maleNode=male->front->next;
              famleNode=famle->front->next;
			    system("cls");
                menu();
		 }
       else if(choice==4)
	   {
		   printf("\t\t\t��ֱ�����������Ů����ţ�������Ů��\t\t\t");
		   scanf("%d,%d",&nantemp,&nvtemp);
		      if(nantemp>0)
               {
                   nan++;
                   in_Line(male,nantemp);

               }
              if(nvtemp>0)
               {
                    nv++;
                    in_Line(famle,nvtemp);

               }
			  maleNode=male->front->next;
              famleNode=famle->front->next;
              system("cls");
              menu();
	   }
        else if(choice==5)
		{
			if(nan>0)
			   {
				   out_Line(male,nan);
                   nan--;
			   }
            if(nv>0)
			   {
				   out_Line(famle,nv);
                   nv--;
			   }
			printf("\t\t\t\t���������\n");
		    exit(EXIT_FAILURE);
        }
    }
    return 0;
}
 int main()
 {
    menu();
	return 0;
 }
