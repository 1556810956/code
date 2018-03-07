#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}list;
list *createl()
{
	list *h;
	h=(list *)malloc(sizeof(list));
	h->next=NULL;
	return h;
}
void input(list *h)
{
	list *r;
	char ch;
	while(1)
	{
		r=(list *)malloc(sizeof(list));
		scanf("%d",&n);

		r->data=n;
	}
}
int main(void)
{
	return 0;
}
