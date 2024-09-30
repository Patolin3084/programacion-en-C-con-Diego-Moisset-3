#include<stdio.h>
#include<conio.h>

void load(char names[5][41])
{
    for(int r=0;r<5;r++)
    {
        printf("Enter the name of the person: ");
        gets(names[r]);
    }
}
void print(char names[5][41])
{
    for(int r=0;r<5;r++)
    {
        printf("%s\n",names[r]);
    }
}

void search(char names[5][41])
{
    char nam[41];
    int exist=0;
    printf("Enter the name to search: ");
    gets(nam);
    for(int f=0;f<5;f++)
    {
        if(strcmp(nam,names[f])==0)
        {
            exist=1;
        }
    }
    if(exist==1)
    {
        printf("The name is stored in the array");
    }
    else
    {
        printf("The name is NOT stored in the array");
    }
}


int main()
{
    char names[5][41];
    load(names);
    print(names);
    search(names);
    getch();
    return 0;
}
