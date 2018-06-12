#include<stdio.h>
#define MAXSIZE 30
struct TNode {
    char Data;
    struct TNode *Left;
    struct TNode *Right;
};

int getlen(char inarr[]) {
    int i;
    for (i=0; ;i++) {
        if (inarr[i] == '\0')
            break;
    }
    return i;
}

void p(char inarr[]) {
    int i;
    for(i=0;;i++) {
        if(inarr[i] == '\0')
            break;
        printf("|%c", inarr[i]);
    }
    printf("\n");
}

void putBinTree(struct TNode *BT) {
    if(BT)
    {
        putBinTree( BT->Left);
        putBinTree( BT->Right);
        printf("%c", BT->Data);
    }
}


struct TNode *CreateBinTree(int n, char sq[], char sz[]) {
    //n为0，那么节点个数为0.
    int tag=0;
    if (n == 0)
        return NULL;
//n不为0，则有新的节点
    struct TNode *BT = (struct TNode *)malloc(sizeof(struct TNode));
//取出先序遍历的第一个值，作为当前新节点的Data值。
    BT->Data = sq[0];
//找到先序遍历第一个值在中序遍历数组中的位置，即为当前节点左子树的节点个数。
    for(tag=0; tag<n; tag++) {
        if(BT->Data == sz[tag]) {
            break;
        }
    }
/*
    printf("--------------------------------------------\n\n");
    printf("n=%d\t\ttag=%d\n", n, tag);
    printf("Q:"); p(sq);
    printf("Z:"); p(sz);
    printf("--------------------------------------------\n\n");
*/
    BT->Left = CreateBinTree(tag, sq+1, sz);
    BT->Right = CreateBinTree(n-tag-1, sq+tag+1, sq+tag+1);
    return BT;
}


int main(void)
{
    int i, n;
    char sq[MAXSIZE], sz[MAXSIZE]; //后，中
    char in;
    while(scanf("%s %s", sq, sz)) {
        n = getlen(sq);
        struct TNode *BT = CreateBinTree(n, sq, sz);
        putBinTree(BT);
        printf("\n");
    }
    return 0;
}

