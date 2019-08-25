#include <stdio.h>
#include <stdlib.h>
//#define NULL 0
#define MaxVerNum 100  /* ��󶥵�����Ϊ100 */
typedef char VertexType;  /* ����������Ϊ�ַ��� */
typedef int  EdgeType;  /* �ߵ�Ȩֵ��Ϊ���� */
typedef struct
   { VertexType vexs[MaxVerNum];       /* ��Ŷ�����Ϣ */
      EdgeType  edges[MaxVerNum][MaxVerNum]; /* ����ڽӹ�ϵ */
      int  n,e; /*�������ͱ���*/
}Mgraph;
int flag[MaxVerNum];
void CreateMGraph(Mgraph *G)
  {int i,j,k;
   printf("�����붥�����ͱ���(�����ʽΪ:������,����):\n") ;
    scanf("%d,%d",&(G->n),&(G->e));
    printf("�����붥����Ϣ:\n");
    for(i=0;i<G->n;i++)
	  scanf("\n%c",&(G->vexs[i]));
    for(i=0;i<G->n;i++)
        for(j=0;j<G->n;j++)
            G->edges[i][j]=0;
    printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:i,j):\n");
              for(k=0;k<G->e;k++)
                   { scanf("\n%d,%d",&i,&j);
                         G->edges[i][j]=1;
						 G->edges[j][i]=1; }
        }

void DFSM(Mgraph *G,int k)
  {
     int i;
     printf( "%c",G->vexs[k]);
     flag[k]=1;
     for(i=0;i<G->n;i++)
      if(G->edges[k][i]==1&&flag[i]==0)
        DFSM(G,i);
  }
void DFSTraveseM(Mgraph *G)
    { int i;
       for (i=0; i<G->n;i++)  flag[i]=0;    /* ��ÿ������һ��δ���ʹ���� */
       for (i=0; i<G->n; i++)
          if (!flag[i]) DFSM(G,i);  /*������viδ���ʹ�,��vi��ʼ������ȱ���ͼ*/
     }  /* Ҫ�ر�ע�����ͨͼ�ı��� */

void BFSM(Mgraph *G,int k)  /*��Vk������������ȱ���ͼG*/
 { int i,j;
   int Q[MaxVerNum],front,rear;
   front=-1;rear=-1;  /* ��ʼ������Q */
   printf("%c",G->vexs[k]);
   flag[k]=1;
   rear++; Q[rear]=k;  /* k�뵽����Q�� */
   while(front!=rear) /* ����Q����ʱ */
    { front++;i=Q[front];
      for (j=0;j<G->n;j++)
     if(G->edges[i][j]==1&&!flag[j])
        { printf("%c",G->vexs[j]);
          flag[j]=1;
          rear++; Q[rear]=j; /* j��� */
        }
   }
  }
void BFSTraverseM(Mgraph *G)
 { int i;
   for (i=0;i<G->n;i++)
     flag[i]=0;
   /* �����ж���һ��δ�����ʱ�� */
   for (i=0;i<G->n;i++)
     if(!flag[i]) BFSM(G,i);
   /*��viδ�����ʹ�,��vi ��ʼ���й�����ȱ���*/
  } /* Ҫ�ر�ע�����ͨͼ�ı��� */

int main()
{Mgraph G;
 CreateMGraph(&G);
 BFSTraverseM(&G);
 printf("\n");
 DFSTraveseM(&G);
 printf("\n");
 return 0;
}
