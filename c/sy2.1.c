#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char ch1,ch2;
	float coe1[40][40],coe2[40][40],a[40];
	int i,m,j=0;
	printf("please input coefficient:\n");//input message
	while(ch1!=10)
	{

		scanf("%f",&coe1[j][j]);
	        ch1=getchar();
		j++;
	}

	printf("please input coefficient again:\n");
        while(ch2!=10)
	{

		scanf("%f",&coe2[i][i]);
	       	ch2=getchar();
		i++;
	}
	if(i<j)
	{
		for(;i<j;i++)
			coe2[i][i]=0;
		m=i;

	}
	else
	{
		for(;j<i;j++)
			coe1[j][j]=0;
		m=j;
	}
	m=m-1;
	while(m>=0)
	{
	
		a[m]=coe1[m][m]+coe2[m][m];
		printf("%f ",a[m]);
		m--;
	}
	printf("\n");
	return 0;


}
