#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int x,y;
	int narr[20][20];
	char ch[20];
}graph;
typedef struct qnode
{
	int data;
	struct qnode *next;
}qnode,*queueptr;
typedef struct
{
	queueptr front;
	queueptr rear;
}linkqueue;

int vist[20];
int look[20];

linkqueue *initqueue()
{
	linkqueue *p;
	qnode *h;
	p=(linkqueue *)malloc(sizeof(linkqueue));
	h=(qnode *)malloc(sizeof(qnode));
	h->next=NULL;
	p->front=h;
	p->rear=h;
	return p;
}

int empty(linkqueue *p)
{
	if(p->front->next==NULL)
		return 1;
	else 
		return 0;

}

void enqueue(linkqueue *p,int n)
{
	qnode *r;
	r=(qnode *)malloc(sizeof(qnode));
	r->data=n;
	r->next=NULL;
	p->rear->next=r;
	p->rear=r;
}
int deque(linkqueue *p)
{
	int n;
	n=p->front->next->data;
	p->front->next=p->front->next->next;
	if(p->rear->next==NULL)
		p->rear=p->front;
	return n;
}
int locate(graph *g,char ch)
{
	int i;
	for(i=0;i<g->x;i++)
	{
		if(g->ch[i]==ch)
			return i;
	}
	return 0;
}
graph* creategraph()
{
	int i=0,j;
	char ch1,ch2,ch;
	graph *G;
	G=(graph *)malloc(sizeof(graph));
	printf("please input ding dian:\n");
	while(1)
	{
		G->ch[i]=getchar();
		if(G->ch[i]==10)
			break;
		i++;
	}
	G->x=i;
	G->y=i;
	printf("please input the message of bian :\n");
	while(1)
	{
		scanf("%c %c",&ch1,&ch2);
		ch=getchar();
		if(ch1=='#')
		{
			break;
		}
		i=locate(G,ch1);
		j=locate(G,ch2);
		G->narr[i][j]=1;
		G->narr[j][i]=1;
	}
	return G;

}
void output(graph *g)
{
	int m,n;
	for(m=0;m<g->x;m++)
	{
		for(n=0;n<g->y;n++)
			printf("%d ",g->narr[m][n]);
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	int j;
	vist[v]=1;
	printf("%d->",v+1);
	for(j=0;j<g->x;j++)
	{
		if(g->narr[v][j]==1 && vist[j]==0)
		{
			DFS(g,j);
		}
	}
	
}

void BFS(graph *g,int v)
{
	int j;
	linkqueue *p;
	p=initqueue();
	printf("%d->",v+1);
	for(j=0;j<g->x;j++)
		look[j]=0;
	look[v]=1;
	enqueue(p,v);
	while(!empty(p))
	{
		v=deque(p);
		for(j=0;j<g->x;j++)
		{
			if(g->narr[v][j]==1 && look[j]==0)
			{
				look[j]=1;
				enqueue(p,j);
				printf("%d->",j+1);
			}
		}
	}
	printf("\n");

}
int main(void)
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	g=creategraph();
	output(g);

	printf("the graph of depth search is :\n");
	DFS(g,0);
	printf("\n");
	
	printf("the broadth search is :\n");
	BFS(g,0);
	return 0;
}

