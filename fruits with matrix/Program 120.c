#include<stdio.h>
#include<conio.h>

void load(char fruits[3][31])
{
    for(char r=0;r<3;r++)
    {
        printf("Enter the name of the fruit: ");
        gets(fruits[r]);
    }
}

void print(char fruits[3][31])
{
    printf("The matrix has been loaded in the following way: \n");
    for(char r=0;r<3;r++)
    {
        printf("%s\n",fruits[r]);
    }
}

void main()
{
    char fruits[3][31];
    load(fruits);

    print(fruits);
    getch();
    return 0;
}
