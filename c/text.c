#include<stdio.h>
#include<stdlib.h>
void add(int **p);
int main(void)
{
	int *n;
	int h=9;
	n=&h;
	
	add(&n);
}
void add(int **p)
{
	printf("%d\n",**p+9);
}
