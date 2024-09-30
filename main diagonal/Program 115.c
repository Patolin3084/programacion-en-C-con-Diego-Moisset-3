#include<stdio.h>
#include<conio.h>

void load(int matrix[4][4])
{
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            printf("Enter the element:");
            scanf("%i",&matrix[r][c]);
        }
    }
}

void print(int matrix[4][4])
{
     for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            printf("%i  ",matrix[r][c]);
        }
        printf("\n");
    }
}

void printMainDiagonal(int matrix[4][4])
{
    /*printf("Elements of the main diagonal\n");
    printf("%i-",matrix[0][0]);
    printf("%i-",matrix[1][1]);
    printf("%i-",matrix[2][2]);
    printf("%i-",matrix[3][3]);*/

    /*for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            if (r==c)
            {
                printf("%i-",matrix[r][c]);
            }
        }
    }*/

    for(int k=0;k<4;k++)
    {
        printf("%i-",matrix[k][k]);
    }
}

int main()
{
    int matrix[4][4];
    load(matrix);
    print(matrix);
    printMainDiagonal(matrix);
    getch();
    return 0;
}
