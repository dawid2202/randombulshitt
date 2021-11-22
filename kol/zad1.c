#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char n1[] = "521";
    char n2[] = "241";
    int d1=0, d2=0;
    for(int i=0, j=sizeof(n1)-2; i<=sizeof(n1)-2; i++, j--)
    {
        d1+=(n1[j]-'0')*pow(6,i);
    }
    printf("%s(6): %d(10)\n", n1, d1);
    for(int i=0, j=sizeof(n2)-2; i<=sizeof(n2)-2; i++, j--)
    {
        d2+=(n2[j]-'0')*pow(6,i);
    }
    printf("%s(6): %d(10)\n", n2, d2);

    printf("%d", d1+d2);
    return 0;
}
