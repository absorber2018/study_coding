#include <iostream>
const int n=5; //n表示公园图中顶点个数
const int e=7; //e表示公园图中路径
bool visited[n+1];
#define max 32767

class graph
{
  public:
      int arcs[n+1][n+1]; //领接矩阵
      int a[n+1][n+1];    //距离
      int path[n+1][n+1]; //景点
      void floyd(graph &t,const int n);
      void picture();
      void creatp(graph &t);
      void bfs(graph t);
};
void graph::picture()  //公园图
{
    cout<<"   ******公园导游图******"<<endl;
    cout<<"以下是公校的景点"<<endl;
    cout<<" ***************************"<<endl;
    cout<<" * 1.公园入口   2.水族馆 *"<<endl;
    cout<<" * 3.摩天轮     4.动物园 *               *"<<endl;
    cout<<" * 5.公园出口            *"<<endl;
    cout<<" ***************************"<<endl;
    cout<<"以下是公园的路径图  "<<endl;
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
    cout<<"    入口         出口   "<<endl;

    cout<<"下面是景点与景点之间的距离和介绍："<<endl;
    cout<<"1.公园入口 ->2.水族馆     距离为：3"<<endl;
    cout<<"1.公园入口 ->3.摩天轮     距离为：10"<<endl;
    cout<<"2.水族馆   ->4.动物园     距离为：9"<<endl;
    cout<<"2.水族馆   ->3.摩天轮     距离为：4"<<endl;
    cout<<"3.摩天轮   ->4.动物园     距离为：5"<<endl;
    cout<<"4.动物园   ->5.公园出口   距离为：2"<<endl;
    cout<<"3.摩天轮   ->5.公园出口   距离为：3"<<endl;
}
void graph::creatp(graph &t)
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(i==j)t.arcs[i][j]=0; //景点一样则距离为0
    else t.arcs[i][j]=max; //i不等于j时
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
}   //把景点跟距离用一个二围数组存储下来
void graph::floyd(graph &t,const int n)
{
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    {
      t.a[i][j]=t.arcs[i][j]; //把距离付值给a.[i][j]
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

void graph::bfs(graph t) //从顶点i出发实现广度搜索搜索n
{

  int j,i;            //f，r分别为队列头，尾指针
  char ch;
  cout<<"请输入一个你想去的地方:";
  cin>>i;
  while(i<=5)
  {
    if(i==1)cout<<"这里就是你要去的地方拉!!"<<endl<<endl;
    else
    {
      for(j=1;j<=n;j++)
       {
        if(i!=j)
        {
          cout<<"距离为"<<t.a[i][j]<<": ";
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
      cout<<"等我推荐一条最佳路径供你返回吧(y/n):";
   }
   cin>>ch;
  if(ch=='y')
   {
    if(i==2) cout<<"2--3--5"<<endl;
    if(i==3) cout<<"3--5"<<endl;
    if(i==4) cout<<"4--5"<<endl;
    cout<<"请问你想去游览公园全景吗(y/n)："<<endl;
    cin>>ch;
	if(ch=='y')
	cout<<"请走1--2--3--4--5路线"<<endl;
	cout<<"你还想去别的地方吗?(y/n)";
    cin>>ch;
    if(ch=='y')
	{cout<<"请输入一个你想去的地方:";
	 cin>>i;}
    if(ch!='y')
    {
     cout<<"          *****退出程序*****"<<endl;
     cout<<"             欢迎下次再来"<<endl;
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
