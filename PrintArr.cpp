#include<iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);

int main()
{
	setlocale(LC_ALL, "Russian");

	int actual_size{};
	int logicaal_size{};

	std::cout << "Введите фактический размер массива: ";
	std::cin >> actual_size;

	std::cout << "Введите логический размер массива: ";
	std::cin >> logicaal_size;

	if (logicaal_size > actual_size)
	{
		std::cout << "Логический размер не может быть больше фактического! "<<std::endl;
		return 1;
	}
	int* arr = new int[actual_size];
	std::cout << "Введите: " << logicaal_size << " Элементов массива: "<<std::endl;

	for (int i{ 0 }; i < logicaal_size; ++i)
	{
		std::cout << "Введите Arr[" << i << "]: ";
		std::cin >> arr[i];
	}

	std::cout << "Полученный массив: ";
	print_dynamic_array(arr, logicaal_size, actual_size);
	delete[]arr;
	return 0;

}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int i{ 0 }; i < actual_size; ++i)
	{
		if (i < logical_size)
		{
			std::cout << arr[i] << " ";
		}
		else
		{
			std::cout << "_ ";
		}
	}
	std::cout << std::endl;
}