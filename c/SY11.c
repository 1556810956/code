#include<stdio.h>
#include<stdlib.h>
int search(int a[],int len, int x)
 {
      int i;
      for (i=0; i<len; i++)
      {
           if(x==a[i])   
           return i;  
      }
	return -1;  
}
 
int main(void)
{
    int *arr;
    int n;
	int i,m,j;
	printf("please input number's count:\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
		scanf("%d",&arr[j]);
	printf("please input the number you want to find :\n");
	scanf("%d",&m);
    i= search(arr, n, m);
    if(i!=-1)
         printf("the num %d is at %d\n",n,i+1);
     else
        printf("have no number:%d\n",n);
   return 0;
}
