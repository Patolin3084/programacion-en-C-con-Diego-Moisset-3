#include<stdio.h>
#include<conio.h>

void counter(int value)
{
    if(value<0)
    {
        printf("Error");
    }
    else
    {
        int x;
        for(x=1;x<=value;x++)
        {
            printf("%i",x);
            printf(" - ");
        }

    }
}

int main()
{
    int x=100;
    counter(x);
    getch();
    return 0;
}
