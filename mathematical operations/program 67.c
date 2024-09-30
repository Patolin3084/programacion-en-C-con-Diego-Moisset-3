#include<stdio.h>
#include<conio.h>

int main()
{
    int value1,value2;
    float result;
    char sign;
    printf("Enter the first value: ");
    scanf("%i",&value1);
    printf("Enter the second value: ");
    scanf("%i",&value2);
    printf("Enter the sign of the operation you want to do: ");
    scanf(" %c",&sign);
    if(sign=='+')
    {
        result=value1+value2;
        printf("The result of adding the first an the second value is: %f",result);
    }
    else
    {
        if(sign=='-')
        {
            result=value1-value2;
            printf("The result of subtracting the first an the second value is: %f",result);
        }
        else
        {
            if(sign=='*')
            {
                result=value1*value2;
                printf("The result of multiplying the first an the second value is: %f",result);
            }
            else
            {
                if(sign=='/')
                {
                    result=value1/value2;
                    printf("The result of dividing the first an the second value is: %f",result);
                }
            }
        }
    }
    getch();
    return 0;
}
