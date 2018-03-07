#include<stdio.h>
#include<stdlib.h>
struct stackh
{
	char ch;
	struct stackh *next;
};
int narr[7][7]={
{1,1,-1,-1,-1,1,1},{1,1,-1,-1,-1,1,1},{1,1,1,1,-1,1,1},{1,1,1,1,-1,1,1},{-1,-1,-1,-1,-1,0,2},{1,1,1,1,2,1,1},{-1,-1,-1,-1,-1,2,0}};
void push(struct stackh *top,char ch3);

char pop(struct stackh *top);
int precede(char ch2,char ch1);
char gettop(struct stackh *top);
int operate(char a,char thata,char b);
int change(char ch1);
int main(void)
{
	struct stackh *h1,*h2,*top,*p;
	char ch1,ch2,theta;
	int a,b;
	h1=(struct stackh *)malloc(sizeof(struct stackh));
	h2=(struct stackh *)malloc(sizeof(struct stackh));
//	top=(struct stackh *)malloc(sizeof(struct stackh));

	p=(struct stackh *)malloc(sizeof(struct stackh));
	p->ch='#';
	p->next=NULL;
	h1->next=p;
	p->ch='#';
	
	h2->next=p;
	while(1)
	{
		scanf("%c",&ch1);
		if(ch1==10)
			break;
		if(ch1<=57 && ch1>=48)
			push(h2,ch1);//数字
		else
			switch(precede(gettop(h1),ch1))
				case 0:break;
				case 1:theta=pop(h1);a=pop(h2);b=pop(h2);push(h2,operate(a,theta,b));break;//运算
 				case -1:push(h1,ch1);break;
	}
//	while(1)
//	{
//		if(h1->next==NULL)
//			break;
//		printf("%c",pop(h1));
//		printf("\n");
//	}
	
}

void push(struct stackh *top,char ch3)
{
	struct stackh *p;
	p=(struct stackh *)malloc(sizeof(struct stackh));
	p->ch=ch3;
	p->next=top->next;
	top->next=p;
	
	
	
}

char pop(struct stackh *top)
{

	char ch4; 
	ch4=top->next->ch;
	top->next=top->next->next;
	
	return ch4;
}
char gettop(struct stackh *top)
{
	char ch5;
	ch5=top->next->ch;
	return ch5;

}
int precede(char ch2,char ch1)//比较
{
	int b,g;
	int we[3]={-1,0,1};
	b=change(ch2);
	g=change(ch1);
	if(narr[b][g]==0)
		return we[1];
	if(narr[b][g]==-1)
		return we[0];
	if(narr[b][g]==1)
		return we[2];

}
int change(char ch1)
{
	int a[7],i;
	for(i=0;i<7;i++)
	{
		a[i]=i;
	}
	if(ch1=='+')
		return a[0];
	if(ch1=='-')
		return a[1];
	if(ch1=='*')
		return a[2];
	if(ch1=='/')
		return a[3];
	if(ch1=='(')
		return a[4];
	if(ch1==')')
		return a[5];
	if(ch1=='#')
		return a[6];
	
}
int operate(char a,char theta,char b)
{
	int a1,b1;
	a1=atof(a);
	b1=atof(b);
	if(theta=='+')
		return (a1+b1);
	if(theta=='-')
		return (a1-b1);
	if(theta=='/')
		return (a1/b1);
	if(theta=='*')
		return (a1*b1);

}
