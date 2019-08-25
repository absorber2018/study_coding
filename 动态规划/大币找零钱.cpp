#include<iostream>
using namespace std;
    void makeChange(int values[] , int valueKinds, int money,int coinsUsed[])
  {
    coinsUsed[0] = 0;
    for (int cents = 1; cents <= money; cents++)
     {
        int minCoins = cents;
         for (int kind = 0; kind < valueKinds; kind++)
         {
               if (values[kind] <= cents)
               {
                   int temp = coinsUsed[cents - values[kind]] + 1;
                   if (temp < minCoins)
                       minCoins = temp;
               }
         }
         coinsUsed[cents] = minCoins;
     }
    cout<<"面值为 "<<money<<" 的最小硬币数 : "<<coinsUsed[money]<<endl;
  }

     int main( )
     {
        int coinValue[] ={1,2,5};
        int money = 23;
        int coinsUsed [money + 1];
        makeChange(coinValue,3, money, coinsUsed);
        return 0;
     }
