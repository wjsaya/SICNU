#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree();

void InorderTraversal( BinTree BT )
//中序LVR
{
    if(BT)
    {
        InorderTraversal( BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal( BT->Right);
    }
}
void PreorderTraversal( BinTree BT )
//先序VLR
{
    if(BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal( BT->Left);
        PreorderTraversal( BT->Right);
    }
}
void PostorderTraversal( BinTree BT )
//后序LRV
{
    if(BT)
    {
        PostorderTraversal( BT->Left);
        PostorderTraversal( BT->Right);
        printf(" %c", BT->Data);
    }
}

int IsEmpty_BinTree(BinTree *T)
{
    if(*T == NULL)
        return 1;
    else
        return 0;
}

void LevelorderTraversal( BinTree BT )
//层序
{
    int rear = 0;
    int front = 0;
    if(!BT) return;
    BinTree BinQueue[100];
    BinTree tempNode;
    if(!IsEmpty_BinTree(T))
    {
        BinQueue[rear++] = T; 

        while(front != rear)
        {
            tempNode = BinQueue[front++];
            if(!IsEmpty_BinTree(tempNode->Left))
                BinQueue[rear++] = temoNode->Left;

            if(!IsEmpty_BinTree(tempNode->Right))
                BinQueue[rear++] = temoNode->Right;

            printf(" %c", tempNode->Data);
        }
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */

