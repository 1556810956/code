#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char *ch;
	int len;
}string;
string *input()
{
	int i,j;
	char ch1[100];
	string *str;
	str=(string *)malloc(sizeof(string));
	for(i=0;;i++)
	{
		ch1[i]=getchar();
		if(ch1[i]==10)
			break;
	}
	str->ch=(char *)malloc(i*sizeof(char));
	for(j=0;j<=i;j++)
	{
		str->ch[j]=ch1[j];
	}
	str->len=i;
	return str;
}
void copy(string *s1,string *s2)
{
	int length,i,j=0;
	string *s3;
	length=s1->len+s2->len-1;
	s3=(string *)malloc(sizeof(string));
	s3->ch=(char *)malloc(length*sizeof(char));
	for(i=0;;i++)
	{
		if(s1->ch[i]==10)
			break;
		s3->ch[i]=s1->ch[i];

	}
	i--;
	for(;;i++)
	{
		s3->ch[i]=s2->ch[j];
		if(s3->ch[i]==10)
			break;
		j++;

	}
	i=0;
	printf("the string of copy is :\n");
	while(s3->ch[i]!=10)
	{
		printf("%c",s3->ch[i]);
		i++;
	}
	printf("\n");

}
int substring(string *s,char ch,int len)
{
	string *s1;
	int i,length,j=0,m=0;
	s1=(string *)malloc(sizeof(string));
	length=s->len;
	s1->ch=(char *)malloc((len+1)*sizeof(char));
	for(i=0;i<length;i++)
	{
		if(ch==s->ch[i])
			j++;
		if(j==1)
		{
			m++;
		}
		
	}
	if(m<len || j!=1)
	{
		printf("errr\n");
		return 0;
	}
	for(i=0;i<length;i++)
	{
		if(s->ch[i]==ch)
		{
			j=i;
			for(;i<j+len;i++)
			{
				s1->ch[i]=s->ch[i];
			}
			break;
		}

	}
	if(s1->ch[i]!=10)
		s1->ch[i+1]='\n';
	i=0;
	printf("the string of substring is :\n");
	while(s1->ch[i]!=10)
	{
		printf("%c",s1->ch[i]);
		i++;
	}
	printf("\n");
	return 0;

}
void insert(string *s,string *s2,int len)
{
	string *s1;
	int i,length,m=0;
	length=s2->len;
	s1=(string *)malloc(sizeof(string));
	length=length+s->len-1;
	s1->ch=(char *)malloc(length*sizeof(char));
	for(i=0;i<len;i++)
	{
		s1->ch[i]=s->ch[i];
	}
	for(;;i++)
	{
		if(s2->ch[m]==10)
			break;
		s1->ch[i]=s2->ch[m];
		m++;
	}
	for(;;i++)
	{
		s1->ch[i]=s->ch[m];
		if(s1->ch[i]==10)
			break;
		m++;
	}
	i=0;
	printf("the string of insert is :\n");
	while(s1->ch[i]!=10)
	{
		printf("%c",s1->ch[i]);
		i++;
	}
	printf("\n");
}
int main(void)
{
	int len;
	char ch;
	string *r1,*r2,*r3;
	printf("please input string onece:\n");
	r1=input();
	printf("please input string that you want to copy:\n");
	r2=input();
	copy(r1,r2);
	printf("the the string you want to put out :\n");
	scanf("%d %c",&len,&ch);
	substring(r1,ch,len);
	printf("please input the string you want to insert :\n");
	ch=getchar();
	r3=input();
	printf("please input the number you want to insert :\n");
	scanf("%d",&len);
	insert(r1,r3,len);	

	return 0;
}
