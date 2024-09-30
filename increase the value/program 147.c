#include<stdio.h>
#include<conio.h>

void increase(int *pe)
{
    *pe=*pe+1;
}


int main()
{
    int x=0;
    printf("%i\n",x);
    increase(&x);
    printf("%i\n",x);
    increase(&x);
    printf("%i\n",x);
    int z=100;
    printf("\n%i\n",z);
    increase(&z);
    printf("%i\n",z);
    increase(&z);
    printf("%i\n",z);
    getch();
    return 0;
}
