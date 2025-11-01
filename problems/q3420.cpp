#include <iostream>
#include <map>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }

  std::map<int, int> m;
  int                distinct       = 0;
  long long          total_distinct = 0;

  int left = 0;
  for (int right = 0; right < n; right++)
  {
    if (m.contains(arr[right]) == 0)
    {
      distinct++;
    }

    m[arr[right]]++;

    while (m[arr[right]] > 1)
    {
      m[arr[left]]--;

      if (m[arr[left]] == 0)
      {
        distinct--;
      }
      left++;
    }

    total_distinct += distinct;
  }

  std::cout << total_distinct << "\n";
  return 0;
}