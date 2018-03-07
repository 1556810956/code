#include<stdio.h>	
#include<stdlib.h>
int main(void)
{
	int n,k;

	void bubble_sort(int *p,int n);
	int *p;
	printf("please input the number's count:\n");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	/* *f=*p;*/
//	printf("%x",p);
	printf("please input again:\n");
	for(k=0;k<n;k++)
	{
		scanf("%d",&p[k]);
	
	}
	
	bubble_sort(p,n);
	free(p);
	return 0;
}
void bubble_sort(int *p,int n)
{
	int i,j,change,ntemp;
	change=n;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(change-1);j++)
		{
			if(p[j]>p[j+1])
			{
				ntemp=p[j];
				p[j]=p[j+1];
				p[j+1]=ntemp;
			}
		}
		change--;
	}
	for(i=0;i<n;i++)
	{
		printf("the number's order is %d\n",p[i]);
	}
	return ;

}
