#include<iostream>

const int smax{ 1000 };

void merger(int* arr, int left, int right);
void merge_sort_recursive(int* arr, int left, int right);
void merge_sort(int* arr, int size);
void print(int arr[], int size);

int main()
{
	const int size_a{ 10 };
	int arr_a[size_a]{ 3,43,38,29,18,72,57,61,2,33 };

	const int size_b{15};
	int arr_b[size_b]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };

	const int size_c{18};
	int arr_c[size_c]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0,7, 59, 90, 84, 60, 95, 62 };

	int mid = size_a / 2;

	std::cout << "begin arr: ";
	print(arr_a, size_a);
	merge_sort(arr_a,size_a);
	std::cout << "sorted arr: ";
	print(arr_a, size_a);

	std::cout << "begin arr: ";
	print(arr_b, size_b);
	merge_sort(arr_b, size_b);
	std::cout << "sorted arr: ";
	print(arr_b, size_b);

	std::cout << "begin arr: ";
	print(arr_c, size_c);
	merge_sort(arr_c, size_c);
	std::cout << "sorted arr: ";
	print(arr_c, size_c);


	return 0;
}

void merger(int* arr,int start,int end)
{
	int i = start;
	int mid = start + (end - start) / 2;
	int j = mid + 1;
	int k = 0;
	int d[smax];

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			d[k] = arr[i]; 
			++i;
		}
		else
		{
			d[k] = arr[j]; 
			++j;
		}
		++k;
	}
	while (i <= mid)
	{
		d[k] = arr[i];
		++i;
		++k;
	}
	while (j <= end)
	{
		d[k] = arr[j];
		++j;
		++k;
	}
	for (i = 0; i < k; ++i)
	{
		arr[start + i] = d[i];
	}
}

void merge_sort_recursive(int* arr,int left,int right)
{
	int temp{ 0 };
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort_recursive(arr, left,mid);
		merge_sort_recursive(arr, mid+1,right);
		merger(arr, left, right);
	}
	
}
void merge_sort(int* arr, int size)
{
	merge_sort_recursive(arr, 0, size - 1);
}
void print(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
