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
           printf("无法配对");
}
int nan,nv,time=1;
lNode *maleNode,*famleNode;
lNodeQueue *male,*famle;
int nantemp,nvtemp;
int menu()
{
     int temp,choice;


    printf("                                  舞伴配对\n\n");
    printf("        1.输入人数情况\n        2.开始配对\n        3.中途退出号码，格式；男号码，女号码（若有一项不退出，用零代替）\n        4.中途加入号码，格式；男号码，女号码（若有一项没有中途加入，用零代替）\n        5.清空数据\n ");
    printf("\t\t\t请输入你的选择：");
    scanf("%d",&choice);
    while(choice)
    {
        if(choice==1)
		{printf("\t\t\t请分别输入男女生人数；男生，女生\t");
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
            printf("\t\t第%d轮配对",time) ;
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
			 printf("\t\t\t请分别输入退出的男女生号码；男生，女生\t\t\t");
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
		   printf("\t\t\t请分别输入加入的男女生编号；男生，女生\t\t\t");
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
			printf("\t\t\t\t数据已清空\n");
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
