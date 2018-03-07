#include<stdio.h>
#include<stdlib.h>
struct node
	
{
	int date;
	struct node *next;
};
int main(void)
{
	int m;
	struct node *p,*head,*q,*t;
	head=NULL;
	do
	{
		scanf("%d",&m);
		p = (struct node *)malloc(sizeof(struct node));
		p -> date=m;
		p -> next = NULL;
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;
	}while(getchar() != 10);
	t=head;
	
	while(t!=NULL)
	{
		t=t->next;
	}
	while(t!=NULL)
	{
		printf("%d ",t->date);
		t =t->next;
	}
	printf("\n");
	free(p);
	return 0;
	
		
}

