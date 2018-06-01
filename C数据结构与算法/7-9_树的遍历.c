#include<stdio.h>
#define MAXSIZE 30
struct TNode {
    int Data;
    struct TNode *Left;
    struct TNode *Right;
};

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

void putBinTree(struct TNode *BT) {
    struct TNode *s[MAXSIZE];
    int t = 0, k = 1;
    s[t] = BT;
    while(t != k) {
        if(!t) {
            printf("%d", s[t]->Data); //第一个数字不加空格 
        }
        else {
            printf(" %d", s[t]->Data); //非第一个前面加空格，这样保证了最后不会有多于的空格 
        }
        if(s[t]->Left) {
            s[k] = s[t]->Left;
            k = (k+1) % MAXSIZE;
        }
        if(s[t]->Right) {
            s[k] = s[t]->Right;
            k = (k+1) % MAXSIZE;
        }
        t = (t+1) % MAXSIZE;
    }
}

int main()
{
    int i, n;
    int sh[MAXSIZE], sz[MAXSIZE];
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        scanf("%d", &sh[i]);
    }   
    for(i = 0; i < n; i ++) {
        scanf("%d", &sz[i]);
    }   
    struct TNode *BT = CreateBinTree(n, sh, sz);
    putBinTree(BT);
    return 0;
}
