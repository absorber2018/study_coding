#include <stdio.h>
#include <malloc.h>
#define N 5
struct student
{
   char num[20];
   char name[20];
   float score;
   struct student *next;
};


void inputOne(struct student *b)
{
  printf("请输入一个学生 学号 姓名 成绩\n");
  scanf("%s%s%f",&b->num,&b->name,&b->score);
  }


struct student *creat(int n)
{
  int i;
  struct student *head,*b,*c;
   if(n<=N)
    {
  for(i=0;i<n;i++)
   {c=(struct student*)malloc(sizeof(struct student));
    if(i==0)
    {
      b=c;
      head=b;}
    else{
     b->next=c;
     c->next=NULL;
     b=c;

  }
    inputOne(b);

    }
    }
   else
        {
          b=GetoutputList(head,N);
          c=(struct student*)malloc(sizeof(struct student));
          b->next=c;
          c->next=NULL;
          b=c;
          inputOne(b);
        }
  return head;
}
void outputList(struct student *head)
{
    struct student *c;
    c=head;
    printf( " %8s %10s %6s \n", "学号", "姓名", "成绩" );
   while(c!=NULL)
   {
       printf("%8s%10s%6.1f\n",c->num,c->name,c->score);
       c=c->next;
   }
}
int main()
{

   int i,n;
   struct student  *ListHead;
   ListHead=creat(N);
   outputList(ListHead);
   printf("是否再添加学生及信息？\n是：1;否；0\n");
   scanf("%d",&i);
   if(i=1)
   {n=N+1;
    creat(n);
    }
   printf("----运行完毕----");
}
