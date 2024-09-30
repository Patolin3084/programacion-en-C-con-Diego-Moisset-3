#include<stdio.h>
#include<conio.h>

void load(int vector[5])
{
    for(int x=0;x<5;x++)
    {
        printf("Enter the element: ");
        scanf("%i",&vector[x]);
    }
}

void mayor(int vector[5])
{
    int may=vector[0];
    int pos=0;
    for(int x=1;x<5;x++)
    {
        if(vector[x]>may)
        {
            may=vector[x];
            pos=x;
        }
    }
    printf("The largest element of vector is %i and is located in position %i",may,pos);
}


int main()
{
    int vector[5];
    load(vector);
    mayor(vector);
    getch();
    return 0;
}
