#include<stdio.h>
#include<conio.h>

int main()
{
    int f,age[2];
    char sex[2];
    for(f=0;f<2;f++)
    {
        printf("Enter the age of the person: ");
        scanf("%i",&age[f]);
        printf("Enter the sex of the person [m/f]: ");
        scanf(" %c",&sex[f]);
    }
    printf("\n");
    if(age[0]<age[1])
    {
        printf("The age of the oldest person is %i\n",age[1]);
        {
            if(sex[1]=='m')
            {
                printf("and his sex is male");
            }
            else
            {
                if(sex[1]=='f')
                {
                    printf("and his sex is female");
                }
            }
        }
    }
    else
    {
        if(age[0]>age[1])
            {
                printf("The age of the oldest person is %i\n",age[0]);
            }
                 if(sex[0]=='m')
                {
                    printf("and his sex is male");
                }
                else
                {
                    if(sex[0]=='f')
                    {
                        printf("and his sex is female");
                    }
                }
    }
    getch();
    return 0;
}
