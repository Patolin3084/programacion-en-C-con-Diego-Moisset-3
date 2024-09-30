#include<stdio.h>
#include<conio.h>

int main()
{
    int x, n, cantidad;
    float largo;
    x=1;
    cantidad=0;
    printf("Cuantas piezas va a procesar:");
    scanf("%i", &n);
    while (x<=n)
    {
        printf("Ingrese la medida de la pieza:");
        scanf("%f", &largo);
        if (largo>=1.20 && largo<=1.30)
        {
            cantidad=cantidad+1;
        }
        x=x+1;
    }
    printf("la cantidad de piezas aptas son:");
    printf("%i", cantidad);
    getch();
    return 0;
}
