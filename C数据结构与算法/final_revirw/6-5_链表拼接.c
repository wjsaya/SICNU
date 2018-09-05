#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*����ʵ�֣�ϸ�ڲ���*/
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

/* ��Ĵ��뽫��Ƕ������ */

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
	/*
	1,����ָ��,��ʼ��Ϊ��
	2,�Ƚ϶�������,��һΪ����ֱ�ӷ�����һ���ǿ� 
	3,���ǿ�,��ָ��ָ������еĵ�һ��Сֵ��Ϊ��ʼ
	3,������߾��ǿ���ѭ��,�Ƚ�,��ָ���е�nextʼ��ָ���С����һ��.
	4,�Ƚ����֮��,������һΪ��,��ָ��ֱ��ָ��ǿյ�����. 
	*/
	struct ListNode *l1=NULL, *l2=NULL, *l3=NULL, *rsp=l3;
	//l1, l2, l3������,rspΪl3ͷָ��,���� 
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







