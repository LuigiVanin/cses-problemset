// https://cses.fi/problemset/task/1621
#include <iostream>
#include <map>

#define ll long long

int main()
{
  std::map<ll, bool> m{};
  ll count = 0;
  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++)
  {
    ll x;
    std::cin >> x;

    bool has = m[x];

    if (!has)
    {
      count++;
      m[x] = true;
    }
  }

  std::cout << count << std::endl;
  return 0;
}