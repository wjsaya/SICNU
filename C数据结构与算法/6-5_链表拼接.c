#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
//           printf("%d ", p->data);
             printf("%d:%d\n ",p, p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    /*
	printlist(list1);
    printlist(list2);
    */
	list1 = mergelists(list1, list2);
    printlist(list1);
	
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

/* 你的代码将被嵌在这里 */

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
	/*
	1,建新指针,初始化为空
	2,比较二个链表,其一为空则直接返回另一个非空 
	3,均非空,新指针指向二者中的第一个小值作为开始
	3,如果二者均非空则循环,比较,新指针中的next始终指向较小的那一个.
	4,比较完毕之后,二者其一为空,新指针直接指向非空的链表. 
	*/
	struct ListNode *l1=NULL, *l2=NULL, *l3=NULL, *rsp=l3;
	//l1, l2, l3供遍历,rsp为l3头指针,返回 
	l1 = list1;
	l2 = list2;
	
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	
	if(l1->data < l2->data)
	{
		l3 = l1;
		l1 = l1->next;
	}
	else
	{
		l3 = l2;
		l2 = l2->next;
	}
	rsp = l3;
	
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->data < l2->data)
		{
			l3->next = l1;
			l1 = l1->next;
		}
		else
		{
			l3->next = l2;
			l2 = l2->next;
		}
		l3 = l3->next;
	}
	
	if(l1 != NULL)
		l3->next = l1;
	if(l2 != NULL)
		l3->next = l2;
		
	return rsp;
}







