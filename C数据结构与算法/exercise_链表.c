#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#defile TSIZE 45;

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
    };

int main(void)  {
    struct film * head = NULL:
    struct film * prev, * current;
    char input[TSIZE];
    puts("输入影片title:");
    while(gets(input) != NULL && input[0] != '\0')  {
        current = (struct film *) malloc (sizeof (struct film));

        if (head == NULL)
            head = current;
        else
            prev->next = current;
        
        current->next = NULL;
        strcpy(current->title, input);

        puts("输入分数<0-10>:");
        scanf("%d", &current->rating);

        while(getchar() != '\n')
            continue;
    
        puts("输入下一个影片名（直接回车停止）：");
        prev = current;
    }
    
    if (head == NULL)
        printf("no data");
    else
        printf("list:\n");

    current = head;

    while(current != NULL)  {
        printf("movie:%s,ating:%d\n", current->title, current->rating);
        current = current->next;
        }
    
    current = head;
    while(current != NULL)  {
        free(current);
        current = current->next;
        }
    printf("Bye;\n");


    return 0;
}

