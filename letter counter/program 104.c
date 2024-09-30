#include<stdio.h>
#include<conio.h>

void load(char world[40])
{
    printf("Enter a world: ");
    gets(world);
}


int counterLetter(char letter[40])
{
    int x=0,amount=0;
    while(letter[x]!='\0')
    {
        if(letter[x]=='a' || letter[x]=='e' || letter[x]=='i' || letter[x]=='o' || letter[x]=='u' ||
           letter[x]=='A' || letter[x]=='E' || letter[x]=='I' || letter[x]=='O' || letter[x]=='U')
        {
            amount++;
        }
        x++;
    }
    return amount;
}


int main()
{
    char w[40];
    load(w);
    printf("The world %s has %i vowels",w,counterLetter(w));
    getch();
    return 0;
}
