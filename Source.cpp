#include<iostream>

int elem(int* arr, int point,int size);

int main()
{
	int size{ 9 };
	int arr[9]{14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int point{};

	std::cout << "Enter the point: ";
	std::cin >> point;
	std::cout << "Count of elem: " << elem(arr, point, size);
	
	return 0;
}

int elem(int* arr, int point,int size)
{
	int low{ 0 };
	int high{ size - 1 };
	int first_index{ size };

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] > point)
		{
			first_index = mid;
			high = mid - 1;
		
		}
		else
		{
			low = mid + 1;
		}
	}
	
	return size - first_index;
}