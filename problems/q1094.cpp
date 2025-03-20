// Problem "Increasing Array": https://cses.fi/problemset/task/1094
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> array = {};
  int n;

  std::cin >> n;

  for (size_t i = 0; i < n; i++)
  {
    int x;
    std::cin >> x;
    array.push_back(x);
  }

  for (size_t i = 0; i < array.size(); i++)
  {

    std::cout << array[i] << std::endl;
  }

  return 0;
}