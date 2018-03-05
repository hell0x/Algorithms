#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node{
    int  Ele;
    Position Next;
};
void
PrintArray(List L)
{
    Position p;
    p = L;
    while( p->Next != NULL )
    {
        printf("%d",p->Next->Ele);
        p = p->Next;
    }
}
Position
CreateTable( void )
{
    PtrToNode L;
    L = malloc( sizeof( struct Node ) );
    if( L == NULL){
        printf("out of space ");
        return ;
    }
    L->Next = NULL;
    return L;
}

int main()
{

    int i;
    Position L,p;
    PtrToNode TmpCell;
    L = CreateTable();
    p = L;
    for(i = 0; i<3; i++ )
    {
        TmpCell = malloc(sizeof(struct Node ));
        if(TmpCell == NULL)
        {
            printf("error");
            return;
        }
        p->Next = TmpCell;

        TmpCell->Ele = i;
        TmpCell->Next = NULL;

        p = TmpCell;
    }
    PrintArray( L );
}