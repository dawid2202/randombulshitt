#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char test[11];
    scanf("%10s", test);
    if(strlen(test)%2!=0)
    {
        printf("Incorrect input");
        return 1;
    }

    for(int i=0; i<strlen(test); i+=2)
    {
        printf("%c:%d ", test[i], test[i]-test[i+1]);
    }

    return 0;
}
