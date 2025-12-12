#include<iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int new_element);
  
int main()
{
    setlocale(LC_ALL, "Russian");

    int actual_size{};
    int logical_size{};
    int new_element;

   std::cout << "Введите фактический размер массива: ";
   std::cin >> actual_size;
   std::cout << "Введите логический размер массива: ";
   std::cin >> logical_size;

   if (logical_size > actual_size)

       {
           std::cout << "Логический размер не может быть больше фактического! " << std::endl;
           return 1;
       }

   int* arr = new int[actual_size];
   std::cout << "Введите элементы массива (" << logical_size << " элементов):" << std::endl;

   for (int i{ 0 }; i < logical_size; ++i)
   {
       std::cout << "Введите arr[" << i << "]: ";
       std::cin >> arr[i];
   }

   std::cout<< "Динамический массив: ";
   print_dynamic_array(arr, logical_size,actual_size);

   while (true)
   {
       std::cout << "Введите элемент для добавления (или 0 для завершения): ";
       std::cin >> new_element;

       if (new_element == 0)
       {
           break;
       }
       append_to_dynamic_array(arr, logical_size, actual_size, new_element);
       std::cout << "Массив после добавления: ";
       print_dynamic_array(arr, logical_size,actual_size);

   }

   
   std::cout << "Спасибо! Ваш массив: ";

   print_dynamic_array(arr, logical_size,actual_size);
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
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int new_element)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = new_element;
        ++logical_size;
    }
    else
    {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];
        for (int i{ 0 }; i < logical_size; ++i)
        {
            new_arr[i] = arr[i];
        }
        new_arr[logical_size] = new_element;

        ++logical_size;
        actual_size = new_actual_size;
        delete[]arr;
        arr = new_arr;
    }
}