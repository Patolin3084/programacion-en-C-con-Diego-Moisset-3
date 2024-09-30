#include<stdio.h>
#include<conio.h>

void load(int vector[5])
{
    for(int x=0;x<5;x++)
    {
        printf("Enter a number: ");
        scanf("%i",&vector[x]);
    }

}

void ascendingOrder(int vector[5])
{
    for(int k=0;k<4;k++)
    {
        int aux;
        for(int x=0;x<4-k;x++)
        {
            if(vector[x]>vector[x+1])
            {
                aux=vector[x];
                vector[x]=vector[x+1];
                vector[x+1]=aux;
            }
        }
    }
}

void descendingOrder(int vector[5])
{
    for(int k=0;k<4;k++)
    {
        int aux;
        for(int x=0;x<4-k;x++)
        {
            if(vector[x]<vector[x+1])
            {
                aux=vector[x];
                vector[x]=vector[x+1];
                vector[x+1]=aux;
            }
        }
    }
}

void print(int vector[5])
{
    for(int x=0;x<5;x++)
    {
        printf("%i\n",vector[x]);
    }
}

void main()
{
    int vector[5];
    load(vector);
    ascendingOrder(vector);
    printf("Vector in ascending order \n");
    print(vector);
    descendingOrder(vector);
    printf("Vector in descending order \n");
    print(vector);
    getch();
    return 0;
}
