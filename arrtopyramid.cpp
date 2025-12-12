#include<iostream>
#include<vector>

void print_pyramid(const std::vector<int>& pyramid);

int main()
{
	std::vector<int> pyramid = { 1, 3, 6, 5, 9, 8};
	std::cout << "The original array: ";
	for (int val : pyramid)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
	std::cout << "Pyramid: " << std::endl;
	print_pyramid(pyramid);
	return 0;
}

void print_pyramid(const std::vector<int>& pyramid)
{
	for (int i{}; i < pyramid.size(); ++i)
	{
		int level{ 0 };
		int count{ 1 };
		while (i >= count)
		{
			++level;
			count += (1 << level);
		}
		std::cout << "Level " << level << ": ";
		if (i == 0)
		{
			std::cout << "root " << pyramid[i] << std::endl;
		}
		else
		{
			int parent_index = (i - 1) / 2;
			std::cout << (i % 2 == 1 ? "left" : "right") << "(" << pyramid[parent_index] << ") " << pyramid[i] << std::endl;
		}
	}

}