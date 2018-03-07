#include<stdio.h>
#include<stdlib.h>
struct stackh
{
	char ch;
	struct stackh *next;
};
struct stack
{
	float n;
	struct stack *next;
};
int narr[7][7]={{1,1,-1,-1,-1,1,1},{1,1,-1,-1,-1,1,1},{1,1,1,1,-1,1,1},{1,1,1,1,-1,1,1},{-1,-1,-1,-1,-1,0,2},{1,1,1,1,2,1,1},{-1,-1,-1,-1,-1,2,0}};
void pushs(struct stack *top,float num);
float pops(struct stack *top);
char pop(struct stackh *top);
void push(struct stackh *top,char ch);
int precede(char ch2,char ch1);
char gettop(struct stackh *top);
float operate(float a,char thata,float b);
float change(char ch1);
void calcu(struct stackh *h1,struct stack *h2);
void dgish(char *narr,struct stackh *h1,struct stack *h2);
int main(void)
{
	
	
	struct stackh *h1,*p1;
	struct stack *h2,*p2;
	char ch1,ch2,theta,narr[100];
	float a,b;
	char *s;
	float m;
	int i=0;
	h1=(struct stackh *)malloc(sizeof(struct stackh));
	h2=(struct stack *)malloc(sizeof(struct stack));
	
	p1=(struct stackh *)malloc(sizeof(struct stackh));
	p2=(struct stack *)malloc(sizeof(struct stack));
	
	p1->ch='#';
	p1->next=NULL;
	h1->next=p1;
	
	p2->n=0;
	p2->next=NULL;
	h2->next=p2;
	
	gets(narr);
	dgish(narr,h1,h2);
	calcu(h1,h2);
	
	
	while(h1->next!=NULL)
	{
		printf("%c",pop(h1));
            
	}
	printf("%f\n",pops(h2));
	free(h1);
	free(h2);
	
	return 0;
}
float rembra(char *bra,struct stackh *h1,struct stack *h2)
{
	float m;
	dgish(bra,h1,h2);
	calcu(h1,h2);
	m=pops(h2);
	return m;
}
void dgish(char *narr,struct stackh *h1,struct stack *h2)
{
	
	struct stackh *h3,*p3;
	struct stack *h4,*p4;
	char ch1,ch[10],ch3,theta,kuo[20];
	char *s;
	int i=0,j=0,n,m;
	float a,b;
	ch1=' ';
	h4=(struct stack *)malloc(sizeof(struct stack));
	h3=(struct stackh *)malloc(sizeof(struct stackh));
	p4=(struct stack *)malloc(sizeof(struct stack));
	p3=(struct stackh *)malloc(sizeof(struct stackh));
	p3->ch='#';
	p3->next=NULL;
	h3->next=p3;
	p4->n=0;
	p4->next=NULL;
	h4->next=p4;
	while(1)  
	{
		ch1=narr[i];
		if(ch1=='\0')
			break;
		if(ch1=='-' && (narr[i-1]>57 || narr[i-1]<48))
		{
			i++;
			s=&ch1;
			a=atof(s);
			pushs(h2,-1*a);
		}
		else if(ch1<=57 && ch1>=48)
		{
			if(narr[i+1]<=57 && narr[i+1]>=48)
			{
				n=i;
				while(narr[i]<=57 && narr[i]>=48)
				{
					ch[j]=narr[i];
					j++;
					i++;
					a=atof(ch);
					
					pushs(h2,a);
				}
				i--;
			}
			else
			{
				s=&ch1;
				a=atof(s);
				pushs(h2,a);
			}
		}
		else if(ch1=='(')
		{
			for(m=0;;m++)
			{
				i++;
				
				kuo[m]=narr[i];
				if(narr[i+1]==')')
				{
					i++;
					kuo[m+1]='#';
					break;
				}
			}
			pushs(h2,rembra(kuo,h3,h4));

		}
		else
		{
			switch(precede(ch1,gettop(h1)))
			{
				case -1:theta=pop(h1);a=pops(h2);b=pops(h2);pushs(h2,operate(a,theta,b));push(h1,ch1);break;
				case 1:push(h1,ch1);break;
			}
		}
		i++;
	}
}
void calcu(struct stackh *h1,struct stack *h2)
{
	int m;
	float a,b;
	char theta;
	while(h1->next->next->ch!='#')
	{
		switch(precede(gettop(h1),gettop(h1->next)))
		{
			if(gettop(h1->next->next)=='-')
			{
				h1->next->next->next->ch='+';
				m=h2->next->next->next->n;
				h2->next->next->next->n=-1*m;
			}
			case -1:theta=pop(h1->next);a=pops(h2);b=pops(h2);pushs(h2,operate(a,theta,b));break;
			case 1:break;
		}
	}
}    

void pushs(struct stack *top,float num)
{
	struct stack *p;
	p=(struct stack *)malloc(sizeof(struct stack));
	p->n=num;
	p->next=top->next;
	top->next=p;
}
float pops(struct stack *top)
{
	float n4;
	n4=top->next->n;
	top->next=top->next->next;
	return n4;
}
float gettops(struct stack *top)
{
	float n5;
	n5=top->next->n;
	return n5;
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
int precede(char ch2,char ch1)
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
	return 0;
}
float change(char ch1)
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
	return 0;
}
float operate(float a,char theta,float b)
{
	float a1,b1;
	/* char *s1,*s2;     */
	/*	s1=&a;           */
	/*	s2=&b;          */
	/*	a1=atof(s1);    */
	/*	b1=atof(s2);    */
	a1=a;
	b1=b;
	if(theta=='+')
	{  
	   //	printf("%f\n",a1+b1);
		return (a1+b1);

	}
	if(theta=='-')
	{
//		printf("%f\n",b1-a1);
		return (b1-a1);
	}
	if(theta=='/')
	{
	//	printf("%f\n",b1/a1);
		return (b1/a1);
	}
	if(theta=='*')
	{
	 //	printf("%f\n",a1*b1);
		return (a1*b1);


	}
	else
		printf("error\n");
	return 0;
}

