#include<stdio.h>
#include<stdlib.h>
int main(void)
{
      int n;		
      void maN(int n);
      printf("please input the number's count:\n");
      scanf("%d",&n);
      if(n<0)
	      printf("your input number is eorr!\n");
      else
              maN(n);
      return 0;
}


void maN(int n) 
{
      int i,j,max,min;
      int *p;
      p=(int*)malloc(n*sizeof(int));
      printf("please input the number:\n");
      for(i=0;i<n;i++)
      {
		scanf("%d",&p[i]);

      } 
      max=p[0];
      for(j=0;j<(n-1);j++)
      {
            if(max<p[j+1])
            {
                  max=p[j+1];
            }
      }
      
      min=p[0];
      for(j=1;j<(n-1);j++)
      {
            if(min>p[j+1])
            {
                  min=p[j+1];
            }
      }
      printf("the min number is %d\n the max number number is %d\n",min,max);
      free(p);
      return ;
}
     


