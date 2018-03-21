#include<stdio.h>
#include<stdlib.h>


typedef struct linklist
{
	int num;
	struct linklist *next;	
}linknode, *linkstp;

linkstp head_insert (linkstp head, linkstp newnode)
{
	printf("头插\n");
	printf("%x --> %x\n", head, newnode);
	newnode->next = head;
	head = newnode;
	return head;
}

linkstp tail_insert (linkstp head, linkstp newnode)
{
	printf("尾插\n");
	if (head == NULL)
		head = newnode;
	else
	{
		linkstp temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		newnode->next = NULL;
		temp->next= newnode;
	}
	return head;
}

void show(linkstp head)
{
	//puts("showing...");
	linkstp temp = head;
	while(temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
}
int main(void)  
{
	int i =0;
	linkstp head = NULL;
	linkstp newnode = NULL;
	srand(time(NULL));	//随机数的种子 
	for(i=0; i<5; i++)
	{
		linkstp newnode = (linkstp)malloc(sizeof(linknode));
		newnode->num = rand()%100; 
		newnode->next = NULL; 
		//head = head_insert(head, newnode);
		head = tail_insert(head, newnode);
		show(head);
		getchar();
	}
	
    return 0;
}

