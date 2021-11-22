#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int pos[100][2]={0};
    int test[3];
    int arr[10][10], arr2[10][10]={0};
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            arr[i][j]=rand()%4+1;
    }

    int i0=10;
    int j0=rand()%10;
    int i=i0, j=j0, x=0;
    while(i!=0)
    {
        arr2[i][j]=1;
        if(j>0)
            test[0]=arr[i][j-1];
        else test[0]=10;
        if(i>0)
            test[1]=arr[i-1][j];
        else test[1]=10;
        if(j<9)
            test[2]=arr[i][j+1];
        else test[2]=10;

        if(j>0 && test[0]>=test[1] && test[0]>=test[2] && arr2[i][j-1]!=1)
            j--;
        else if(j<9 && test[2]>=test[1] && arr[i][j+1]!=1)
            j++;
        else i--;

        printf("%d %d\n", i, j);
        pos[x][0]=i;
        pos[x][1]=j;
        x++;
    }

    arr2[i][j]=1;


    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            if(arr2[i][j]==1)
                printf("x ");
            else printf("%d ",arr[i][j]);
        printf("\n");
    }

    return 0;
}
