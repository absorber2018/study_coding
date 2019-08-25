#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

const int N=1000;
struct book/*编号、书名、类别、出版社、作者、出版日期、存放位置、馆藏数量、状态标志（是否可借出）*/
{
    int num;
    char name[20];
    char classes[20];
    char publish[20];
    char author[20];
    char date[20];
    char place[20];
    int amount;
    char state[5];
};

void Creats(struct book books[],int *n,int *a)
{
    int i=0,j;
    FILE *fp1;
    fp1=fopen("C:\\a.txt","r");
    if(fp1==NULL)
        printf ("→_→打开错误\n");
    else
    {
        while (!feof(fp1))
		{
            fscanf (fp1,"%d%s%s%s%s%s%s%d%s",&books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,&books[i].amount,books[i].state);
            i++;
        }
		printf("\n");
        printf ("【--~\(≧▽≦)/~啦啦啦--读取成功-------】\n");
        *n=i;
        for(j=0;j<i-1;j++)
			*a=*a+books[j].amount;
    }
    fclose(fp1);
	getchar();
}

void Creat(struct book books[],int *n,int *a)//1
{
	system("CLS");
    Creats(books,n,a);
	printf("\n");
	printf("【------任意键返回!-----】\n");
	getchar();
}






void Zengjia(struct book books[], int *n)
{
    int i;
    int a;
    i = *n;
    FILE *fp1;
	system("cls");//清屏
    printf("【---╰(￣▽￣)╮--图书信息增加--╰(￣▽￣)╮--】\n");
    do
    {
        printf("●﹏●请按顺序输入图书信息:\n\n");
        printf("请输入增加图书的编号:\n");
        scanf("%d", &books[i].num);
        printf("请输入增加图书的书名:\n");
        scanf("%s", books[i].name);
        printf("请输入增加图书的类别:\n");
        scanf("%s", books[i].classes);
        printf("请输入增加图书的出版社:\n");
        scanf("%s", books[i].publish);
        printf("请输入增加图书的作者:\n");
        scanf("%s", books[i].author);
        printf("请输入增加图书的出版日期:\n");
        scanf("%s", books[i].date);
        printf("请输入增加图书的有效位置:\n");
        scanf("%s", books[i].place);
        printf("请输入图书的馆藏数量:\n");
        scanf("%d", &books[i].amount);
        printf("请输入增加图书的状态:\n");
        scanf("%s", books[i].state);
        (*n)++;
        printf("是否需要继续添加图书:(0为结束增加，若继续增加按0外任意键)\n");
		scanf("%d",&a);


    }
    while (a);
    {
        printf("\(^o^)/添加图书成功!");

    }
	getchar();
	getchar();
}



void Xiugai(struct book books[],int *n)
{

    int i,k,a,p;
	system("cls");//清屏
    printf("【-----^_^------图书信息修改-----^_^-----】\n\n");
	printf("<(￣︶￣)>请输入你要修改的图书的编号:\n");
	scanf("%d",&p);
	do
     {k=*n-1;
    do
      k--;

    while(k>=0&&books[k].num!=p);
    if(k<0)
     {printf("\t|----找不到图书信息；----|\n");
	printf("\t|----请重新输入图书序号；----|\n");
    scanf("%d",&p);}}
    while(k<0);
		do
		{

		   printf("【---╰(￣▽￣)╮---修改图书内容选项---╰(￣▽￣)╮---】:\n");
           printf("【①-----编号】\n");
           printf("【②-----书名】\n");
           printf("【③-----类别】\n");
           printf("【④-----出版社】\n");
           printf("【⑤-----作者】\n");
           printf("【⑥-----出版日期】\n");
           printf("【⑦-----有效位置】\n");
           printf("【⑧-----馆藏数量】\n");
           printf("【⑨-----状态】\n");
           printf("╮(╯3╰)╭请输入您的选择:\n");
		   printf("\n");
		   scanf("%d",&i);
		   printf("【----------------------┢┦aΡｐy--------------------】\n");
           switch(i)
		   {
		    case 1:	printf("请输入修改后的编号:\n");
                scanf("%d",&books[k].num);break;
            case 2: printf("请输入修改后的书名:\n");
                scanf("%s",books[k].name);break;
            case 3: printf("请输入修改后的类别:\n");
                scanf("%s",books[k].classes);break;
            case 4: printf("请输入修改后的出版社:\n");
                scanf("%s",books[k].publish);break;
            case 5: printf("请输入修改后的作者:\n");
                scanf("%s",books[k].author);break;
            case 6: printf("请输入修改后的出版日期:\n");
                scanf("%s",books[k].date);break;
            case 7: printf("请输入修改后的有效位置:\n");
                scanf("%s",books[k].place);break;
            case 8: printf("请输入修改后的馆藏数量:\n");
                scanf("%d",&books[k].amount);break;
            case 9: printf("请输入修改后的状态:\n");
                scanf("%s",books[k].state);break;
		   }
		printf("修改成功!");
		printf("是否需要继续修改图书:(0为结束修改，若继续修改按0外任意键)\n");
		scanf("%d",&a);
		}
		while(a);
		{
			printf("修改结束!");
		}

	printf("【---任意键返回!---】\n");
    	getchar();
		getchar();
		}

void Shanchu(struct book books[], int *n)//2
{
    int i, k;
    int a;
	system("cls");//清屏
    printf("【----└(^o^)┘---图书信息删除----└(^o^)┘---】\n\n");
    printf("Y(^_^)Y请您输入你想删除图书的号码:\n");
    scanf("%d", &k);
    if (*n == 0)
        printf("→_→图书文件为空\n");
    else if (k<1 || k>*n)
        printf("→_→删除位置不存在\n");
    else
    {
        printf("选择删除第%d本图书,请确定:⊙﹏⊙(0为取消删除，若删除按0外任意键)\n",k);
        scanf("%d",&a);
	}
        while (a)
        {
            for (i = k; i < *n; i++)
			{
				books[i - 1] = books[i];
			}
			printf("删除成功!\n");
			a=0;
			(*n)--;
        }
		a=1;
        while(!a)
		{
			printf("取消删除成功!\n");
			a=1;
		}
		printf("【--------任意键返回!-------】\n");
		getchar();
		getchar();
}


void Change(struct book books[], int *n)
{
	int a;
	system("cls");//清屏
	printf("【---o(≧v≦)o~~---欢迎进入图书管理系统增加 删除 修改界面---o(≧v≦)o~~---】\n\n");
	    printf("【①-------------增加】\n\n");
		printf("【②-------------删除】\n\n");
		printf("【③-------------修改】\n\n");
		printf("【0----返回上一级----】\n");
		printf("\n");
		printf("(0^◇^0)请做出选择:\n");
		scanf("%d",&a);
		switch(a)
		{
		case 1: Zengjia(books,n);break;
		case 2: Shanchu(books,n);break;
		case 3: Xiugai(books,n);break;
		}


}



void Find1(struct book books[],int n)
{
    int i;
    i=n-1;
    int m;
	system("CLS");
    printf("(^o^)请输入要查找的编号");
    scanf ("%d",&m);
    while (i>0&&books[i].num!=m)
        i--;
    if (i==0)
        printf ("未找到\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find2(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("╰(￣▽￣)╮请输入要查找的书名:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].name)!=0)
        i--;
    if (i==0)
        printf ("(ˉ﹃ˉ)未找到\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find3(struct book books[],int n)
{
    int i,j=0,s[N];
    i=n-1;
    char a[20];
	system("CLS");
    printf("╰(￣▽￣)╮请输入要查找的类别:");
    scanf("%s",a);
	while (i>0&&strcmp(a,books[i].classes)!=0)
        i--;
    if (i==0)
        printf ("未找到\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find4(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("╮(╯▽╰)╭请输入要查找的出版社:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].publish)!=0)
        i--;
    if (i==0)
        printf ("→_→未找到\n");
    else
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Find5(struct book books[],int n)
{
    int i;
    i=n-1;
    char a[20];
	system("CLS");
    printf("(^o^)请输入要查找的作者:");
    scanf("%s",a);
    while (i>0&&strcmp(a,books[i].author)!=0)
        i--;
    if (i==0)
	{
        printf ("→_→未找到\n");
	}
    else
	{
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);

	}
	getchar();
	getchar();
}
void Find(struct book books[],int n)//3
{
    int m=6;

	while(m)
	{
		 system("CLS");
		 printf ("【--------o(≧v≦)o~~--------】\n\n");
		 printf ("【①-----按照编号查询-------】\n");
		 printf ("【②-----按照书名查询-------】\n");
		 printf ("【③-----按照类别查询-------】\n");
		 printf ("【④-----按照出版社查询-----】\n");
		 printf ("【⑤-----按照作者查询-------】\n");
		 printf ("【0-----返回上一级---------】\n");
		 printf("\n");
		 printf ("【--------o(≧v≦)o~~--------】\n");
		scanf("%d",&m);
		switch (m)
		{
			case 1:{Find1(books,n);break;}
			case 2:{Find2(books,n);break;}
			case 3:{Find3(books,n);break;}
		    case 4:{Find4(books,n);break;}
		    case 5:{Find5(books,n);break;}
		    case 0:{return;}
		}
	}
	getchar();
	getchar();
}




void Borrow(struct book books[],int *n)//4
{   int i,j,t;
    char copy[5]="no";
    int person;
	system("cls");//清屏
    printf("\t|----请输入图书序号；----|\n");
    scanf("%d",&i);
     do
     {t=*n-1;
    do
      t--;

    while(t>=0&&books[t].num!=i);
    if(t<0)
     {printf("\t|----找不到图书信息；----|\n");
	printf("\t|----请重新输入图书序号；----|\n");
    scanf("%d",&i);}}
    while(t<0);

    printf("\t|----请输入借阅数量；----|\n");
    scanf("%d",&j);
    if(j>books[t].amount)
	{printf("\t数量过限,请更改借阅数量\n");
	printf("\t|----请重新输入借阅数量；----|\n");
    scanf("%d",&j);}
    printf("\t|----请输入学生证序号：----|\n");
    scanf("%d",&person);
    books[t].amount=books[t].amount-j;
    if(books[t].amount==0)
        strcpy(books[t].state,copy);
    printf("\t|----借书成功！----|\n");
   getchar();
	getchar();
}

void Return(struct book books[],int *n)//5
{    int i,j,t;
    char copy[5]="yes";
    system("cls");//清屏
    printf("\t|----请输入图书序号；----|\n");
    scanf("%d",&i);
     do
     {t=*n-1;
    do
      t--;

    while(t>=0&&books[t].num!=i);
    if(t<0)
     {printf("\t|----找不到图书信息；----|\n");
	printf("\t|----请重新输入图书序号；----|\n");
    scanf("%d",&i);}}
    while(t<0);
    printf("\t|----请输入还书数量；----|\n");
    scanf("%d",&j);
    books[t].amount=books[t].amount+j;
    if(books[t].amount>0)
        strcpy(books[t].state,copy);
    printf("\t|----还书成功！----|\n");
   getchar();
	getchar();
}


void Sort(struct book books[],int *n)//6
{   int i,j;
    struct book cb;
	system("cls");//清屏
    printf("【-----------^_^-------------图 书 信 息 排 序-------------^_^-----------】\n");
    for(j=0;j<*n-1;j++)
        for(i=j+1;i<*n;i++)
            if(books[i].num<books[j].num)
            {
				cb=books[i];
                books[i]=books[j];
                books[j]=cb;
            }
    printf("图书排序(按照图书编号从小到大排序)\n");
   printf(" 编号 图书名称 类别 出版社 作者 出版日期 馆藏处 馆藏数 状态标志（是否可借出） \n");
    for(i=0;i<*n;i++)
        printf(" %d %s %s %s %s %s %s %d %s\n",
              books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
    getchar();
	getchar();
}

void Print(struct book books[],int *n)//7
{
    int i;
	system("CLS");
    printf ("【----------┈━═☆------------图 书 信 息----------┈━═☆--------】\n\n");
    printf ("编号 书名 类别 出版社 作者 出版日期 存放位置 馆藏数量 状态标志\n");
    for (i=0;i<*n;i++)
        printf("%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
	printf("\n");
    printf ("【-----------------------------┢┦aΡｐy----------------------------】\n");
	getchar();
	getchar();
}




void Write(struct book books[],int n)//8
{
    FILE *fp2;
    int i;
    fp2=fopen("C:\\b.txt","w");
	system("CLS");
    if(fp2==NULL)
	{

        printf ("→_→打开错误");
	}
    else
    {

        for (i=0;i<n-1;i++)
            fprintf(fp2,"%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
         fprintf(fp2,"%d %s %s %s %s %s %s %d %s\n",books[i].num,books[i].name,books[i].classes,books[i].publish,books[i].author,books[i].date,books[i].place,books[i].amount,books[i].state);
		printf("Y(^_^)Y输出成功");
    fclose(fp2);
    }
    getchar();
	getchar();
}







int main()
{
    int menunum=10;
    int i,m=3,a=0;
    struct book books[N];
    int n=0;
    system("color 3D");
    while (m--)
    {
		system("CLS");
        printf("【----------┈━═☆------欢 迎 使 用 图 书 管 理 系 统--------┈━═☆------】\n\n");
        printf("o(≧v≦)o~~您还可以输入密码%d次!!!\n\n",m);
		printf("请输入密码:");
        scanf("%d",&i);
        if(i!=666)//123456为用户自定义密码
            ;
        else
        {
            while(menunum)
            {
				system("CLS");
                printf ("【--------╮(╯▽╰)╭…--------】\n\n");
                printf ("【①------数据读取------】\n");
                printf ("【②------增删改--------】\n");
                printf ("【③------查询----------】\n");
                printf ("【④------借书----------】\n");
                printf ("【⑤------还书----------】\n");
                printf ("【⑥------排序----------】\n");
                printf ("【⑦------显示----------】\n");
                printf ("【⑧------数据写入------】\n");
                printf ("【0------退出程序------】\n");
				printf("\n");
				printf ("【----------┢┦aΡｐy----------】\n");
                scanf("%d",&menunum);
                switch(menunum)
                {
                  case 0:return 0;//退出程序
                  case 1:{Creat(books,&n,&a);break;}//数据读取
                  case 2:{Change(books,&n);break;}//增、删、改功能
                  case 3:{Find(books,n);break;}//查询功能
                  case 4:{Borrow(books,&n);break;}//借书管理
                  case 5:{Return(books,&n);break;}//还书管理
                  case 6:{Sort(books,&n);break;}//排序功能
                  case 7:{Print(books,&n);break;}//显示功能
                  case 8:{Write(books,n);break;}//数据写入功能
                  default: {printf("→_→输入错误");}
                }
            }
        }
    }
    return 0;
}
/*功能：该系统包含图书馆馆藏图书的信息，供读者查询和进行借还书。每本图书的基本信息包括：编号、书名、类别、出版社、作者、出版日期、存放位置、馆藏数量、状态标志（是否可借出）。系统提供以下功能供用户选择：
 (1)数据读取功能：从指定数据文件中读取所有图书的基本信息；c
 (2)增、删、改功能：可对图书基本信息进行插入、删除及修改；a
 (3)查询功能：可按照编号、书名、类别、出版社或作者进行书目信息的查询；c
 (4)借书管理：可按照编号进行借书的处理；b
 (5)还书管理：可按照编号进行还书的处理；b
 (6)排序功能：可按照编号、类别、出版日期等进行排序；b
 (7)显示功能：可在屏幕上显示所有图书的基本信息；c
 (8) 数据写入功能：可将所有图书信息写入指定数据文件中。c
 建议：一人完成数据读入、增加、删除与修改；一人负责完成借、还书管理和排序功能；一人负责文件写入操作、显示查询功能、显示功能、菜单功能及主函数。*/

