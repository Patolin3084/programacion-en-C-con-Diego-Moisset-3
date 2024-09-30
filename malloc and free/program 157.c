#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int *pe;
    int tam;
    printf("How many elements will the vector have? :");
    scanf("%i",&tam);
    pe=malloc(tam*sizeof(int));
    for(int r=0;r<tam;r++)
    {
        printf("Enter the element:");
        scanf("%i",&pe[r]);
    }
    printf("Vector content.\n");
    for(int r=0;r<tam;r++)
    {
        printf("%i ",pe[r]);
    }
    free(pe);
    getch();
    return 0;
}
