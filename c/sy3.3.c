#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int i,j,narr[20][20]; 
	printf("Ten random numbers from 0 to 99\n\n"); 
　　	for(i=0; i<20; i++)
	{
		for(j=0;j<20;j++)
			narr[i][j]=(rand()%2);
	}
	for(i=0;i<20;i++)
	{
		printf("      ");
		for(j=0;j<20;j++)
			printf("%d ",narr[i][j]);
		printf("\n");
	}
　　	return 0; 
}

