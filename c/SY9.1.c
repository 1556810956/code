#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
}list;
list *input(int n)
{
	list *r;
	int i=0;
	r=(list *)malloc(n*sizeof(list));
	for(i=0;i<n;i++)
	{
		scanf("%d",&r[i].data);
	}
	return r;
}
void xuanzhe(list *h,int n)
{
	int i,j=0,min,t;
	while(j<=n-1)
	{
		min=h[j].data;
		for(i=j;i<n;i++)
		{
			if(min>h[i].data)
			{
				min=h[i].data;
			}
		}
		for(i=j;i<n;i++)
		{
			if(h[i].data==min)
				break;
		}
		t=h[i].data;
		h[i].data=h[j].data;
		h[j].data=t;
		j++;
	}
}
void output(list *h,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",h[i].data);
	}
}
int main(void)
{
	list *r;
	int n;
	printf("please input the number of count :\n");
	scanf("%d",&n);
	r=input(n);
	xuanzhe(r,n);
	output(r,n);
	printf("\n");
	return 0;
}
