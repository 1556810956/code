#include<stdio.h>
#include<stdlib.h>
struct node	
{
	int coe,num;
	struct node *next;
};
int main(void)
{
	int num1,num2,num3,num4;
	char ch1,ch2;
	struct node *head,*ptr,*fpt,*mpt,*apt,*x;
	fpt=head;
	mpt=head;// 输入第一个多项式系数
	void add(struct node *ptr);
	while(1)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		scanf("%d %d",&num1,&num2);
		ch1=getchar();
		ptr->coe=num1;
		ptr->num=num2;
		head->next=ptr;
		ptr->next=NULL;
		head=ptr;
		if(ch1==10)
			break;
	}

	return 0;
}
void add(struct node *ptr)
{	
	
	mpt=ptr;
	char ch2;
	while(ch2!=10)
	{	
		fpt=mpt;
		
		scanf("%d",&num3,&num4);
		ch2=getchar();
		while(fpt!=NULL)
		{
			if(fpt->next->num==num4)
				fpt->coe=fpt->coe+num3;
			else if(fpt->num<num4)
			{
				x=(struct node*)malloc(sizeof(struct node));
				x->coe=num3;
				x->num=num4;
				x->next=fpt->next;
				fpt->next=x;

			}
			if(fpt->next==NULL)
			{	
				x=(struct node*)malloc(sizeof(struct node));
				x->coe=num3;
				x->num=num4;
				ptr->next=x;
				x->next=NULL;	
			}

			fpt=fpt->next;
		}
	}
}	





