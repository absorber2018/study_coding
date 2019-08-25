#include <iostream>
#include <malloc.h>
#define MaxSize 100 //最多結点数
using namespace std;
typedef struct QNode
{
    float weight;
    float value;
    int ceng;
    struct QNode *parent;
    bool leftChild;

}QNode,*qnode;//存放毎个結点

typedef struct
{
    qnode Q[MaxSize];
    int front,rear;
}SqQueue;//存放結点的以列

   SqQueue sq;
    float bestv=0;
    int n=0;
    float w[MaxSize];
    float v[MaxSize];
    int bestx[MaxSize];
   qnode bestE;

  void InitQueue(SqQueue &sq )
  {
    sq.front=1;
    sq.rear=1;
  }

  bool QueueEmpty(SqQueue sq)
  {
      if(sq.front==sq.rear)
        return true;
      else
        return false;
  }

  void EnQueue(SqQueue &sq,qnode b)
  {
      if(sq.front==(sq.rear+1)%MaxSize)
    {
        cout<<"队列已满";
        return;
    }
      sq.Q[sq.rear]=b;
      sq.rear=(sq.rear+1)%MaxSize;
  }

  qnode DeQueue(SqQueue &sq)
  {
      qnode e;
    if(sq.front==sq.rear)
    {
        cout<<"队列已空"<<endl;
        return 0;
    }
    e=sq.Q[sq.front];
    sq.front=(sq.front+1)%MaxSize;
    return e;
  }

void EnQueue1(float wt,float vt, int i,QNode *parent, bool leftchild)
  {
    qnode b;
    if(i==n)
    {
        if(vt==bestv)
        {
            bestE=parent;
            bestx[n]=(leftchild)?1:0;
        }
    return;
    }
    b=(qnode)malloc(sizeof(QNode));
    b->weight=wt;
    b->value=vt;
    b->ceng=i;
    b->parent=parent;
    b->leftChild=leftchild;
    EnQueue(sq,b);
  }

void maxLoading(float w[],float v[],int c)
{
    float wt=0;
    float vt=0;
    int i=1;
    float ew=0;
    float ev=0;
    qnode e=NULL;
    qnode t=NULL;
    InitQueue(sq);
    EnQueue(sq,t);
    while (!QueueEmpty(sq))
    {
        wt=ew+w[i];
        vt=ev+v[i];
        if(wt<=c)
        {
            if(vt>bestv)
                bestv=vt;
            EnQueue1( wt,vt,i,e,true);
        }
        EnQueue1(ew,ev,i,e,false);
        e=DeQueue(sq);
    if(e == NULL)
    {
        if(QueueEmpty(sq))
            break;
        EnQueue(sq,NULL);
        e=DeQueue(sq);
        i++;
    }
    ew=e->weight;
    ev=e->value;
}
   cout<<"最优取法为:"<<endl;
    for( int j=n-1;j>0;j--)
    {
        bestx[j]=(bestE->leftChild?1:0);
        bestE=bestE->parent;
    }
    for(int k=1;k<=n;k++)
    {
        if(bestx[k]==1)
            cout<<"物品"<<k<<":重量:"<<w[k]<<"价值: "<<v[k]<<endl;
    }
  cout<<"最优价值为: "<<bestv<<endl;
  }

  int  main()
  {
    int c;
    float eww[MaxSize];
    cout<<" ------0-1 背包问题分枝限界法  -------"<<endl;
    cout<<"请输入物品的数量:"<<endl;
    cin>>n;
    cout<<"请输入背包的最大承重量:"<<endl;
    cin>>c;
    cout<<"请输入物品的重量和单位重量价值:"<<endl;
  for(int i=1;i<=n;i++)
    {
        cout<<"物品"<<i<<":"<<endl;
        cin>>w[i]>>eww[i];
        v[i]=w[i]*eww[i];
    }
    maxLoading(w,v,c);
    return 0;
  }
