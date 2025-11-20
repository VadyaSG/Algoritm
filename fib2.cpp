#include<iostream>
#include<vector>

int fib(int n)
{
    if (n <= 1) return n; 
    vector<int> num(n + 1);
    num[0]{ 0 };
    num[1]{ 1 };

    for (int i{2}; i <= n; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
        return num[n];
    }
}

  int main() 
    {
      int n{ 20 };
        for (int i{ 0 }; i < n; ++i)
        {
            std::cout << fib(i)<<" ";
        }
        std::cout << std::endl;
        return 0;
    }




