#include<stdio.h>
#define MAXSIZE 26
struct TNode {
    int Data;
    struct TNode *Left;
    struct TNode *Right;
};

void p(char in[]) {
    int i=0;
    while(in[i] !='\0')
        printf("%c ", in[i]);
    printf("\n");
}

struct TNode *CreateBinTree(int n, int sh[], int sz[]) {
//n为0，那么节点个数为0.
    int tag=0;
    if (n == 0)
        return NULL;
//n不为0，则有新的节点
    struct TNode *BT = (struct TNode *)malloc(sizeof(struct TNode));
//取出后序遍历的最后一个值，作为当前新节点的Data值。
    BT->Data = sh[n-1];
//找到后序遍历最后一个值在中序遍历数组中的位置，即为当前节点左子树的节点个数。
    for(tag=0; tag<n; tag++) {
        if(BT->Data == sz[tag]) {
            break;
        }
    }
    BT->Left = CreateBinTree(tag, sh, sz);
    BT->Right = CreateBinTree(n-tag-1, sh+tag, sz+tag+1);
    return BT;
}

int main()
{
    int i;
    char sh[MAXSIZE], sz[MAXSIZE];
    char IN;
    int JU=0;
    for(i=0;scanf("%c", &IN);i++) {
        if(IN == " ")
            JU = 1;

        if(JU == 0)
            sh[i] = IN;
        else
            sz[i] = IN;
    }

    p(sh);
//    struct TNode *BT = CreateBinTree(n, sh, sz);
//    putBinTree(BT);
    return 0;
}
