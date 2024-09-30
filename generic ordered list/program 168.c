#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *root=NULL;

void release()
{
    struct node *reco=root;
    struct node *del;
    while(reco!=NULL)
    {
        del=reco;
        reco=reco->next;
        free(del);
    }
}

int empty()
{
    if(root==NULL)
        return 1;
    else
        return 0;
}

void print()
{
    struct node *reco=root;
    printf("Full list\n");
    while(reco!=NULL)
    {
        printf(" %i ",reco->info);
        reco=reco->next;
    }
    printf("\n");
}

void insert(int x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    nuevo->info=x;
    nuevo->next=NULL;
    if(root==NULL)
       root=nuevo;
    else
    {
        if(x<root->info)
        {
            nuevo->next=root;
            root=nuevo;
        }
        else
        {
            struct node *reco=root;
            struct node *back=root;
            while(x>=reco->info && reco->next!=NULL)
            {
                back=reco;
                reco=reco->next;
            }
            if(x>=reco->info)
            {
                reco->next=nuevo;
            }
            else
            {
                nuevo->next=reco;
                back->next=nuevo;
            }
        }
    }
}

int main()
{
    insert(10);
    insert(5);
    insert(7);
    insert(50);
    insert(1);
    insert(8);
    print();
    release();
    getch();
    return 0;
}
