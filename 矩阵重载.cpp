#include <iostream>
using namespace std;
class Matrix
{
private:
    int *m,*n;
    int row,col;
public:
    Matrix(int,int);
    int &operator()(int,int);
};
Matrix::Matrix(int r,int c)
{
    row=r;
    col=c;
    m=new int[row*col];
    for(int i=0;i<row*col;i++)
        *(m+i)=i;
}
int &Matrix::operator()(int r,int c)
{
    return(*(m+r*col+c));
}
int main()
{
    Matrix aM()
}
