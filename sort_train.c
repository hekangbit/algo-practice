#include <stdio.h>

void quick_sort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int flag = 0;
	int tmp = arr[i];

	if (i < j)
	{
		while (i < j)
		{
#if 0
			if (flag == 0)
			{
				if (arr[j] < tmp)
				{
					arr[i] = arr[j];
					flag = 1;
					continue;
				}
				else
				{
					j--;
				}
			}
			else
			{
				if (arr[i] > tmp)
				{
					arr[j] = arr[i];
					flag = 0;
					continue;
				}
				else
				{
					i++;
				}
			}
#else
			while (arr[j] > tmp && i < j)
				j--;
			arr[i] = arr[j];
			while (arr[i] < tmp && i < j)
				i++;
			arr[j] = arr[i];

#endif
		}

		arr[i] = tmp;

		quick_sort(arr, left, i - 1);
		quick_sort(arr, j + 1, right);
	}
	else
	{
		return;
	}
}

void print_buf(int buf[], int size)
{
	int i = 0;
	for (; i < size; i++)
		printf("%d, ", buf[i]);
	printf("\n");
}

void maopao_sort(int arr[], int n)
{
	int i = 0;
	int j = 0;
	int tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int bsearch(int arr[], int n, int target)
{
	int low = 0;
	int high = n - 1;
	int mid;
	int tmp;

	while (low <= high)
	{
		mid = (high + low) / 2;
		tmp = arr[mid];
		if (target == tmp)
			return mid;
		else if(target < tmp)
			high = mid - 1;
		else if(target > tmp)
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int test[] = {1,11,100,5,4,78,11,23,14,2,45};
	print_buf(test, sizeof(test)/sizeof(int));
	quick_sort(test, 0, sizeof(test)/sizeof(int) - 1);
	print_buf(test, sizeof(test)/sizeof(int));
	
	int test2[] = {1,11,100,5,4,78,11,23,14,2,45};
	print_buf(test2, sizeof(test)/sizeof(int));
	maopao_sort(test2, sizeof(test)/sizeof(int));
	print_buf(test2, sizeof(test)/sizeof(int));
	printf("find 23, index is %d", bsearch(test2, sizeof(test)/sizeof(int), 23));
	return 0;
}
