#include<stdio.h>
#include<stdlib.h>
typedef struct coe
{
	int x,y;
	int num;
	struct coe *next;
}three;
void input(three *h)
{
	int x,y;
	int arr;
	char ch;
	three *h1,*h2;
	h1=h;

	while(1)
	{
		h2=(three *)malloc(sizeof(three));
		printf("input row\n");
		scanf("%d",&x);
		printf("input column\n");
		scanf("%d",&y);
		printf("input num\n");
		scanf("%d",&arr);
		h2->x=x;
		h2->y=y;
		h2->num=arr;
		h1->next=h2;
		h1=h2;
		h2->next=NULL;
		ch=getchar();

		if(ch==' ')
			break;

	}
}
void paitf(three *h,int m,int n)
{
	int i,j;
	
	
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(h->next!=NULL && h->next->x==i && h->next->y==j)
				{
					printf("%d ",h->next->num);
					h=h->next;
				}
				else
					printf("0 ");
			}
			printf("\n");
		}
	
}
int main(void)
{
	int i,j;
	three *h,*h2;
	
	h=(three *)malloc(sizeof(three));
	h2=(three *)malloc(sizeof(three));
	h2->x=1;
	h2->y=1;
	h2->num=2;
	h->next=h2;
	h2->next=NULL;
	printf("please input toal row and column\n");
	scanf("%d %d",&i,&j);
	input(h);
	paitf(h,i,j);
	return 0;
}
