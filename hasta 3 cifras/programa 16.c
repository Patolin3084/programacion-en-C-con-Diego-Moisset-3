#include<stdio.h>
#include<conio.h>

int main()
{
    int num;
    printf("Ingrese un valor pasitivo de hasta 3 cifras:");
    scanf("%i", &num);
    if (num<10)
    {
        printf("Este numero es de 1 cifra");
    }
    else
    {
        if (num<100)
        {
            printf("Este numero es de 2 cifras");
        }
        else
        {
            if (num<1000)
            {
                 printf("Este numero es de 3 cifras");
            }
            else
            {
                printf("Error: debes ingresar un numero positivo de hasta 3 cifras!");
            }

        }
    }
    getch();
    return 0;
}
