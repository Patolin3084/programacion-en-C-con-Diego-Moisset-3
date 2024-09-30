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

void insertFirst(int x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    nuevo->info=x;
    nuevo->next=root;
    root=nuevo;
}

void insertEnd(int x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    nuevo->info=x;
    nuevo->next=NULL;
    if(root==NULL)
        root=nuevo;
    else
    {
        struct node *reco=root;
        while(reco->next!=NULL)
        {
            reco=reco->next;
        }
        reco->next=nuevo;
    }
}

void insertSecond(int x)
{
    if(root!=NULL)
    {
        struct node *nuevo;
        nuevo=malloc(sizeof(struct node));
        nuevo->info=x;
        if(root->next==NULL)
        {
            root->next=nuevo;
            nuevo->next=NULL;
        }
        else
        {
            nuevo->next=root->next;
            root->next=nuevo;
        }
    }
}

void insertBeforelast(int x)
{
    if(root!=NULL)
    {
        struct node *nuevo;
        nuevo=malloc(sizeof(struct node));
        nuevo->info=x;
        if(root->next==NULL)
        {
            nuevo->next=root;
            root=nuevo;
        }
        else
        {
            struct node *back=root;
            struct node *reco=root->next;
            while(reco->next!=NULL)
            {
                    back=reco;
                    reco=reco->next;
            }
            nuevo->next=back->next;
            back->next=nuevo;
        }
    }
}

void deleteFirst()
{
    if(root!=NULL)
    {
        struct node *del=root;
        root=root->next;
        free(del);
    }
}

void deleteSecond()
{
    if(root!=NULL)
    {
        if(root->next!=NULL)
        {
            struct node *del=root->next;
            struct node *third=root->next;
            third=third->next;
            root->next=third;
            free(del);
        }
    }
}

void deleteLast()
{
    if(root!=NULL)
    {
        if(root->next==NULL)
        {
            free(root);
            root=NULL;
        }
        else
        {
            struct node *reco=root->next;
            struct node *back=root;
            while(reco->next!=NULL)
            {
                back=reco;
                reco=reco->next;
            }
            back->next=NULL;
            free(reco);
        }
    }
}

void deleteHighest()
{
     if(root!=NULL)
     {
         struct node *reco=root;
         int higher=root->info;
         while(reco!=NULL)
         {
             if(reco->info>higher)
             {
                 higher=reco->info;
             }
             reco=reco->next;
         }
         reco=root;
         struct node *back=root;
         struct node *del;
         while(reco!=NULL)
         {
             if(reco->info==higher)
             {
                 if(reco==root)
                 {
                     del=root;
                     root=root->next;
                     back=root;
                     reco=root;
                     free(del);
                 }
                 else
                 {
                     back->next=reco->next;
                     del=reco;
                     reco=reco->next;
                     free(del);
                 }
             }
             else
             {
                 back=reco;
                 reco=reco->next;
             }
         }
     }
}

int main()
{
    insertFirst(10);
    insertFirst(30);
    insertFirst(70);
    print();
    insertEnd(200);
    print();
    insertSecond(400);
    print();
    insertBeforelast(500);
    print();
    deleteFirst();
    print();
    deleteSecond();
    print();
    deleteLast();
    print();
    deleteHighest();
    print();
    release();
    getch();
    return 0;
}
