#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	PNODE Create_List(void);
	PNODE Create_List();
	return 0;
}

PNODE Create_List(void)  
{  
    int len;  //存放链表的长度  
    int i;   //循环变量  
    int val;//用来临时存放用户输入的结点的值  
    PNODE List;  
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//分配一个头节点  
    if(NULL==pHead)  
    {  
        printf("Memory allocation failure");  
        exit(-1);  
    }  
    else  
    {   PNODE pTail=pHead;  
        pHead->pNext=NULL;   
        printf("please input the length of list: ");  //需要一个指针始终指向链表的结尾  
        scanf("%d",&len);  
        for(i=0;i<len;i++)  
        {  
            PNODE p=(PNODE)malloc(sizeof(NODE));  
            if(NULL==p)  
            {  
                printf("Memory allocation failure");  
                exit(-1);  
            }  
            else  
            {     
                printf("please input the value of list: ");  
                scanf("%d",&val);  
                p->data=val;  
                pTail->pNext=p;  
                p->pNext=NULL;  
                pTail=p;  
            }  
  
        }  
  
  
    }  
    return pHead;  
  
}  

