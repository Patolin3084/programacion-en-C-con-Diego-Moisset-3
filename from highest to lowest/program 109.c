#include<stdio.h>
#include<conio.h>

void load(int vector[10])
{
    for(int x=0;x<10;x++)
    {
        printf("Enter a value: ");
        scanf("%i",&vector[x]);
    }
}

void verification(int vector[10])
{
    int order=1;
    for(int x=0;x<9;x++)
    {
        if(vector[x+1]<vector[x])
        {
            order=0;
            break;
        }
    }
    if(order==1)
    {
        printf("The vector is in order");
    }
    else
    {
        printf("The vector is not in order");
    }
}

void main()
{
    int v[10];
    load(v);
    verification(v);
    getch();
    return 0;
}
