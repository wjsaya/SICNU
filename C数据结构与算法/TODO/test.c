#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 31 

struct TNode{
    int Data;
    struct TNode *Left;
    struct TNode *Right;
};

void p(int sin[]) {
    int i=0;
    while(sin[i] != '\0') {
        printf("%d ", sin[i]);
        i++;
    }
    printf("\n");
}

struct TNode *PutBinTree(int s1[], int s2[], int k) {
    printf("s1|  ");
    p(s1);
    printf("s2|  ");
    p(s2);
    printf("k=%d\n",k);
/*s1为存放后序遍历的数组，s2为存放中序遍历的数组，k代表当前结点的左右子树结点的个数和*/ 
    int i, t;
    if(k == 0) { //如果k为0表示左右子树的个数和为0，即当前结点为叶子结点 
        return NULL;  //叶子结点然后空值。 
    }
    struct TNode *BT = (struct TNode *)malloc(sizeof(struct TNode));
    t = s1[k-1];//t取后序的最后一个结点 
    BT->Data = t;//t即为根结点，所以直接存放在根结点的数据区 
    printf("root = %d\n", t);
    printf("------------------------\n");
    for(i = 0; i < k; i ++) {
        /*遍历中序中t的位置，i充当一个计数器，
        当找到t时，i的值即为根结点左边的个数，
        也就是左子树的结点个数*/ 
        if(s2[i] == t) {  
            break;
        }
    }
    /*s1、s2即数组的首地址，把左子树看成一个新的二叉树，而这颗全新的树的结点个数就为i*/ 
    BT->Left = PutBinTree(s1, s2, i);
    //printf("s1=%d, s2=%d, k=%d\n",s1, s2, k);
    /*s1+i就得到后序遍历第一个右子树结点的地址，
    s2+i+1同理也是找到中序遍历中第一个结点的地址，
    k-i就去掉了左子树的个数，再-1就去掉了根结点的个数*/ 
    BT->Right = PutBinTree(s1+i, s2+i+1, k-i-1);

    return BT;
}

/*层序遍历，非递归方式(用到队列的思想)*/ 
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
    int s1[MAXSIZE], s2[MAXSIZE];
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        scanf("%d", &s1[i]);
    }
    for(i = 0; i < n; i ++) {
        scanf("%d", &s2[i]);
    }
    struct TNode *BT = PutBinTree(s1, s2, n);
    putBinTree(BT);

    return 0;
}
