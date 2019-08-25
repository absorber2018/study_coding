#include<iostream>
#include<cmath>

using namespace std;

#define SIGN(A) ((A > 0) ? 1 : -1)
int Conquer(int X, int Y, int n){
    int sign = SIGN(X) * SIGN(Y);
    int x = abs(X);
    int y = abs(Y);
    if(x == 0 || y == 0){
        return 0;
    }else if(n == 1){
        return sign * x * y;
    }else{
        int A = (int) x / pow(10, (int)(n / 2));
        int B = x - A * pow(10, n / 2);
        int C = (int) y / pow(10, (int)(n / 2));
        int D = y - C * pow(10, n / 2);
        int AC = Conquer(A, C, n / 2);
        int BD = Conquer(B, D, n / 2);
        int ABDC = Conquer((A - B), (D - C), n / 2) + AC + BD;
        return sign * (AC * pow(10 , n) + ABDC * pow(10, (int)(n / 2)) + BD);
    }
}

int main(){
    int x, y, n;
    cin>>x>>y>>n;
    cout<<"x 和 y的乘积为："<<Conquer(x, y, n);
}
