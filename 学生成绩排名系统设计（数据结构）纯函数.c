#include<stdio.h>
#include<stdlib.h>
#define  N  5
struct stud_type
{
	 char num[20];               /*学号*/
	 char name[20];               /*姓名*/
	 float score[3];                /*3门课程成绩*/
     float ave;                     /*平均分*/
};
void input(struct stud_type stu[]);          /*input函数声明*/
void average(struct stud_type stu[]);       /*average函数声明*/
void sort(struct stud_type stu[]);          /*sort函数声明*/
void print(struct stud_type stu[]);         /*print函数声明*/
int main()
{
	  int sel;
	  struct stud_type stu[N];
	  do
	  {
	       printf("1....................输入\n");
	       printf("2....................计算平均值\n");
		   printf("3....................排序\n");
	       printf("4....................输出\n");
	       printf("0....................退出\n");
	       printf("请输入选择\n");
	       scanf("%d",&sel);
	       switch(sel)
		   {
	         case  1:
	              input(stu);
	              break;
	         case  2:
	              average(stu);
	              break;
	         case  3:
	              sort(stu);
	              break;
	         case  4:
	              print(stu);
	              break;
	         case  0: exit(0);
		   }
	 }while(sel!=0);
     return 0;
}
void input(struct stud_type stu[])
{
     int i;
     printf("请输入 %d 名学生信息（学号  姓名  成绩）:\n", N);
     for(i=0;i<N;i++)
      	scanf("%s%s%f%f%f",stu[i].num,stu[i].name,&stu[i].score[0],
                                 &stu[i].score[1],&stu[i].score[2]);
}
void average(struct stud_type stu[])
{
      int i;
	  for(i=0;i<N;i++)                     /*average函数调用*/
	stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
}
void  sort(struct stud_type stu[])          /*sort函数定义*/
{
    int i,k,j;
    struct stud_type t;
    for(i=0;i<N-1;i++)
	{
	     k=i;
	     for(j=i+1;j<N;j++)
	       if(stu[j].ave>stu[k].ave)
	             k=j;
	       if(k!=i)
		   {
	             t=stu[i];
	             stu[i]=stu[k];
	             stu[k]=t;
			}
      }
}
void print(struct stud_type stu[])          /*print函数定义*/
{
     int i;
     printf("****名次  学号   姓名   成绩1  成绩2   成绩3  平均成绩****\n");
     for(i=0;i<N;i++)	     printf("%6d%8s%8s%8.2f%8.2f%8.2f%8.2f\n",i+1, stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
}
