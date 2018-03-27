#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
    int input;
    struct ListNode *head=NULL, *in=NULL, *node=NULL;

    scanf("%d", &input);
    in = (struct ListNode *)malloc(sizeof(struct ListNode));
    in->data = input;
    in->next = NULL;
    head = in;
        
    while(input != -1)
    {
        scanf("%d", &input);
        if(input == -1)
            return head;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->data = input;
        node->next = NULL;
        in->next = node;
        in = node;
    }
    return head;
}


struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode *p, *n;

    if(head != NULL)
    {
        p = head;
        n = head->next;
    }
  
    while(n != NULL)
    {
        p->next = n->next;
        p = n->next;
        free(n);
        
        if(p != NULL)
            n = p->next;
        else
            n = NULL;
    }
return head;
}
