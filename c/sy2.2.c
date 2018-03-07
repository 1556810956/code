#include <stdio.h>
#include <stdlib.h>
struct node	
{
    int data;
    struct node* next;
};
typedef struct node* ptr;
int main()
{
    int n;
    char ch1,ch2;
    ptr head=(ptr)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    ptr temp,con;
    temp=head;
    con=head;
    while(ch1!=10)
    {
	scanf("%d",&n);
	ch1=getchar();
        ptr t=(ptr)malloc(sizeof(struct node));
        head->next=t;
        t->data=n;
        t->next=NULL;
        head=head->next;

    }
    while(ch2!=10)
    {
	scanf("%d",&n);
	ch2=getchar();
        while(temp->next!=NULL)
	{
              if(temp->next->data>=n)
	      {
             	 ptr tmp=(ptr)malloc(sizeof(struct node));
              	tmp->next=temp->next;
              	tmp->data=n;
              	temp->next=tmp;
		printf("%d\n",1);
              	break;
             }
              else 
		     temp=temp->next;
      }
      if(temp->next==NULL)
      {
    	ptr x=(ptr)malloc(sizeof(struct node));

    	x->data=n;
    	x->next=NULL;
    	temp->next=x;
      }
   } 
       if(con->next==NULL)
	   printf("NULL");
       else
       {

            con=con->next;
	    while(con->next!=NULL)
	    {


    		printf("%d ",con->data);
		con=con->next;
	   }
	   printf("%d",con->data);
      }
      printf("\n");
	
      return 0;
}

