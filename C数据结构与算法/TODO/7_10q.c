#include<stdio.h>
#define MAXSIZE 99999

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
        printf("%c", inarr[i]);
    }
    printf("\n");
}

void putBinTree(struct TNode *BT) {
    struct TNode *s[MAXSIZE];
    int t = 0, k = 1;
    s[t] = BT;
    while(t != k) {
        if(!t) {
            printf("%C", s[t]->Data); //第一个数字不加空格 
        }
        else {
            printf("%C", s[t]->Data); //非第一个前面加空格，这样保证了最后不会有多于的空格 
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


struct TNode *CreateBinTree(int n, char sh[], char sz[]) {
    //n为0，那么节点个数为0.
    int tag=0;
    if (n == 0)
        return NULL;
//n不为0，则有新的节点
    struct TNode *BT = (struct TNode *)malloc(sizeof(struct TNode));
//取出后序遍历的最后一个值，作为当前新节点的Data值。
    BT->Data = sh[n--];
//找到后序遍历最后一个值在中序遍历数组中的位置，即为当前节点左子树的节点个数。
    for(tag=0; tag<n; tag++) {
        if(BT->Data == sz[tag]) {
            break;
        }
    }
    
    printf("n=%d\t\ttag=%d\n", n, tag);
    p(sh);
    p(sz);
    getchar();

    BT->Left = CreateBinTree(tag, sh, sz);
    BT->Right = CreateBinTree(n-tag-1, sh+tag, sz+tag+1);
    return BT;
}


int main()
{
    int i, n;
    char sh[MAXSIZE], sz[MAXSIZE]; //后，中
    char in;
        memset(sh, 0, MAXSIZE);
        memset(sz, 0, MAXSIZE);
        for(i = 0; ; i++)
        {
            scanf("%c", &in);
            if(in == ' ')
                break;
            sh[i] = in;
        }

        for(i=0; ;i++)
        {
            scanf("%c", &in);
            if(in == '\n')
                break;
            sz[i] = in;
        }
        n = getlen(sh);
        printf("%d\n", n);
       p(sh);
       p(sz);
        struct TNode *BT = CreateBinTree(n, sh, sz);
        putBinTree(BT);
    return 0;
}

