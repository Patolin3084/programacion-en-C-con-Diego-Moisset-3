#include<stdio.h>
#include<conio.h>

void load(float heights[5])
{
    int x;
    for(x=0;x<5;x++)
    {
        printf("Enter the height: ");
        scanf("%f",&heights[x]);
    }
}

float average(float heights[5])
{
    int x;
    float add=0,prom;
    for(x=0;x<5;x++)
    {
        add=add+heights[x];
    }
    prom=add/5;
    printf("Average of heights: %0.2f\n",prom);
    return prom;
}

void discrimination(float heights[5],float prom)
{
    int x,talls=0,shorts=0;
    for(x=0;x<5;x++)
    {
        if(heights[x]>prom)
        {
            talls++;
        }
        else
        {
            shorts++;
        }
    }
    printf("The numbers of people taller than average are: %i\n",talls);
    printf("The numbers of people shorter than average are: %i\n",shorts);
}

int main()
{
    float h[5],prom;
    load(h);
    prom=average(h);
    discrimination(h,prom);
    getch();
    return 0;
}
