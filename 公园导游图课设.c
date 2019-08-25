#include <iostream>
const int n=5; //n��ʾ��԰ͼ�ж������
const int e=7; //e��ʾ��԰ͼ��·��
bool visited[n+1];
#define max 32767

class graph
{
  public:
      int arcs[n+1][n+1]; //��Ӿ���
      int a[n+1][n+1];    //����
      int path[n+1][n+1]; //����
      void floyd(graph &t,const int n);
      void picture();
      void creatp(graph &t);
      void bfs(graph t);
};
void graph::picture()  //��԰ͼ
{
    cout<<"   ******��԰����ͼ******"<<endl;
    cout<<"�����ǹ�У�ľ���"<<endl;
    cout<<" ***************************"<<endl;
    cout<<" * 1.��԰���   2.ˮ��� *"<<endl;
    cout<<" * 3.Ħ����     4.����԰ *               *"<<endl;
    cout<<" * 5.��԰����            *"<<endl;
    cout<<" ***************************"<<endl;
    cout<<"�����ǹ�԰��·��ͼ  "<<endl;
    cout<<"            9          "<<endl;
    cout<<"     2 *---------*4    "<<endl;
    cout<<"       | \\      /|    "<<endl;
    cout<<"       | 4\\   5/ |    "<<endl;
    cout<<"       |   \\  /  |    "<<endl;
    cout<<"     3 |    \\/   | 2  "<<endl;
    cout<<"       |     * 3  |    "<<endl;
    cout<<"       |   / \\   |    "<<endl;
    cout<<"       |  /10  \\3|    "<<endl;
    cout<<"     1 * /     \\ * 5  "<<endl;
    cout<<"    ���         ����   "<<endl;

    cout<<"�����Ǿ����뾰��֮��ľ���ͽ��ܣ�"<<endl;
    cout<<"1.��԰��� ->2.ˮ���     ����Ϊ��3"<<endl;
    cout<<"1.��԰��� ->3.Ħ����     ����Ϊ��10"<<endl;
    cout<<"2.ˮ���   ->4.����԰     ����Ϊ��9"<<endl;
    cout<<"2.ˮ���   ->3.Ħ����     ����Ϊ��4"<<endl;
    cout<<"3.Ħ����   ->4.����԰     ����Ϊ��5"<<endl;
    cout<<"4.����԰   ->5.��԰����   ����Ϊ��2"<<endl;
    cout<<"3.Ħ����   ->5.��԰����   ����Ϊ��3"<<endl;
}
void graph::creatp(graph &t)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(i==j)t.arcs[i][j]=0; //����һ�������Ϊ0
    else t.arcs[i][j]=max; //i������jʱ
    t.arcs[1][2]=3;
    t.arcs[2][1]=3;
    t.arcs[2][4]=9;
    t.arcs[4][2]=9;
    t.arcs[3][1]=8;
    t.arcs[1][3]=8;
    t.arcs[3][2]=4;
    t.arcs[2][3]=4;
    t.arcs[3][4]=5;
    t.arcs[4][3]=5;
    t.arcs[3][5]=3;
    t.arcs[5][3]=3;
    t.arcs[5][4]=2;
    t.arcs[4][5]=2;
}   //�Ѿ����������һ����Χ����洢����
void graph::floyd(graph &t,const int n)
{
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    {
      t.a[i][j]=t.arcs[i][j]; //�Ѿ��븶ֵ��a.[i][j]
      if((i!=j)&&(a[i][j]<max))
      t.path[i][j]=i;
      else t.path[i][j]=0;
    }
 for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
       if(t.a[i][k]+t.a[k][j]<t.a[i][j])
        {
          t.a[i][j]=t.a[i][k]+t.a[k][j];
          t.path[i][j]=t.path[k][j];
        }
  }
}

void graph::bfs(graph t) //�Ӷ���i����ʵ�ֹ����������n
{

  int j,i;            //f��r�ֱ�Ϊ����ͷ��βָ��
  char ch;
  cout<<"������һ������ȥ�ĵط�:";
  cin>>i;
  while(i<=5)
  {
    if(i==1)cout<<"���������Ҫȥ�ĵط���!!"<<endl<<endl;
    else
    {
      for(j=1;j<=n;j++)
       {
        if(i!=j)
        {
          cout<<"����Ϊ"<<t.a[i][j]<<": ";
          int next=t.path[i][j];
          cout<<j;
          while(next!=i)
          {
            cout<<"--"<<next;
            next=t.path[i][next];
          }
          cout<<"--"<<i<<endl;
        }
       }
      cout<<"�����Ƽ�һ�����·�����㷵�ذ�(y/n):";
   }
   cin>>ch;
  if(ch=='y')
   {
    if(i==2) cout<<"2--3--5"<<endl;
    if(i==3) cout<<"3--5"<<endl;
    if(i==4) cout<<"4--5"<<endl;
    cout<<"��������ȥ������԰ȫ����(y/n)��"<<endl;
    cin>>ch;
	if(ch=='y')
	cout<<"����1--2--3--4--5·��"<<endl;
	cout<<"�㻹��ȥ��ĵط���?(y/n)";
    cin>>ch;
    if(ch=='y')
	{cout<<"������һ������ȥ�ĵط�:";
	 cin>>i;}
    if(ch!='y')
    {
     cout<<"          *****�˳�����*****"<<endl;
     cout<<"             ��ӭ�´�����"<<endl;
     break;
   }
  }
 else break;
 }
}
int main()
{
graph t;
t.picture();
t.creatp(t);
t.floyd(t,n);
t.bfs(t);
}
