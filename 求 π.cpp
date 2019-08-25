#include <stdio.h>
#define n 10000
int main()
{
    float T,pai,i;
    for(i=1,T=0;i<=n;i++)
        T=T+(1/(4*i-3)-1/(4*i-1));
    pai=4*T;
    printf("¦Ð=%f",pai);
    return 0;
}
