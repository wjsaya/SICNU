
#include<stdlib.h>
#include<stdio.h>

//定义linklist结构体类型
typedef struct linklist
{
    int data;
    struct linklist *next;
}list,*plist;//建立一个结构体list及linklist结构体类型指针

//尾插法建链表
void tail_insert(plist *head, int num)/**/
{
    plist p_new = (plist)malloc(sizeof(list));
    p_new->data = num;          /*新元素data设为num*/
    p_new->next = NULL;         /*将新元素next置为空*/
    plist temp = *head;         /*定义一个临时指针变量指向表头*/
    if (NULL == *head)          /*head为空则赋予p_new为第一个新结点*/
    {
        *head = p_new;
        p_new->next = NULL;
    }
    else                            /*若非空*/
    {
        while (temp->next != NULL)  /*最终让temp指向尾结点*/
        {
            temp = temp->next;
        }
        temp->next = p_new;     /*将尾结点temp的next设为p_new,即将p_new设为尾结点*/

    }
}

/*打印输出链表*/
void print_list(plist head)
{
    plist elem = head;
    while (elem!=NULL)
    {
        printf("%d ",elem->data);
        elem = elem->next;
    }
    printf("\n");
}

void main()
{
    int number;
    plist head;
    head = NULL;//初始化表头为空

    printf("input some numbers:\n");
    scanf("%d",&number);
    while (number != -1)//输入-1终止输入循环
    {
        tail_insert(&head, number);
        scanf("%d", &number);
    }

    printf("打印输出链表:\n");
    print_list(head);

}
