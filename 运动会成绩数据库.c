#include<iostream>                                                    //标准的C++头文件
#include<fstream>                                                   //进行文件的 I/O 处理
#include<iomanip>                                                       //I/O流控制头文件                                                         //字符串数据类型
using namespace std;
#include <windows.h>
#define MAX 10
int n,m,w;
class gamescore
{
  public:
  int  academynum;          //院系编号
  int score[MAX+4][MAX];     //记录成绩的2维数组
  int totalscore[MAX];     //院总分存储数组
  int mentotalscore[MAX];  //男团总分存储数组
  int womentotalscore[MAX];//女团总分存储数组
  int projectnum;          //项目编号
    gamescore()
    {
        academynum=0;
        projectnum=0;
    }
    void save();
    int read();
    void compile();//编辑
    void input();//输入
    void del();//删除
    void amend();//修改
    void sorting();
    void sort1();
    void sort2();
    void sort3();
    void show();
    void search(int academynum,int projectnum);
};
void gamescore::save()
{
    int i,j;
    const char * file="e:\\运动会成绩.txt";
    ofstream fout(file,ios::out);                              // out ***** 写打开
    if(!fout.is_open())
    { cerr<<"\n\n\t无法打开"<<file<<endl;
      exit(EXIT_FAILURE);
    }
    for(i=0;i<n;i++)
        {
             for(j=0;j<m+w+3;j++)
             {
                 fout<<score[i][j]<<setw(5);
             }
             fout<<endl;
         }
   fout.close();
}
int read()
{
	const char * file="E:\\AddressBook";
    ifstream fin(file,ios::in);                           //in ********* 只读打开
    if(!fin.is_open())
    {
        cerr<<"\n\n\t无法打开"<<file<<endl;
        exit(EXIT_FAILURE);
    }
	int i,j,k;
	while(!fin.eof())                                  //从文件中读出数据，直到文件末尾
	{
	    for(i=0;i<n;i++)
	    {
	      for(j=0;j<n+m+3;j++)
	      {
	          fin>>score[i][j];
	      }
	    }
	    k++;
	}fin.close();
	return k;
}
void gamescore::compile()
{   system("cls");	int select;  gamescore m1;
	cout<<"\n\t\t1.输入\t2.删除\t3.修改!!";
	cout<<"\t请选择:";
	cin>>select;
	switch(select)
	{
	case 1:	system("color 1e");	m1.input();break;
	case 2:	system("color 0c"); m1.del();break;
	case 3:	 m1.amend();break;
	}
}
void gamescore::input()
{
    gamescore m1;
    int i,j;
    for(i=0;i<MAX+4;i++)//成绩表初始化
    {
        for(j=0;j<MAX;j++)
        {
            score[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
        {
             cout<<"输入编号为"<<i+1<<"院系的成绩"<<endl;
             for(j=0;j<m+w;j++)
             {
                 cout<<"输入编号为"<<i+1<<"院系的的运动项目编号为"<<j+1<<"的成绩:(第一名：10，第二名：5，第三名：2)";
                 cin>>score[i][j];
                 if(score[i][j]!=0&&score[i][j]!=2&&score[i][j]!=5&&score[i][j]!=10)
                 {
                     cout<<"成绩输入错误，请检查后再输入"<<endl;
                     cin>>score[i][j];
                 }
                 if(j<m)
                 score[i][m+w]+=score[i][j];
                 if(j>=m)
                 score[i][m+w+1]+=score[i][j];
                 score[i][n+m+2]+=score[i][j];
             }
         }
         for(i=0;i<n;i++)
         {
             mentotalscore[i]=score[i][n+m];
             womentotalscore[i]=score[i][n+m+1];
             totalscore[i]=score[i][n+m+1];
         }
   if(i=n-1) cout<<"!!输入完毕"<<endl;
   m1.save();
}
void gamescore::del()
{
    cout<<"输入要删除成绩所在的院系的编号:";
    cin>>academynum;
    cout<<"输入要删除运动项目编号:";
    cin>>projectnum;
    score[academynum-1][projectnum-1]=0;
    cout<<"!!删除成功"<<endl;
}
void gamescore::amend()
{
    cout<<"输入要修改的院系编号";
    cin>>academynum;
    cout<<"输入要修改的运动项目的编号:";
    cin>>projectnum;
    cout<<"请重新输入该项成绩:";
    cin>>score[academynum-1][projectnum-1];
    cout<<"修改成功"<<endl;
}
void gamescore::sorting()
{   int count,choose,i,j,swap,k=0;
    int q,p;
    gamescore m5;
    count=m5.read();
	do
	{   system("cls"); //清屏方法
		if(!count) { k++;   break; }
		cout<<"\t1.按院总分排序\t2.按男团总分排序\t3.按女团总分排序 \t请选择:";
        cin>>choose;
		if(choose<1||choose>3)
		 {
		     cout<<"\n\t输入有误，重新选择!";
		      system("pause");
        }
	}while(choose<1||choose>3);
	if(k)
	  cout<<"\t\t请先输入信息!";
	else
	{
	    switch(choose)
	    {
	        case 1:m5.sort1();break;
	        case 2:m5.sort2();break;
	        case 3:m5.sort3();break;
	    }
    }
}
void gamescore::sort1()//按院系总分排序
{
    int i,j,swap;
    int p,q;
    int a[MAX];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(j=0;j<n-1;j++)
    {swap=0;
        for(i=0;i<=n-1-j;i++)
        {
            if(totalscore[i]<totalscore[i+1])
            {
                p=totalscore[i];
                totalscore[i]=totalscore[i+1];
                totalscore[i+1]=p;
                q=a[i];
                a[i]=a[i+1];
                a[i+1]=q;
            }
        }
        if(swap=0) break;
    }
    cout<<"按院系总分从大到小排序，以及对应的院系编号为："<<endl;
    cout<<"学员编号";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"成绩";
    for(j=0;j<n;j++)
    {
        cout<<totalscore[j]<<setw(5);
    }
    cout<<endl;
}

void gamescore::sort2()//按男团总分排序
{
    int i,j;
    int p,q;
    int a[MAX];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(j=0;j<n-1;j++)
    {
        swap=0;
        for(i=0;i<=n-1-j;i++)
        {
            if(mentotalscore[i]<mentotalscore[i+1])
            {
                p=mentotalscore[i];
                mentotalscore[i]=mentotalscore[i+1];
                mentotalscore[i+1]=p;
                q=a[i];
                a[i]=a[i+1];
                a[i+1]=q;
            }
        }
        if(swap=0)break;
    }
    cout<<"按男团总分从大到小排序，以及对应的院系编号为："<<endl;
    cout<<"学院编号";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"成绩";
    for(j=0;j<n;j++)
    {
        cout<<mentotalscore[j]<<setw(5);
    }
    cout<<endl;
}
void gamescore::sort3()//按院系总分排序
{
    int i,j,swap;
    int p,q;
    int a[MAX];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(j=0;j<n-1;j++)
    {swap=0;
        for(i=0;i<=n-1-j;i++)
        {
            if(womentotalscore[i]<womentotalscore[i+1])
            {
                p=womentotalscore[i];
                womentotalscore[i]=womentotalscore[i+1];
                womentotalscore[i+1]=p;
                q=a[i];
                a[i]=a[i+1];
                a[i+1]=q;
            }
        }
        if(swap=0) break;
    }
    cout<<"按院系总分从大到小排序，以及对应的院系编号为："<<endl;
    cout<<"学院编号";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"成绩";
    for(j=0;j<n;j++)
    {
        cout<<womentotalscore[j]<<setw(5);
    }
    cout<<endl;
}

void gamescore::sort2()//按男团总分排序
{
    int i,j;
    int p,q;
    int a[MAX];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<=n-1-j;i++)
        {
            if(mentotalscore[i]<mentotalscore[i+1])
            {
                p=mentotalscore[i];
                mentotalscore[i]=mentotalscore[i+1];
                mentotalscore[i+1]=p;
                q=a[i];
                a[i]=a[i+1];
                a[i+1]=q;
            }
        }
    }
    cout<<"按男团总分从大到小排序，以及对应的院系编号为："<<endl;
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    for(j=0;j<n;j++)
    {
        cout<<mentotalscore[j]<<setw(5);
    }
    cout<<endl;
}
void  gamescore::show()
{
    int i,j;
      int count;
      gamescore m3;
      count=m3.read;
      for(i=0;i<n;i++)
      {
          for(j=0;j<w+m+3;j++)
          {
              cout<<score[i][j];
              cout<<setw(5);
          }
          cout<<endl;
      }
}



void gamescore::search(int academynum,int projectnum)
{
    gamescore m6;
    int count;
    count=m6.read;
    int j;
    int k;
   do
   {
    cout<<"1 查询该院该单项成绩的总分, 2 查询该院总分,,3 查询该院男团总分，4 查询该院女团总分,5 按项目编号查询，0 退出查询"<<endl;
    cout<<"请选择:";
    cin>>k;
    if(k<0||k>5)   //判断输入的操作编号是否在目录中，如果超出范围重新输入
         {
             cout<<"输入有误，请重新输入要操作的项目编号";
             cin>>k;
         }
       switch(k)
         {
          case 1:
              cout<<"编号为"<<academynum<<"的学院的第"<<projectnum<<"个项目的成绩为:";
              cout<<score[academynum-1][projectnum-1]<<endl;break;
          case 2:
                 cout<<"该院总分为："<<score[gamescore-1][n+m+2]<<endl;break;
          case 3:
              cout<<"该院男团总分为："<<score[gamescore-1][n+m]<<endl;break;
          case 4:
              cout<<"该院女团总分："<<score[gamescore-1][n+m+1]<<endl;break;
          case 5:
              cout<<"不同院系对应的第"<<projectnum<<"个项目的成绩为:"<<endl;
                for(j=0;j<n;j++)
                {
                    cout<<1+j<<setw(5);
                }
                cout<<endl;
                  for(j=0;j<n;j++)
                {
                    cout<<score[j][projectnum-1]<<setw(5);
                }
                  cout<<endl;
                break;
        }

    }while(1);
}

void sysQuit()                                                       //sysQuit()函数定义开始
{	system("color 09");   system("cls"); 	fflush(stdin);
    cout <<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
    cout <<"┃◇◇◇◇◇         　         运动会成绩系统               　　　 ◇◇◇◇◇┃";
    cout <<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
	cout <<"┃ →→→→   ><(((:>                                      <:)))><   ←←←← ┃";
	cout <<"┃                             感 谢 您  使 用 ！                             ┃";
	cout <<"┃◇◇◇◇◇                                                        ◇◇◇◇◇┃";
    cout <<"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫";
	cout <<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	cout.flush();
	cout << "\n\t正 ";Sleep(600);cout<<"在 ";Sleep(600);cout<<"安 ";Sleep(600);cout<<"全 ";
	Sleep(600);cout<<"退 ";Sleep(600);cout<<"出 ";Sleep(600);cout<<"· ";Sleep(600);
	cout<<" ··";	Sleep(600);cout<<"··· ";Sleep(600);cout<<"····· ";
    Sleep(100);	 //转页间隔
}
  /***********************************************/
int main()
{
    cout<<"\t\t****************学生运动会*************"<<endl;
    cout<<"                   输入参加院系数 n=";
    cin>>n;
    cout<<"                   输入男子项目数 m=";
    cin>>m;
    cout<<"                   输入女子项目数 w=";
    cin>>w;
    int select;
    int p;
    int a;
    gamescore m;
	while(true)
	{	do
		{	system("cls");
			system("color 1f");
			cout<<"\t\t*****************运动会*********************"<<endl;
			cout<<"\t\t*      1.编辑           4.排序             *"<<endl;
			cout<<"\t\t*      2.浏览           0.退出             *"<<endl;
			cout<<"\t\t*      3.查找                              *"<<endl;
			cout<<"\t\t********************************************"<<endl;
			cout<<"\t\t请选择:";  cin>>select;
			if(select<0||select>4)
			{cout<<"输入有误，请重新选择!"<<endl;
			 system("pause") ;
			}
		}while(select<0||select>4);
		if(select==0)
		{ sysQuit();	break;	}
		switch(select)
		{
		case 1:	system("color 1a");	m.compile();system("pause") ;break;
		case 2:	system("color 1e");	m.show();system("pause") ;break;
		case 3:	system("color 0");cout<<"输入要查找的院系:";cin>>a;cout<<"输入要查询的运动项目编号:";cin>>p;m.search(a,p);system("pause") ;break;
		case 4:	system("color 1d");	m.sorting();system("pause");break;
		}
	}return 0;
}
