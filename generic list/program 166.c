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
    int amount=0;
    struct node *reco=root;
    while(reco!=NULL)
    {
        amount++;
        reco=reco->next;
    }
    return amount;
}

void insert(int position,int x)
{
    if(position<=amount()+1)
    {
        struct node *nuevo;
        nuevo=malloc(sizeof(struct node));
        nuevo->info=x;
        if(position==1)
        {
            nuevo->next=root;
            root=nuevo;
        }
        else
        {
            if(position==amount()+1)
            {
                struct node *reco=root;
                while(reco->next!=NULL)
                {
                    reco=reco->next;
                }
                reco->next=nuevo;
                nuevo->next=NULL;
            }
            else
            {
                struct node *reco=root;
                for(int r=1;r<=position-2;r++)
                {
                    reco=reco->next;
                }
                struct node *siguiente=reco->next;
                reco->next=nuevo;
                nuevo->next=siguiente;
            }
        }
    }
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
    printf("\n_____________________\n");
}

int extract(int position)
{
    if(position<=amount())
    {
        int information;
        struct node *del;
        if (position==1)
        {
            information=root->info;
            del=root;
            root=root->next;
        }
        else
        {
            struct node *reco=root;
            for(int r=1;r<=position-2;r++)
            {
                reco=reco->next;
            }
            struct node *prox=reco->next;
            reco->next=prox->next;
            information=prox->info;
            del=prox;
        }
        free(del);
        return information;
    }
    else
        return -1;
}

int deleteNode(int position)
{
    if(position<=amount())
    {
        struct node *del;
        if (position==1)
        {
            del=root;
            root=root->next;
        }
        else
        {
            struct node *reco=root;
            for(int r=1;r<=position-2;r++)
            {
                reco=reco->next;
            }
            struct node *prox=reco->next;
            reco->next=prox->next;
            del=prox;
        }
        free(del);
    }
}

void exchange(int position1,int position2)
{
    if(position1<=amount() && position2<=amount())
    {
        struct node *reco1=root;
        for(int r=1;r<position1;r++)
        {
            reco1=reco1->next;
        }
        struct node *reco2=root;
        for(int r=1;r<position2;r++)
        {
            reco2=reco2->next;
        }
        int aux=reco1->info;
        reco1->info=reco2->info;
        reco2->info=aux;
    }
}

int bigger()
{
    if(!empty())
    {
        int big=root->info;
        struct node *reco=root->next;
        while(reco!=NULL)
        {
            if(reco->info>big)
            {
                big=reco->info;
            }
            reco=reco->next;
        }
        return big;
    }
    else
        return -1;
}

int positionBigger()
{
    if(!empty())
    {
        int big=root->info;
        int x=1;
        int posit=x;
        struct node *reco=root->next;
        while(reco!=NULL)
        {
            if(reco->info>big)
            {
                big=reco->info;
                posit=x;
            }
            reco=reco->next;
            x++;
        }
        return posit;
    }
    else
        return -1;
}

int order()
{
    if(amount()>1)
    {
        struct node *reco1=root;
        struct node *reco2=root->next;
        while(reco2 != NULL)
        {
            if(reco2->info<reco1->info)
            {
                return 0;
            }
            reco2=reco2->next;
            reco1=reco1->next;
        }
    }
    return 1;
}

int main()
{
    insert(1,10);
    insert(2, 20);
    insert(3, 30);
    print();
    insert(2, 15);
    insert(1, 115);
    print();
    //printf("Extract the one from the second position: %i\n",extract(2));
    deleteNode(2);
    print();
    printf("Bigger on the list: %i\n",bigger());
    printf("Position of Bigger on the list: %i\n",positionBigger());
    if(order())
        printf("The list is ordered from smallest to biggest.\n");
    else
        printf("The list is NOT ordered from smallest to largest.\n");
    release();
    getch();
    return 0;
}
