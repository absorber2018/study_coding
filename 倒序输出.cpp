#include <stdio.h>
void rev(void);
int main()
{rev();
return 0;}
void rev(void)
{char c;
c=getchar();
if (c!='\n')
{rev();
printf("%c",c);}}
