#include<stdio.h>
#include<stdlib.h>
int *ptArr(int n)//建立动态数组
{
	int *arr;
	arr = (int *)malloc(n*sizeof(int));
	return arr;
}
int Elem_arr(int *arr, int n)//给数组元素赋值
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("plz input the num ::");
		scanf("%d", &arr[i]);
	}
	return 0;
}
int get_the_max_min(int *arr, int n, int *nMax, int *nMin)//大小比较
{
	int i;
	*arr = *nMin;
	*nMin = *nMax;
	*nMax = *arr;
	for (i = 0; i < n; i++)
	{
		if (*nMax < arr[i])  *nMax = arr[i];
		if (*nMin > arr[i])  *nMin = arr[i];
	}
	return 0;
}
int main()
{
	int n, nMax, nMin, *arr;
	printf("enter the n::\n");
	scanf("%d", &n);
	arr=ptArr(n);
	Elem_arr(arr, n);
	get_the_max_min(arr, n, &nMax, &nMin);
	printf("the Max=%d\t the Min=%d\n ", nMax,nMin);
	free(arr);
	return 0;
}

