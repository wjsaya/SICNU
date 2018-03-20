#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct ListNode)

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist()   {
    struct ListNode *head, *p1, *p2;
    char input;
    head = NULL;
    p2 = NULL;
    printf("input numbers(# to stop)\n");
    scanf("%c", &input);
    while(input != '#') {
        printf("%c\n",input);
        p1 = malloc(LEN);
        p1->data = input;
        if(head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        scanf("%d", &input);
    }
    p2->next = NULL;
    return head;
    }


int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */











