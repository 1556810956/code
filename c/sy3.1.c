#include<stdio.h>
#include<stdlib.h>
struct stackh
{
	int data;
	struct stackh *next;
};
void push(struct stackh *h,int n);

int pop(struct stackh *h);

void initstack(struct stackh *h);

void gettop(struct stackh *h);

int main(void) 
{
	struct stackh *h;
	h=(struct stackh *)malloc(sizeof(struct stackh));
        initstack(h);
        pop(h);
        push(h,100);
       
	while(h->next!=NULL)
	{
	
		gettop(h);
		h=h->next;
	}
	printf("\n");
	return 0;
}

void initstack(struct stackh *h)
{
	int n,i=1;
	char ch;

	struct stackh *b,*t,*s;
	while(ch!=10)
	{
		if(i==1)
		{
			scanf("%d",&n);
			ch=getchar();
			s=(struct stackh *)malloc(sizeof(struct stackh));
			s->data=n;
			s->next=NULL;
			h->next=s;
			t=s;
			b=s;
		}
		else
		{
			scanf("%d",&n);
			ch=getchar();
			s=(struct stackh *)malloc(sizeof(struct stackh));
			s->data=n;
			h->next=s;
			s->next=t; 
			t=s;
	
		}
		i++;
	}
	

}

void push(struct stackh *h,int n)
{
	struct stackh *p;
	p=(struct stackh *)malloc(sizeof(struct stackh));
	p->data=n;
	p->next=h->next;
	h->next=p;
}

int pop(struct stackh *h)
{

	int n; 
	n=h->next->data;
	h->next=h->next->next;
	return n;
}
void gettop(struct stackh *h)
{
	int k;
	k=h->next->data;
	printf("%d ",k);
}
