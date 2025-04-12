// https://cses.fi/problemset/task/1618
#include <iostream>
#include <cmath>
#define ll long long

int main()
{
  ll n;
  ll count = 0;
  ll acc = 5;
  std::cin >> n;

  while (acc <= n)
  {
    count += (ll)(n / acc);
    acc *= 5;
  }

  std::cout << count;
  return 0;
}