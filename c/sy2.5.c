#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}list;
list *input()
{
	int n;
	char ch;
	list *h1,*h2,*h;
	h2=(list *)malloc(sizeof(list));
	h=h2;
	
	while(1)
	{
		scanf("%d",&n);
		ch=getchar();
		
		h1=(list *)malloc(sizeof(list));
		h1->data=n;
		h2->next=h1;
		h2=h1;
		h1->next=NULL;
		if(ch==10)
			break;
	}
	
	return h;
}
void output(list *h)
{
	while(h->next!=NULL)
	{
		printf("%d ",h->next->data);
		h=h->next;
	//	free(h);
	}
	printf("\n");
	
}
list *combine(list *h,list *h2)
{
	list *k,*m;
	k=h;

	while(h2->next!=NULL)
	{
		h=k;
		while(h->next!=NULL)
		{
			if(h->next->data>=h2->next->data)
			{
				m=(list *)malloc(sizeof(list));
				m->data=h2->next->data;
				m->next=h->next;	
				h->next=m;
				break;
			}
			h=h->next;
			if(h->next==NULL)
			{
				m=(list *)malloc(sizeof(list));
				m->data=h2->next->data;
				h->next=m;
				m->next=NULL;
				break;
			}
			
		}
		h2=h2->next;
	}
	return k;
}
list *jiao(list *h,list *h1)
{
	list *h2,*h3,*h4,*h5;
	h2=(list *)malloc(sizeof(list));
	h3=h1;
	h4=h2;
	while(h->next!=NULL)
	{
		h1=h3;
		while(h1->next!=NULL)
		{
			if((h1->next->data)==(h->next->data))
			{
     				h5=(list *)malloc(sizeof(list));
				h5->data=h1->next->data;
				h4->next=h5;
				h4=h5;
				h5->next=NULL;	
	//			printf("%d\n",h5->data);
				break;
			}	

			h1=h1->next;
		}

		h=h->next;
	}
//	while(h2->next!=NULL)
//	{
//		
//		printf("%d ",h2->next->data);
//		h2=h2->next;
//	}
//	printf("\n");
	return h2;
}
list *bu(list *h,list *h1)
{
	list *h2,*h3,*h4,*h5,*h22;
	list *H,*H1;
	H=h;
	H1=h1;
	h2=jiao(h,h1);
	h=H;
	h1=H1;
	h22=h2;
	h3=(list *)malloc(sizeof(list));
	h4=h3;
	while(h->next!=NULL)
	{
		h2=h22;
		while(h2->next!=NULL)
		{

			if((h->next->data)==(h2->next->data))
			{
				break;
			}
			
			if(h2->next->next==NULL)
			{
				
				
				h5=(list *)malloc(sizeof(list));
				h5->data=h->next->data;
				h4->next=h5;
				h4=h5;
				h5->next=NULL;
						
		        }
			h2=h2->next;
		}
		h=h->next;

	}

	while(h1->next!=NULL)
	{
		h2=h22;
		while(h2->next!=NULL)
		{
			
			if((h1->next->data)==(h2->next->data))
			{
				break;
			}
			if(h2->next->next==NULL)
			{
				h5=(list *)malloc(sizeof(list));
		         	h5->data=h1->next->data;
				h4->next=h5;
				h4=h5;
				h5->next=NULL;		
		        }
			h2=h2->next;
		}
		h1=h1->next;

	}
//	while(h3->next!=NULL)
//	{
//		printf("%d ",h3->next->data);
//		h3=h3->next;
//	}
//	printf("\n");
	return h3;
}
list *bing(list *h,list *h1)
{
	list *h2,*h3,*h4;
	h2=(list *)malloc(sizeof(list));
	h3=h2;
	while(h->next!=NULL)
	{
		h4=(list *)malloc(sizeof(list));
		h4->data=h->next->data;
		h3->next=h4;
		h3=h4;
		h4->next=NULL;
		h=h->next;
	}
	h4->next=h1->next;
	return h2;
}
int main(void)
{
	list *H1,*H2,*H3,*H4,*H5,*H6;
	list *h1,*h2;
	h1=input();
	h2=input();
	H1=h1;
	H2=h2;
	H3=bing(H1,H2);
	printf("the result of bing is:\n");
	output(H3);

	H1=h1;
	H2=h2;
	H4=bu(H1,H2);
	printf("the result of bu is:\n");
	output(H4);

	H1=h1;
	H2=h2;
	H5=jiao(H1,H2);
	printf("the result of jiao is :\n");
	output(H5);

	H1=h1;
	H2=h2;
	H6=combine(H1,H2);
	printf("the result of combine is:\n");
	output(H6);


	return 0;
}	
