#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char uss[41];
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
        printf(" %s  -",reco->uss);
        reco=reco->next;
    }
    printf("\n");
}

void insert(char *x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    strcpy(nuevo->uss,x);
    nuevo->next=NULL;
    if(root==NULL)
    {
        root=nuevo;
    }
    else
    {
        if(strcmp(x,root->uss)<0)
        {
            nuevo->next=root;
            root=nuevo;
        }
        else
        {
            struct node *reco=root;
            struct node *back=root;
            while(strcmp(x,reco->uss)>0 && reco->next!=NULL)
            {
                back=reco;
                reco=reco->next;
            }
            if(strcmp(x,reco->uss)>0)
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
    insert("marcos");
    insert("leonardo");
    insert("maria");
    insert("belen");
    insert("borja");
    insert("ted");
    print();
    release();
    getch();
    return 0;
}
