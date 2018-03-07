#include<stdio.h>
#include<stdlib.h>
typedef struct seat
{
	int x,y;
}st;
typedef struct qtype
{
	st sit;
	struct qtype *next;
}qty;

void push(qty *h,int m,int n);

void find(qty *h,int mazw[][10]);
int pass(qty *h,int mazw[][10]);
void went(qty *h,int mazw[][10]);
st pop(qty *h);
int main(void)
{
	int i,j;
	st m,n;
	qty *h,*h1;
	int mazw[10][10]={{1,1,1,1,1,1,1,1,1,1},{0,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},{1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},{1,1,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1}};
	int mazw2[10][10];
	h=(qty *)malloc(sizeof(qty));
	h1=(qty *)malloc(sizeof(qty));
	for(i=0;i<10;i++)
	{
		printf("      ");
		for(j=0;j<10;j++)
		{
			printf("%d ",mazw[i][j]);
			mazw2[i][j]=mazw[i][j];
		}
		printf("\n");
	}
	h1->sit.x=0;
	h1->sit.y=1;
	h1->next=NULL;
	h->next=h1;
	find(h,mazw);
	while(1)
	{	
		m=pop(h);
		
		printf("(%d,%d)->",m.x,m.y);
		if(h->next==NULL)
			break;
	
	}
	printf("\n");
	for(i=0;i<10;i++)
	{
	 	for(j=0;j<10;j++)
	 	{
			if(mazw[i][j]>-1)
				printf("%d  ",mazw[i][j]);
			else
				printf("%d ",mazw[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
void push(qty *h,int m,int n)
{
	qty *h1;
	h1=(qty *)malloc(sizeof(qty));
	h1->sit.x=m;
	h1->sit.y=n;
	h1->next=h->next;
	h->next=h1;
}
st pop(qty *h)
{
	st coor;
	coor=h->next->sit;
	h->next=h->next->next;
	return coor;
}
void went(qty *h,int mazw[][10])
{
	int  m2,n2;

	m2=h->next->sit.x;
	n2=h->next->sit.y;
	
	if(mazw[n2-1][m2]==0)
	{
		--n2;
		push(h,m2,n2);
		mazw[n2][m2]=-1;

	}
	else if(mazw[n2+1][m2]==0)
	{
		++n2;
		push(h,m2,n2);
		mazw[n2][m2]=-1;
		
	}
	else if(mazw[n2][m2+1]==0)
	{
		++m2;
		push(h,m2,n2);

		mazw[n2][m2]=-1;
		
	}
	else
	{
		m2--;
		
		push(h,m2,n2);

		mazw[n2][m2]=-1;
		
	}
}
int pass(qty *h,int mazw[][10])
{
	st j;
	int m2,n2;
	j=h->next->sit;
	m2=j.x;
	n2=j.y;
 	if(mazw[n2-1][m2]==0)
	{
		return 1;
	
	}
 	if(mazw[n2+1][m2]==0)
	{

		return 1;
		
	}
 	if(mazw[n2][m2+1]==0)
	{
		return 1;
	
	}
	if(mazw[n2][m2-1]==0)
	{
		return 1;
		
	}
	return 0;

}
void find(qty *h,int mazw[][10])
{
	int m,n;
	do
	{
		if(pass(h,mazw)==1)
			went(h,mazw);
		else 
		{
			m=h->next->sit.x; 
			n=h->next->sit.y;
			mazw[n][m]=1;
			pop(h);
		}
		m=h->next->sit.x;
		n=h->next->sit.y;
		if(m==9 ||m==0 || n==9 || m==0)
			break;

	}while(1);	

}
