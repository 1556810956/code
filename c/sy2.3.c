#include<stdio.h>
#include<stdlib.h>
struct node	
{
	int coe,num;
	struct node *next;
};

void add(struct node *ptr,struct node *qpt);
int main(void)
{
	int num1,num2,i;
	char ch1;
	struct node *head[2],*fpt,*mpt,*ptr;
	head[0]=(struct node*)malloc(sizeof(struct node));
	head[1]=(struct node*)malloc(sizeof(struct node));
	fpt=head[0];
	mpt=head[1];// 输入第一个多项式系数
//	void add(struct node *ptr,struct node *qpt);
	for(i=0;i<2;i++)
	{	
		while(1)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			scanf("%d %d",&num1,&num2);
			ch1=getchar();
			ptr->coe=num1;
			ptr->num=num2;
			head[i]->next=ptr;
			ptr->next=NULL;
			head[i]=ptr;
			if(ch1==10)
				break;

		}
	//	printf("%d\n",1);	
	}	
	add(fpt,mpt);
//	free();
	return 0;
}
void add(struct node *ptr,struct node *qpt)
{	
	
	
	struct node *fpt1,*mpt1,*x,*mpt2;
	
	
	int num3,num4;
//	char ch2;
	mpt2=ptr;
	
	mpt1=ptr;
	fpt1=ptr;
	
	
	while(qpt->next!=NULL)
	{	
		
		fpt1=mpt1;
		num3=qpt->next->coe;
		num4=qpt->next->num;
		qpt=qpt->next;
		while(fpt1->next!=NULL)
		{
			if((fpt1->next->num)==num4)
			{
				
				fpt1->next->coe=fpt1->next->coe+num3;

			
				break;
			}
			else if((fpt1->next->num)>num4)
			{
				
				
				x=(struct node*)malloc(sizeof(struct node));
				x->coe=num3;
				x->num=num4;
				x->next=fpt1->next;
				fpt1->next=x;

				break;
				

			}
		
		
			if(fpt1->next->next==NULL)
			{
                        	  x=(struct node*)malloc(sizeof(struct node));
				 x->coe=num3;
				 x->num=num4;
				 fpt1->next->next=x;
				 x->next=NULL;
				 break;

			}
			
			fpt1=fpt1->next;
		
		}
	}
	
	while(mpt2->next->next!=NULL)
	{
		if(mpt2->next->coe>0)
			printf("%dx^%d+",mpt2->next->coe,mpt2->next->num);
		if(mpt2->next->num<0)
		       	printf("%dx^%d",mpt2->next->coe,mpt2->next->num);
		mpt2=mpt2->next;
	}
	if(mpt2->next->coe>0)
		printf("%dx^%d",mpt2->next->coe,mpt2->next->num);
//	if(mpt2->next->coe)
// 		printf("%dx^%d",mpt2->next->coe,mpt2->next->num);
	printf("\n");

}	





