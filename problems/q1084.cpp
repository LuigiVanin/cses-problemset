// https://cses.fi/problemset/task/1084
#include <iostream>

#define ll long long

int main()
{
  ll n, m, k;

  std::cin >> n >> m >> k;

  for (ll i = 0; i < n; i++)
  {
    ll z;
    std::cin >> z;
    std::cout << z << std::endl;
  }

  for (ll j = 0; j < m; j++)
  {
    ll x;
    std::cin >> x;
    std::cout << x << std::endl;
  }

  std::cout << "Hello World!";
  return 0;
}