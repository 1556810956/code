#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}tree;

tree *create()
{
	tree *h;
	char ch,ch1;
	printf("please input the value:\n");
	scanf("%c",&ch);
	ch1=getchar();
	h=(tree *)malloc(sizeof(tree));
	if(ch=='#')
		h=NULL;
	else
	{
		h->data=ch;
		h->lchild=create();
		h->rchild=create();
	}

	return h;

}
int paintf(tree *h)
{

	char ch;
	if(h==NULL)
		return 0;
	else 
	{
		ch=h->data;
//		printf("%c\n",ch);
		paintf(h->lchild);
//		printf("%c\n",ch);
		paintf(h->rchild);
		printf("%c\n",ch);
	}
	return 0;

}
int main(void)
{
	tree *h;
	h=create();
	paintf(h);
	return 0;
}
