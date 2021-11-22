#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int s=5;//pozosta³oœci po próbach z mniejsz¹ tablic¹
    int arr[s][s];
    for(int i=0; i<s*s; i++)
    {
        arr[i/s][i%s]=i+1;
    }

    int kol[5]={0};
    int x=0;
    srand(time(NULL));
    while(x<s)
    {
        int temp=rand()%s+1;
        int test=0;
        for(int i=0; i<x; i++)
            if(temp==kol[i])
                test=1;
        if(test==0)
        {
            kol[x]=temp;
            x++;
        }

    }
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
        {
            printf("%d ",arr[i][kol[j]-1]);
        }
        printf("\n");
    }
    return 0;
}
