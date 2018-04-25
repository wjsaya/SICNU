#include <stdio.h>
#include <stdlib.h>
//要求函数返回给定二叉树BT的高度值。

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree()
{
    char ch;
    scanf("%c",&ch);
    struct TNode *root;
    root=(struct TNode *)malloc(sizeof(struct TNode));
    root->Data=ch;
    root->Left = NULL;
    root->Right = NULL;
    return(root);
}



int GetHeight( BinTree BT )
{
    int HL, HR, Hmax;

    if(BT)
    {
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        Hmax = HL > HR ? HL : HR;
        //取最大值
        return(Hmax + 1);
    }
    else
        return 0;
}

int main()
{
    BinTree BT = CreatBinTree();
    //printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
