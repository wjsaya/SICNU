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
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	struct ListNode *new,*resp=new;
	
	while((list1 != NULL) && (list1 != NULL))
	{
		new = (struct ListNode *)calloc(8, sizeof(struct ListNode));
		
		if((list1 == NULL) && (list2 != NULL))
		{
	//	printf("list1#,list1!\n");
			new->next = list2;
			list2 = list2->next;
			new = new->next;
		}
		
		if((list1 != NULL) && (list2 == NULL))
		{
	//	printf("list1!,list1#\n");
			new->next = list1;
			list1 = list1->next;
			new = new->next;
		}
		else
		{
			
			if(list1->data >= list2->data)
			{
		//		printf("list1\n");
				new->next = list2;
				list2 = list2->next;
				new = new->next;
			}
			else
			{
		//		printf("list2\n");
				new->next = list1;
				list1 = list1->next;
				new = new->next;
			}
		}
	}
	
	return resp->next;
				
}















