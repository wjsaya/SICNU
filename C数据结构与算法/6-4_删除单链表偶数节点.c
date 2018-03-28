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
     //      printf("%d:%d\n", p, p->data);
           printf("%d ",p->data);
           p = p->next;
     }
}

int main()
{
    struct ListNode *head;
    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
} 

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
	struct ListNode *newl, *re;
	newl = (struct ListNode *)malloc(sizeof(struct ListNode));
	re = newl;
	while(head)
	{
		if(head->data % 2 != 0)
		{
			//printf("%d\n",pre->data);
			newl->next = head;
			newl = newl->next;
		}
		head = head->next; 
	}
	return re->next;
}




















