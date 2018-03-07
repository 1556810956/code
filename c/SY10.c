#include<stdio.h>
#include<stdlib.h>
void MaxHeap(int arr[], const int size)
{

	int j;
	int tmp,parent,child;
	for (j=size - 1; j > 0; --j)
	{

		 parent = j / 2;

		 child = j;
		if (j < size - 1 && arr[j] < arr[j+1])
		{

			++child;

		}

		if (arr[child] > arr[parent])
		{

			 tmp = arr[child];

			arr[child] = arr[parent];

			arr[parent] = tmp;

		}

	}

}

void Heap(int arr[], const int size)
{
	int j,tmp;
	for (j = size; j > 0; --j)
	{

		MaxHeap(arr, j);

		 tmp = arr[0];

		arr[0] = arr[j - 1];

		arr[j - 1] = tmp;

	}

}


int main(void)
{

	int *arr;
	int j,n;
	printf("please input the count's number:\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
	{
		scanf("%d",&arr[j]);
	}
	Heap(arr, n);

	for (j = 0; j < n; ++j)
	{

		printf("%d ",arr[j]);

	}

	printf("\n");

	return 0;

}
