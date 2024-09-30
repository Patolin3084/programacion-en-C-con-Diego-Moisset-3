#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
    struct node *former;
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

int amount()
{
    struct node *reco=root;
    int amount=0;
    while(reco!=NULL)
    {
        amount++;
        reco=reco->next;
    }
    return amount;
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

void insert(int pos,int x)
{
    if(pos<=amount()+1)
    {
        struct node *nuevo;
        nuevo=malloc(sizeof(struct node));
        nuevo->info=x;
        nuevo->former=NULL;
        nuevo->next=NULL;
        if(pos==1)
        {
            nuevo->next=root;
            if(root!=NULL)
            {
                root->former=nuevo;
            }
            root=nuevo;
        }
        else
        {
            if(pos==amount()+1)
            {
                struct node *reco=root;
                while(reco->next!=NULL)
                {
                    reco=reco->next;
                }
                reco->next=nuevo;
                nuevo->former=reco;
            }
            else
            {
                struct node *reco=root;
                for(int r=1;r<=pos-2;r++)
                {
                    reco=reco->next;
                }
                struct node *siguiente=reco->next;
                reco->next=nuevo;
                nuevo->former=reco;
                nuevo->next=siguiente;
                siguiente->former=nuevo;
            }
        }
    }
}

void printReverse()
{
    if(root!=NULL)
    {
    struct node *reco=root;
    while(reco->next!=NULL)
    {
        reco=reco->next;
    }
    printf("Full list in reverse\n");
    while(reco!=NULL)
    {
        printf(" %i ",reco->info);
        reco=reco->former;
    }
    printf("\n");
    }
}

int extract(int pos)
{
    if(pos<=amount())
    {
        int information;
        struct node *del;
        if(pos==1)
        {
            information=root->info;
            del=root;
            root=root->next;
            if(root!=NULL)
            {
                root->former=NULL;
            }
        }
        else
        {
            struct node *reco=root;
            for(int r=1;r<=pos-2;r++)
            {
                reco=reco->next;
            }
            struct node *prox=reco->next;
            del=prox;
            reco->next=prox->next;
            struct node *siguiente=prox->next;
            if(siguiente!=NULL)
            {
                siguiente->former=reco;
            }
            information=prox->info;
        }
        free(del);
        return information;
    }
    else
        return -1;
}

int main()
{
    insert(1,10);
    insert(2,20);
    insert(3,30);
    insert(1,200);
    insert(2,45);
    print();
    printReverse();
    printf("Extract the 3rd of the list: %i\n",extract(3));
    print();
    release();
    getch();
    return 0;
}

