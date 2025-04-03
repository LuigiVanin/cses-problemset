// Problem "TWO KNIGHTS": https://cses.fi/problemset/task/1072
#include <iostream>
#define ll long long

int main()
{
  ll n;

  std::cin >> n;

  for (ll k = 1; k <= n; k++)
  {
    if (k == 1)
    {
      std::cout << 0 << std::endl;
      continue;
    }
    // Same shit but a little prettier ⬇️
    // ll fk = ((k * k * (k - 1)) / 2) - (4 * (k - 1) * (k - 2));
    ll fk = ((((k * k) * (k * k)) - (k * k)) / 2) - (4 * (k - 1) * (k - 2));

    std::cout << fk << std::endl;
  }

  return 0;
}