#include<stdio.h>
#include<stdlib.h>
struct chain
{
	int value;
	struct chain *next;
};
struct chain *create()
{
	struct chain *head,*tail,*p;
	int x;
	head=tail=NULL;
	while(scanf("%d",&x)==1)
	{
		p=(struct chain*)malloc(sizeof(struct chain));
		p->value=x;
		p->next=NULL;
		if(head==NULL)
		{
			head=tail;
			head=p;
		}
		else
			tail=tail->next=p;
	}
	return head;
}
struct chain *dellink(struct chain *head,int a)
{
	struct chain *q,*p;
	if(head==NULL)
		printf(“can not find chain\n”);
	else if(head->value==a)
		{
			p=head;
			head=head->next;
		
		}
	else
	{
		p=head;
		while((p->value!=a&&(p->next!=NULL)))
		{
			q=p;
			p=p->next;
		}
		if(p->value!=a)
			printf(“the chain is not\n”);

		else
		{
			q->next=p->next;
			free(p);
		}
	
	}	
	return head;
}
int main(void)
{
	struct chain *p,*q;
	q=create();/* create chain */
	while(q)
	{
		printf("%d\n",q->value);
		p=q->next;
		free(p);
		q=p;
	}
	return 0;
}

