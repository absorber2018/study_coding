#include<stdio.h>
#include<stdlib.h>
#define  N  5
struct stud_type
{
	 char num[20];               /*ѧ��*/
	 char name[20];               /*����*/
	 float score[3];                /*3�ſγ̳ɼ�*/
     float ave;                     /*ƽ����*/
};
void input(struct stud_type stu[]);          /*input��������*/
void average(struct stud_type stu[]);       /*average��������*/
void sort(struct stud_type stu[]);          /*sort��������*/
void print(struct stud_type stu[]);         /*print��������*/
int main()
{
	  int sel;
	  struct stud_type stu[N];
	  do
	  {
	       printf("1....................����\n");
	       printf("2....................����ƽ��ֵ\n");
		   printf("3....................����\n");
	       printf("4....................���\n");
	       printf("0....................�˳�\n");
	       printf("������ѡ��\n");
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
     printf("������ %d ��ѧ����Ϣ��ѧ��  ����  �ɼ���:\n", N);
     for(i=0;i<N;i++)
      	scanf("%s%s%f%f%f",stu[i].num,stu[i].name,&stu[i].score[0],
                                 &stu[i].score[1],&stu[i].score[2]);
}
void average(struct stud_type stu[])
{
      int i;
	  for(i=0;i<N;i++)                     /*average��������*/
	stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
}
void  sort(struct stud_type stu[])          /*sort��������*/
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
void print(struct stud_type stu[])          /*print��������*/
{
     int i;
     printf("****����  ѧ��   ����   �ɼ�1  �ɼ�2   �ɼ�3  ƽ���ɼ�****\n");
     for(i=0;i<N;i++)	     printf("%6d%8s%8s%8.2f%8.2f%8.2f%8.2f\n",i+1, stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
}
