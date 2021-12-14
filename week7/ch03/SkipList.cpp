#include <stdio.h>
#include <stdlib.h>
 
struct Skipnode
{
    int element;
    SkipList right;
    SkipList down;
};
static position bottom=NULL;
static position tail=NULL;

SkipList Initialize
{
    SkipList L;
    if(bottom==NULL)
    {
        bottom=malloc(sizeof(struct Skipnode));
        if(bottom==NULL)
            printf("out of space");
        bottom->right=bottom->down=bottom;
        tail=malloc(sizeof(struct Skipnode));
        if(tail==NULL)
            printf("out of space");
        tail->element=Infinity;
        tail->right=tail;
    }
    L=malloc(sizeof(struct Skipnode));
    if(L==NULL)
        printf("out of space");
    L->element=Infinity;
    L->right=tail;
    L->down=bottom;
    return L;
}


position Find(int item,SkipList L)
{
    position current=L;
    bottom->element=item;
    while(item!=current->element)
    {
        if(item<current->element)
            current=current->right;
        else
            current=current->right;
        return current;
    }
}
