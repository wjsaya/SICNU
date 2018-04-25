#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MaxSize 100

typedef struct TreeNode * BinTree;
struct TreeNode{
    int Date;
    struct TreeNode *Left;
    struct TreeNode *Right;
};

typedef struct{
    BinTree Date[MaxSize];
    int front;
    int rear;
} Queue;

int IsEmptyQ(Queue * Q)
{
    if(Q->front==Q->rear)
        return 1;
    else
        return 0;
}

void AddQ(Queue *Q, BinTree item)
{
    if((Q->rear+1)%MaxSize == Q->front){
        printf("队已满\n");
        return;
    }
    else{
        Q->rear = (Q->rear+1)%MaxSize;
        Q->Date[Q->rear] = item;
    }

}
BinTree DeleteQ(Queue *Q)
{
    if(Q->rear == Q->front){
        printf("队已空\n");
        return NULL;
    }
    else{
        Q->front = (Q->front+1)%MaxSize;
        return Q->Date[Q->front];
    }
}



#endif // QUEUE_H_INCLUDED
