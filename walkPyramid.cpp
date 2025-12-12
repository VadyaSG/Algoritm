#include<iostream>
#include<vector>
#include<string>

void print_pyramid(const std::vector<int>& pyramid);

int main()
{
	int current_index{ 0 };
	std::string command;
	std::vector<int> pyramid = { 1, 3, 6, 5, 9, 8 };

	std::cout << "The original array: ";
	for (int val : pyramid)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
	std::cout << "Pyramid: " << std::endl;
	print_pyramid(pyramid);

	while (true)
	{
		std::cout << "You are here: ";
		int level = 0;
		int count = 1;
		while (current_index >= count)
		{
			++level;
			count += (1 << level);
		}
		std::cout << "Level" << level << ": ";
		if (current_index == 0)
		{
			std::cout << "root " << pyramid[current_index] << std::endl;
		}
		else
		{
			int  parent_index = (current_index - 1) / 2;
			std::cout << (current_index % 2 == 1 ? "left" : "right") << "(" << pyramid[parent_index] << ") " << pyramid[current_index] << std::endl;
		}
		std::cout << "Where would you like to go? (up, left, right, exit):";
		std::cin >> command;

		if (command == "up")
		{
			if (current_index == 0)
			{
				std::cout << "Parent is missing." << std::endl;
			}
			else
			{
				current_index = (current_index - 1) / 2;
				std::cout << "Ok" << std::endl;
			}
		}
		else if (command == "left")
		{
			int left_child_index = 2 * current_index + 1;
			if (left_child_index >= pyramid.size())
			{
				std::cout << "Error! left child is missing." << std::endl;
			}
			else
			{
				current_index = left_child_index;
				std::cout << "OK" << std::endl;
			}
		}
		else if (command == "right")
		{
			int right_child_index = 2 * current_index + 2;
			if (right_child_index >= pyramid.size())
			{
				std::cout << "Error! right child is missing." << std::endl;
			}
			else
			{
				current_index = right_child_index;
				std::cout << "Ok" << std::endl;
			}
		}
		else if (command == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Unknown command." << std::endl;

	}
}
	return  0;
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