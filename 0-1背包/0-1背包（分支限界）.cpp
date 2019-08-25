#include <iostream>
using namespace std;

typedef int Typew;
typedef int Typep;


class Object{
    friend Typep Knapsack(Typew *, Typep *, Typew, int, int *);
public:
    int operator <= (Object a) const{
        return (d >= a.d);
    }
private:
    int ID;
    float d;
};


class bbnode{
    friend class Knap;
    friend Typep Knapsack(Typew *, Typep *, Typew, int, int *);
private:
    bbnode *parent;
    int LChild;
};


class HeapNode{
    friend class Knap;
    friend class MaxHeap;
public:
    operator Typep()const{return uprofit;};
private:
    Typep uprofit,
          profit;
    Typew weight;
    int level;
    bbnode *elemPtr;
};

 class MaxHeap{
public:
    MaxHeap(int maxElem)
    {
        HeapElem = new HeapNode* [maxElem+1];
        capacity = maxElem;
        size = 0;
    }
    void InsertMax(HeapNode *newNode);
    HeapNode DeleteMax(HeapNode* &N);

private:
    int capacity;
    int size;
    HeapNode **HeapElem;

};

 class Knap{
    friend Typep Knapsack(Typew *, Typep *, Typew, int, int *);
public:
    Typep MaxKnapsack();
private:
    MaxHeap *H;
    Typep Bound(int i);
    void AddLiveNode(Typep up, Typep cp, Typew cw, int ch, int level);
    bbnode *E;
    Typew c;
    int n;
    Typew *w;
    Typep *p;
    Typew cw;
    Typep cp;
    int *bestx;
};

void MaxHeap::InsertMax(HeapNode *newNode)
{
      int i = 1;
        for (i = ++size; i/2 > 0 && HeapElem[i/2]->uprofit < newNode->uprofit; i /= 2)
        {
            HeapElem[i] = HeapElem[i/2];
        }
        HeapElem[i] = newNode;
}

HeapNode MaxHeap::DeleteMax(HeapNode *&N)
{
       if(size >0 )
        {
            N = HeapElem[1];
              int i = 1;
            while(i < size)
            {
                if(((i*2 +1) <= size) && HeapElem[i*2]->uprofit > HeapElem[i*2 +1]->uprofit)
                {
                    HeapElem[i] = HeapElem[i*2];
                    i = i*2;
                }
                else
                {
                    if(i*2 <= size)
                    {
                            HeapElem[i] = HeapElem[i*2];
                            i = i*2;
                    }
                    else
                        break;
                }
            }
            if(i < size)
                HeapElem[i] = HeapElem[size];
        }
        size--;
        return *N;
}

Typep Knap::MaxKnapsack()
{
    H = new MaxHeap(1000);
    bestx = new int [n+1];
    int i = 1;
    E = 0;
    cw = 0;
    cp = 0;
    Typep bestp = 0;
    Typep up = Bound(1);
      while (i != n+1)
    {

        Typew wt = cw + w[i];
        if(wt <= c)
        {
            if(cp + p[i] > bestp)
                bestp = cp + p[i];
            AddLiveNode(up, cp + p[i], cw + w[i], 1, i);
        }

        up = Bound(i + 1);
        if(up >= bestp)
            AddLiveNode(up, cp, cw, 0, i);
         HeapNode* N;
        H->DeleteMax(N);
        E = N->elemPtr;
        cw = N->weight;
        cp = N->profit;
        up = N->uprofit;
        i = N->level + 1;
    }
     for (int i = n; i > 0; i--)
    {
        bestx[i] = E->LChild;
        E = E->parent;
    }
    return cp;

}

Typep Knap::Bound(int i)
{
    Typew cleft = c - cw;
    Typep b = cp;
    while (i<=n && w[i] <= cleft)
    {
        cleft -= w[i];
        b += p[i];
        i++;
    }
    if(i<=n) b += p[i]/w[i] * cleft;
    return b;
}

void Knap::AddLiveNode(Typep up, Typep cp, Typew cw, int ch, int level)
{
    bbnode *b=new bbnode;
    b->parent=E;
    b->LChild=ch;
    HeapNode *N = new HeapNode;
    N->uprofit=up;
    N->profit=cp;
    N->weight=cw;
    N->level=level;
    N->elemPtr=b;
    H->InsertMax(N);
}

 Typep Knapsack(Typew *w, Typep *p, Typew c, int n, int *bestx)
{
    Typew W = 0;
    Typep P = 0;
    Object *Q = new Object[n];
    for(int i =1; i<=n; i++)
    {
        Q[i-1].ID = i;
        Q[i-1].d = 1.0*p[i]/w[i];
        P += p[i];
        W += w[i];
    }
    if (W <= c)
    {
        for(int i =1; i<=n; i++)
        {
            bestx[i] = p[i];
        }
        return P;
    }
     for(int i = 1; i<n; i++)
        for(int j = 1; j<= n-i; j++)
        {
            if(Q[j-1].d < Q[j].d)
            {
                Object temp = Q[j-1];
                Q[j-1] = Q[j];
                Q[j] = temp;
            }
        }

    Knap K;
    K.p = new Typep [n+1];
    K.w = new Typew [n+1];
    for(int i = 1; i<=n; i++)
    {
        K.p[i] = p[Q[i-1].ID];
        K.w[i] = w[Q[i-1].ID];
    }
    K.cp = 0;
    K.cw = 0;
    K.c = c;
    K.n = n;
    Typep bestp = K.MaxKnapsack();
    for(int i = 1; i<=n; i++)
    {
        bestx[Q[i-1].ID] = K.bestx[i];
    }
    delete [] Q;
    delete [] K.w;
    delete [] K.p;
    delete [] K.bestx;
    delete [] K.H;
    return bestp;
}

int main ()
{
    const int N = 4;
        Typew c=8;
    int bestx[N+1];
    int bestp;
     Typep p[]={-1,6,4,7,4};
    Typew w[]={-1,2,3,5,2};
    bestp = Knapsack(w, p, c, N, bestx);

    for (int i = 1; i <= N; i++)
    {
        cout<<bestx[i]<<" ";
    }
    cout<<endl;
    cout<<bestp<<endl;

    return 0;
}
