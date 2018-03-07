#include <stdio.h>  
#include <stdlib.h>  
struct node{  
   int num;  
   char name[20];  
  
   struct node* next;  //指向下一个地址的指针  
};  //声明一个链表,此时内存不分配内存  
  
typedef struct node Node; //重命名,便于书写,太长了struct node   
typedef struct node* Link;  
//构造函数,实现传过来的头指针指向一个空的内容  
void creat_node(Link *head); 
   
void insert_head(Link *head,Link p);  
 
void insert_tail(Link *head,Link p)  
{  
    Link a;  
    a = *head;  
  
    if( *head == NULL )  
    {  
        *head = p;  
        p->next = NULL;  
    }  
    else  
    {  
        //*head->next = p;  
        while(a->next!= NULL)  
        {  
            a=a->next;  
        }  
        a->next=p;  
        p->next=NULL;  
    }  
  
}  
  
 
void release_node(Link head)  
{  
    Link p;    
    p = head;  
  
    while(p != NULL)  {  
        free(p);   
        p = p -> next;    
    }  
}  
  
 
void display_node(Link head)   
{  
    Link a;   
    a = head;  
  
    while(a != NULL)   
    {  
        printf("num = %d name = %s\n",a -> num,a -> name);  
        a = a -> next;  
    }  
}  
  
 
int length_node(Link head)    
{  
    Link p;  
    int i = 0; //记录节点个数  
    p = head;  
  
    while(p != NULL)  //直到p指向的空间是NULL  
    {  
        i++;    //i+1技术  
                p = p -> next;  //p指向下一个节点  
    }  
  
    return i; //返回值i是int的,要声明函数的返回值  
}  
  
//查找链表中指定节点的内容  
void check_node(Link head,int k)  //对链表的操作,不需要移动head的位置,形参取head的一级指针,k为指定节点数  
{  
        Link p;  
    p = head;  
  
    if(p == NULL)  
        printf("链表为空,无内容可查\n");  
    else  
    {  
        while(p != NULL)  //找到链表中的指定节点打印出来  
        {  
            if(p -> num == k)  
            {  
                printf("name = %s\n",p -> name);  
                break; //打印完成后要记得退出循环  
            }  
            else  
                p = p -> next; //p指向p的后一位字节  
        }   
    }  
}  
  
//删除指定节点  
void delete_node(Link head,int x)  //对链表的操作,不需要移动head的位置,形参取head的一级指针,k为指定节点数  
{  
    Link p,q;  
    p = head;  
  
    if(head == NULL)  
    {  
        printf("链表为空\n");  
        return ;  
    }  
  
    if(head -> next == NULL)  //链表中只有一个节点  
    {  
        if(p -> num == x)  
          {  
              free(p);  
              p = NULL;  
              return;  
          }  
        else  
        {  
            printf("没有该节点\n");  
            return;  
        }  
    }  
  
    while(p -> num != x) //找到指定节点删除  
    {  
        q = p; //记录当前p指向的位置,p满足循环条件时,q指向p的前一个节点地址  
        p = p -> next;  
    }  
  
    q -> next = p -> next;   
    p -> next = NULL;     //断开p指向的字节在连边中的连接顺序  
    free(p);    //释放空间  
  
}  
  
  
void add_node(Link *head,Link m,int y) //需要讨论head的指向,取二级指针,新节点的指针,插入节点的位置  
{  
    Link p,q;  
    p = *head;  
  
        while(p -> num != (y - 1)) //指针p停在要插入位置的前一个节点  
        {  
          
            p = p -> next;   
        }  
  
        q = p -> next;  
    p -> next = m;  
        m -> next = q;  
  
    m -> num = y;  //完成指针的指向操作  
}  
//指针num变量重赋值,  
void replay_num(Link head)  
{  
    Link p;  
    p = head;  
    int i = 0;  
  
    while(p != NULL)  
    {  
        p -> num = i + 1;  
        p = p -> next;  
        i++;  
    }  
  
}  
   
//主函数  
int main( )  
{  
    Link head = NULL;//head指向NULL 防止野指针  
    Link p = NULL; //定义一个指针P指向NULL,防止野指针  
    int k,x,y = 0,i = 0;  
    Link m = NULL; //防止野指针  
  
  //  creat_node(&head); //head指向一个空  
  
        printf("请输入姓名:\n");  
    for(i = 0;i < 3;i++)  
    {  
                p = (Link)malloc(sizeof(Node)); //malloc()函数分配Node大小的空间,类型转换为Link型,指赋给p  
          
        if(p == NULL)//空间分配失败  
        {  
            printf("malloc error!\n");  
            exit(-1);  //结束进程 文件包含stdlib.h  
        }  
  
        p -> num = i + 1;  
        scanf("%s",p -> name);  
  
      //  insert_head(&head,p);  
        insert_tail(&head,p); //尾插  
    }  
  
    display_node(head);  
  
        printf("链表长度:%d\n",length_node(head));  
  
    printf("请输入想要查询的节点:\n");  
    scanf("%d",&k);  
    check_node(head,k);  
  
    printf("请输入想要删除的节点:\n");  
    scanf("%d",&x);  
        delete_node(head,x);  
  
    display_node(head);   
  
    m = (Link)malloc(sizeof(Node)); //m指向一个新分配的空间  
        printf("请输入想要插入的节点内容:\n");  
    scanf("%s",m -> name);  
    printf("请输入想要插入的节点位置:\n");  
    scanf("%d",&y);  
    add_node(&head,m,y);  
  
    replay_num(head); //调用add_node()函数后把num的内容重新排序  
  
        display_node(head);  
  
  
    release_node(head); //释放函数要放在最后 所有操作结束后释放空间  
    return 0;  
}  
