#include<iostream>                                                    //��׼��C++ͷ�ļ�
#include<fstream>                                                   //�����ļ��� I/O ����
#include<iomanip>                                                       //I/O������ͷ�ļ�                                                         //�ַ�����������
using namespace std;
#include <windows.h>
#define MAX 10
int n,m,w;
class gamescore
{
  public:
  int  academynum;          //Ժϵ���
  int score[MAX+4][MAX];     //��¼�ɼ���2ά����
  int totalscore[MAX];     //Ժ�ִܷ洢����
  int mentotalscore[MAX];  //�����ִܷ洢����
  int womentotalscore[MAX];//Ů���ִܷ洢����
  int projectnum;          //��Ŀ���
    gamescore()
    {
        academynum=0;
        projectnum=0;
    }
    void save();
    int read();
    void compile();//�༭
    void input();//����
    void del();//ɾ��
    void amend();//�޸�
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
    const char * file="e:\\�˶���ɼ�.txt";
    ofstream fout(file,ios::out);                              // out ***** д��
    if(!fout.is_open())
    { cerr<<"\n\n\t�޷���"<<file<<endl;
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
    ifstream fin(file,ios::in);                           //in ********* ֻ����
    if(!fin.is_open())
    {
        cerr<<"\n\n\t�޷���"<<file<<endl;
        exit(EXIT_FAILURE);
    }
	int i,j,k;
	while(!fin.eof())                                  //���ļ��ж������ݣ�ֱ���ļ�ĩβ
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
	cout<<"\n\t\t1.����\t2.ɾ��\t3.�޸�!!";
	cout<<"\t��ѡ��:";
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
    for(i=0;i<MAX+4;i++)//�ɼ����ʼ��
    {
        for(j=0;j<MAX;j++)
        {
            score[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
        {
             cout<<"������Ϊ"<<i+1<<"Ժϵ�ĳɼ�"<<endl;
             for(j=0;j<m+w;j++)
             {
                 cout<<"������Ϊ"<<i+1<<"Ժϵ�ĵ��˶���Ŀ���Ϊ"<<j+1<<"�ĳɼ�:(��һ����10���ڶ�����5����������2)";
                 cin>>score[i][j];
                 if(score[i][j]!=0&&score[i][j]!=2&&score[i][j]!=5&&score[i][j]!=10)
                 {
                     cout<<"�ɼ�������������������"<<endl;
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
   if(i=n-1) cout<<"!!�������"<<endl;
   m1.save();
}
void gamescore::del()
{
    cout<<"����Ҫɾ���ɼ����ڵ�Ժϵ�ı��:";
    cin>>academynum;
    cout<<"����Ҫɾ���˶���Ŀ���:";
    cin>>projectnum;
    score[academynum-1][projectnum-1]=0;
    cout<<"!!ɾ���ɹ�"<<endl;
}
void gamescore::amend()
{
    cout<<"����Ҫ�޸ĵ�Ժϵ���";
    cin>>academynum;
    cout<<"����Ҫ�޸ĵ��˶���Ŀ�ı��:";
    cin>>projectnum;
    cout<<"�������������ɼ�:";
    cin>>score[academynum-1][projectnum-1];
    cout<<"�޸ĳɹ�"<<endl;
}
void gamescore::sorting()
{   int count,choose,i,j,swap,k=0;
    int q,p;
    gamescore m5;
    count=m5.read();
	do
	{   system("cls"); //��������
		if(!count) { k++;   break; }
		cout<<"\t1.��Ժ�ܷ�����\t2.�������ܷ�����\t3.��Ů���ܷ����� \t��ѡ��:";
        cin>>choose;
		if(choose<1||choose>3)
		 {
		     cout<<"\n\t������������ѡ��!";
		      system("pause");
        }
	}while(choose<1||choose>3);
	if(k)
	  cout<<"\t\t����������Ϣ!";
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
void gamescore::sort1()//��Ժϵ�ܷ�����
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
    cout<<"��Ժϵ�ִܷӴ�С�����Լ���Ӧ��Ժϵ���Ϊ��"<<endl;
    cout<<"ѧԱ���";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"�ɼ�";
    for(j=0;j<n;j++)
    {
        cout<<totalscore[j]<<setw(5);
    }
    cout<<endl;
}

void gamescore::sort2()//�������ܷ�����
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
    cout<<"�������ִܷӴ�С�����Լ���Ӧ��Ժϵ���Ϊ��"<<endl;
    cout<<"ѧԺ���";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"�ɼ�";
    for(j=0;j<n;j++)
    {
        cout<<mentotalscore[j]<<setw(5);
    }
    cout<<endl;
}
void gamescore::sort3()//��Ժϵ�ܷ�����
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
    cout<<"��Ժϵ�ִܷӴ�С�����Լ���Ӧ��Ժϵ���Ϊ��"<<endl;
    cout<<"ѧԺ���";
    for(j=0;j<n;j++)
    {
        cout<<a[j]<<setw(5);
    }
    cout<<endl;
    cout<<"�ɼ�";
    for(j=0;j<n;j++)
    {
        cout<<womentotalscore[j]<<setw(5);
    }
    cout<<endl;
}

void gamescore::sort2()//�������ܷ�����
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
    cout<<"�������ִܷӴ�С�����Լ���Ӧ��Ժϵ���Ϊ��"<<endl;
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
    cout<<"1 ��ѯ��Ժ�õ���ɼ����ܷ�, 2 ��ѯ��Ժ�ܷ�,,3 ��ѯ��Ժ�����ܷ֣�4 ��ѯ��ԺŮ���ܷ�,5 ����Ŀ��Ų�ѯ��0 �˳���ѯ"<<endl;
    cout<<"��ѡ��:";
    cin>>k;
    if(k<0||k>5)   //�ж�����Ĳ�������Ƿ���Ŀ¼�У����������Χ��������
         {
             cout<<"������������������Ҫ��������Ŀ���";
             cin>>k;
         }
       switch(k)
         {
          case 1:
              cout<<"���Ϊ"<<academynum<<"��ѧԺ�ĵ�"<<projectnum<<"����Ŀ�ĳɼ�Ϊ:";
              cout<<score[academynum-1][projectnum-1]<<endl;break;
          case 2:
                 cout<<"��Ժ�ܷ�Ϊ��"<<score[gamescore-1][n+m+2]<<endl;break;
          case 3:
              cout<<"��Ժ�����ܷ�Ϊ��"<<score[gamescore-1][n+m]<<endl;break;
          case 4:
              cout<<"��ԺŮ���ܷ֣�"<<score[gamescore-1][n+m+1]<<endl;break;
          case 5:
              cout<<"��ͬԺϵ��Ӧ�ĵ�"<<projectnum<<"����Ŀ�ĳɼ�Ϊ:"<<endl;
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

void sysQuit()                                                       //sysQuit()�������忪ʼ
{	system("color 09");   system("cls"); 	fflush(stdin);
    cout <<"��������������������������������������������������������������������������������";
    cout <<"��������         ��         �˶���ɼ�ϵͳ               ������ ������";
    cout <<"�ǩ�����������������������������������������������������������������������������";
	cout <<"�� ��������   ><(((:>                                      <:)))><   �������� ��";
	cout <<"��                             �� л ��  ʹ �� ��                             ��";
	cout <<"��������                                                        ������";
    cout <<"�ǩ�����������������������������������������������������������������������������";
	cout <<"��������������������������������������������������������������������������������";
	cout.flush();
	cout << "\n\t�� ";Sleep(600);cout<<"�� ";Sleep(600);cout<<"�� ";Sleep(600);cout<<"ȫ ";
	Sleep(600);cout<<"�� ";Sleep(600);cout<<"�� ";Sleep(600);cout<<"�� ";Sleep(600);
	cout<<" ����";	Sleep(600);cout<<"������ ";Sleep(600);cout<<"���������� ";
    Sleep(100);	 //תҳ���
}
  /***********************************************/
int main()
{
    cout<<"\t\t****************ѧ���˶���*************"<<endl;
    cout<<"                   ����μ�Ժϵ�� n=";
    cin>>n;
    cout<<"                   ����������Ŀ�� m=";
    cin>>m;
    cout<<"                   ����Ů����Ŀ�� w=";
    cin>>w;
    int select;
    int p;
    int a;
    gamescore m;
	while(true)
	{	do
		{	system("cls");
			system("color 1f");
			cout<<"\t\t*****************�˶���*********************"<<endl;
			cout<<"\t\t*      1.�༭           4.����             *"<<endl;
			cout<<"\t\t*      2.���           0.�˳�             *"<<endl;
			cout<<"\t\t*      3.����                              *"<<endl;
			cout<<"\t\t********************************************"<<endl;
			cout<<"\t\t��ѡ��:";  cin>>select;
			if(select<0||select>4)
			{cout<<"��������������ѡ��!"<<endl;
			 system("pause") ;
			}
		}while(select<0||select>4);
		if(select==0)
		{ sysQuit();	break;	}
		switch(select)
		{
		case 1:	system("color 1a");	m.compile();system("pause") ;break;
		case 2:	system("color 1e");	m.show();system("pause") ;break;
		case 3:	system("color 0");cout<<"����Ҫ���ҵ�Ժϵ:";cin>>a;cout<<"����Ҫ��ѯ���˶���Ŀ���:";cin>>p;m.search(a,p);system("pause") ;break;
		case 4:	system("color 1d");	m.sorting();system("pause");break;
		}
	}return 0;
}
