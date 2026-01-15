// Problem "Increasing Array": https://cses.fi/problemset/task/1094
#include <cstddef>
#include <iostream>
#define ll long long

int main()
{
  int n;
  ll  prev  = 0;
  ll  moves = 0;

  std::cin >> n;

  for (size_t i = 0; i < (size_t)n; i++)
  {
    ll x;
    std::cin >> x;

    if (prev > x)
    {
      moves += prev - x;
      x = prev;
    }

    prev = x;
  }

  std::cout << moves << std::endl;

  return 0;
}