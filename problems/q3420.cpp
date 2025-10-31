#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
int binarySearch(std::vector<T> v, T target)
{
  int start = 0, end = v.size();

  while (start < end)
  {

    int mid = std::floor((start + end) / 2);
    if (v[mid] == target) return mid;
    if (v[mid] > target)
      end = mid;
    else
      start = mid + 1;
  }

  return -1;
}

int main()
{
  std::cout << "Hello, World!\n";

  std::vector<int> v;

  v.push_back(1);
  v.push_back(12);
  v.push_back(19);
  v.push_back(30);
  v.push_back(31);
  v.push_back(45);
  v.push_back(52);
  v.push_back(59);
  v.push_back(61);
  v.push_back(67);
  v.push_back(69);
  v.push_back(75);
  v.push_back(78);
  v.push_back(91);

  std::cout << "[";
  for (int i = 0; i < (int)v.size(); i++) std::cout << v[i] << ", ";
  std::cout << "]\nsize: " << v.size() << "\n\n";

  auto idx = binarySearch(v, 91);

  std::cout << idx << ": " << v[idx] << "\n";

  return 0;
}