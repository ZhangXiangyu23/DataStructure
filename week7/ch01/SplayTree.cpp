#include <stdio.h>
#include <stdlib.h>
struct SplayNode
{
    int element;
    struct SplayNode* Left;
    struct SplayNode* Right;
};
typedef struct SplayNode *Splaytree;
typedef struct SplayNode *Position;
static Position Nullnode=NULL;
Splaytree MakeEmpty(Splaytree t);
Splaytree Find(int x,Splaytree t);
Splaytree FindMin(Splaytree t);
Splaytree FindMax(Splaytree t);
Splaytree Initialize();
Splaytree Insert(int x,Splaytree t);
Splaytree Remove(int x,Splaytree t);
int Retrieve(Splaytree t);
Splaytree Splay(int item,Position x);



Splaytree Initialize()
{
    if (Nullnode==NULL)
    {
        Nullnode=(Splaytree)malloc(sizeof(struct SplayNode));
        if(Nullnode==NULL)
            printf("Out of space£¡");
        Nullnode->Left=Nullnode->Right=Nullnode;
    }
    return Nullnode;
}

Splaytree Splay(int item,Position x)
{
    static struct SplayNode Header;
    Position LeftMax,RightMin;
    Header.Left=Header.Right=Nullnode;
    LeftMax=RightMin=&Header;
    Nullnode->element=item;
    while(item!=x->element)
    {
        if(item<x->element)
        {
            if(item<x->Left->element)
                x=SingleRotateWithLeft(x);
            if(x->Left==Nullnode)
                break;
            RightMin->Left=x;
            RightMin=x;
            x=x->Left; 
        }
        else{
            if (item>x->Right->element)
                x=SingleRotateWithRight(x);
            if(x->Right==Nullnode)
                break;
            LeftMax->Right=x;
            LeftMax=x;
            x=x->Right;
        }
        LeftMax->Right=x->Left;
        RightMin->Left=x->Right;
        x->Right=Header.Left;
        x->Left=Header.Right;
    }
}


Splaytree Insert(int item,Splaytree t)
{
    static Position Newnode =NULL;
    if(Newnode==NULL)
    {
        Newnode=(Splaytree)malloc(sizeof(struct SplayNode));
        if(Newnode==NULL)
            printf("Out of space");
    }
    Newnode->element=item;
    if(t==Nullnode)
    {
        Newnode->Left=Newnode->Right=Nullnode;
        t=Newnode;
    }
    else 
    {
        t=Splay(item,t);
        if(item<t->element)
        {
            Newnode->Left=t->Left;
            Newnode->Right=t;
            t->Left=Nullnode;
            t=Newnode;
        }
        else if(t->element<item)
        {
            Newnode->Right=t->Right;
            Newnode->Left=t;
            t->Right=Nullnode;
            t=Newnode;
        }
        else
            return t;
    }
    Newnode=NULL;
    return t;
}


Splaytree Remove(int item,Splaytree t)
{
    Position Newtree;
    if(t!=Nullnode)
    {
        t=Splay(item,t);
        if(item==t->element)
        {
            if(t->Left==Nullnode)
                Newtree=t->Right;
            else
            {
                Newtree=t->Left;
                Newtree=Splay(item,Newtree);
                Newtree->Right=t->Right;
            }
            free(t);
            t=Newtree;
        }
    }
    return t;
}


