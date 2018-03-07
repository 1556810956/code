#include<stdio.h>
void pp(int a[1][1])
{
	a[0][0]=23;
}
int main(void)
{
	int a[1][1]={{1}};
	int i,j;
	pp(a);
	for(i=0;i<1;i++)
		for(j=0;j<1;j++)
			printf("%d ",a[i][j]);

}

