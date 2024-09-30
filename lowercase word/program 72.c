#include<stdio.h>
#include<conio.h>

int main()
{
    char word[30];
    int amount=0,x=0;
    printf("Enter a lowercase word: ");
    gets(word);
    while(word[x]!='\0')
    {
        if(word[x]=='a' || word[x]=='e' || word[x]=='i' || word[x]=='o' || word[x]=='u')
        {
            amount++;
        }
        x++;
    }
    printf("The number of vowels that the word %s has is %i",word,amount);
    getch();
    return 0;
}
