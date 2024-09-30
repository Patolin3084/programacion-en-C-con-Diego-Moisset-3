#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void enterPass()
{
    char pass[50];
    int chance=0;
    do{
        if(chance==3)
        {
            exit(1);
        }
        printf("Enter the pass:");
        gets(pass);
        chance++;
    }while(strcmp(pass,"123abc")!=0);
}

int main()
{
    enterPass();
    printf("Welcome\n");
    getch();
    return 0;
}
