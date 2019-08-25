#include <stdio.h>
#define MaxVertexNum 100  /* 最大顶点数设为100 */
#define MaxCost 9999  /* 边的权值最大为9999 */
typedef char VertexType;  /* 顶点类型设为字符型 */
typedef int  EdgeType;/* 边的权值设为整型 */
typedef struct
   { VertexType vexs[MaxVertexNum];   /* 存放顶点信息 */
      EdgeType  edges[MaxVertexNum][MaxVertexNum]; /* 存放邻接关系 */
      int  n,e; /*顶点数和边数*/
}Mgraph;
void CreateMGraph(Mgraph *G)
  {int i,j,k,w;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):\n") ;
    scanf("%d,%d",&(G->n),&(G->e));
    printf("请输入顶点信息:\n");
    for(i=0;i<G->n;i++)
        scanf("\n%c",&(G->vexs[i]));
	for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=MaxCost;
    printf("请输入每条边对应的两个顶点的序号(输入格式为:i,j,w):\n");
              for(k=0;k<G->e;k++)
                   { scanf("%d,%d,%d",&i,&j,&w);
                         G->edges[i][j]=w;
                         G->edges[j][i]=w;
				  }
    }
void Prim(int gm[][MaxVertexNum],int tree[],int cost[],int n)
  { int i,j,k,mincost,flag[MaxVertexNum];
    for (i=1; i<n; i++) flag[i]=0;
    flag[0]=1;  /*一开始最小生成树中只有0号顶点V0，即 U 中只有V0*/
    for (i=1; i<n; i++)
     { cost[i]=gm[0][i];
       tree[i]=0; }
    for (i=1;i<n;i++) /* 循环n-1次,每次求出最小生成树的一条边 */
     { mincost=MaxCost; k=0;
       for(j=1;j<n;j++)
         {if (flag[j]==0 && cost[j]<mincost)
            { mincost=cost[j];k=j;}
          }   /* 找出值最小的 cost[k] */
       flag[k]=1;/* 将Vk加入到当前最小生成树中，即将 Vk 加入到 U 中 */
       for(j=1;j<n;j++)/* 修改cost[ ]和tree[ ] */
          if (flag[j]==0 && gm[k][j]<cost[j])
            { cost[j]=gm[k][j];tree[j]=k;}
       }
   }

void ShortestPath(Mgraph *G,int P[ ],int D[ ])
   {  int final[MaxVertexNum],i,j,k,min;
	  final[0]=1; /* 初始时集合S中只有0号顶点 */
      D[0]=0;
      P[0]=-1; /* 0号顶点无前驱顶点 ，用-1表示 */
      for(i=1;i<G->n;i++)
         { final[i]=0;
           D[i]=G->edges[0][i];
           P[i]=0; /* P[i]存放i号顶点的前驱顶点 */
        }
      for(i=1;i<G->n; i++) /*重复G->n-1次*/
        { min=MaxCost;
          for(k=0;k<G->n;k++)
	        if(final[k]==0&&D[k]<min)
                {j=k;min=D[k];}
            final[j]=1;  /* 将顶点j加入集合S */
         for(k=0;k<G->n;k++)
	        if(final[k]==0&&D[j]+G->edges[j][k]< D[k])
                 { D[k]=D[j]+G->edges[j][k];
		           P[k]=j; }
       }
  }
void main()
{Mgraph G;
int tree[MaxVertexNum],cost[MaxVertexNum];
 int P[MaxVertexNum],D[MaxVertexNum];
 int i,pre;
 CreateMGraph(&G);
 Prim(G.edges,tree,cost,G.n);
 for (i=1;i<G.n;i++)
 printf("edge:(%d,%d),wight:%d\n",tree[i],tree[i+1],cost[i]);                                                /* 输出最小生成树中的每条边 */
 ShortestPath(&G,P,D);
 for(i=1;i<G.n; i++)
      { printf("%d:%d",D[i],i);
         pre= P[i];
         while(pre>=0)
             { printf("<-%d",pre);
                pre=P[pre];
              }
         printf("\n");
      }
 }
