// Missing Number: https://cses.fi/problemset/result/12374079/

#include <iostream>

int main()
{
  int n;
  int sum = 0;
  int total_sum = 1;

  // The total sum can also be found by using the Mathemitcal formula for Sum of linear sequence of numbers ⬇️
  // (n * (n + 1)) / 2 ➡️ Euler formulas

  std::cin >> n;

  for (int i = 1; i < n; i++)
  {
    int x;
    std::cin >> x;

    sum += x;
    total_sum += (i + 1);
  }

  std::cout << (total_sum - sum) << std::endl;

  return 0;
}