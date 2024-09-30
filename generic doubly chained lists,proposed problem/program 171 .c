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

void insertFirst(int x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    nuevo->info=x;
    nuevo->former=NULL;
    nuevo->next=root;
    if(root!=NULL)
    {
        root->former=nuevo;
    }
    root=nuevo;
}

void insertEnd(int x)
{
    struct node *nuevo;
    nuevo=malloc(sizeof(struct node));
    nuevo->info=x;
    nuevo->next=NULL;
    nuevo->former=NULL;
    if(empty())
        root=nuevo;
    else
    {
        struct node *reco=root;
        while(reco->next!=NULL)
        {
            reco=reco->next;
        }
        reco->next=nuevo;
        nuevo->former=reco;
    }
}

void insertSecond(int x)
{
    if(root!=NULL)
    {
        struct node *nuevo;
        nuevo=malloc(sizeof(struct node));
        nuevo->info=x;
        nuevo->next=NULL;
        nuevo->former=NULL;
        if(root->next==NULL)
        {
            root->next=nuevo;
            nuevo->former=root;
        }
        else
        {
            struct node *second=root->next;
            nuevo->next=second;
            nuevo->former=root;
            root->next=nuevo;
            second->former=nuevo;
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
        nuevo->former=NULL;
        nuevo->next=NULL;
        if(root->next==NULL)
        {
            nuevo->next=root;
            root->former=nuevo;
            root=nuevo;
        }
        else
        {
            struct node *reco=root;
            while(reco->next!=NULL)
            {
                    reco=reco->next;
            }
            struct node *beforelast=reco->former;
            beforelast->next=nuevo;
            nuevo->former=beforelast;
            nuevo->next=reco;
            reco->former=nuevo;
        }
    }
}

void deleteFirst()
{
    if(root!=NULL)
    {
        struct node *del=root;
        root=root->next;
        if(root!=NULL)
        {
            root->former=NULL;
        }
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
            if(third!=NULL)
            {
                third->former=root;
            }
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
            struct node *reco=root;
            while(reco->next!=NULL)
            {
                reco=reco->next;
            }
            struct node *ante=reco->former;
            ante->next=NULL;
            free(reco);
        }
    }
}

void deleteHigher()
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
        struct node *del;
        while(reco!=NULL)
        {
            if(reco->info==higher)
            {
                if(reco==root)
                {
                    del=root;
                    root=root->next;
                    if(root!=NULL)
                    {
                        root->former=NULL;
                    }
                    free(del);
                    return;
                }
                else
                {
                    if(reco->next==NULL)
                    {
                        del=reco;
                        reco=reco->former;
                        reco->next=NULL;
                        free(del);
                        return;
                    }
                    else
                    {
                        struct node *ante=reco->former;
                        del=reco;
                        reco=reco->next;
                        ante->next=reco;
                        reco->former=ante;
                        free(del);
                        return;
                    }
                }
            }

            else
            {
                reco=reco->next;
            }
        }
    }
}

int main()
{
    insertFirst(20);
    insertFirst(10);
    insertFirst(5);
    insertFirst(70);
    insertFirst(1);
    print();
    insertEnd(400);
    print();
    insertSecond(9);
    print();
    insertBeforelast(1000);
    print();
    deleteFirst();
    print();
    deleteSecond();
    print();
    deleteLast();
    print();
    deleteHigher();
    print();
    release();
    getch();
    return 0;
}
