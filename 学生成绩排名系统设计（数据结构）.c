#include <stdio.h>
struct studentscore
{
    char num[20];
    char name[20];
    float score[3];
    float ave;
};
int average(struct studentscore stu[])
{
    int i;
    for(i=0;i<5;i++)
        stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
    return 0;
}
int sort(struct studentscore stu[])
{
    int i,j,k;
    struct studentscore t;
    for(k=5-1;k>=0;k--){
        for(i=0;i<5;i++)
    {
        j=i+1;
        if(stu[i].ave<stu[j].ave)
            {t=stu[j];
            stu[j]=stu[i];
            stu [i]=t;}
    }}
     return 0;
}

int print(struct studentscore stu[])
{
    int i;
    printf("排序后结果\n");
    for(i=0;i<5;i++)
        printf("%s  %s  %f  %f  %f  %f \n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].ave);
     return 0;
}

int main(){
    int i;
    printf("请输入学生学号·姓名·成绩（高数·英语·数据结构）\n");
    struct studentscore stu[5];
    for(i=0;i<5;i++)
    scanf("%s%s%f%f%f",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
    average(stu);
    sort(stu);
    printf("输出学生成绩排名");
    print(stu);
  }
