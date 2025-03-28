// Problem "PERMUTATION": https://cses.fi/problemset/task/1070
#include <iostream>
#define ll long long

int main()
{
  ll n;
  std::cin >> n;

  if (n == 1)
  {
    std::cout << 1 << std::endl;
    return 0;
  }
  else if (n < 4)
  {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  for (ll i = 2; i <= n; i += 2)
    std::cout << i << " ";
  for (ll i = 1; i <= n; i += 2)
    std::cout << i << " ";
  return 0;
}

/* ALTERNATIVE SOLUTION
// NOTE: This was my first though on how to solve the problem, but couldnt work around the "4"
//       input, so I figured out the solution abova
#include <iostream>
#include <cmath>
#define ll long long


int main()
{
  ll n;
  std::cin >> n;

  if (n == 1)
  {
    std::cout << 1;
    return 0;
  }
  else if (n < 4)
  {
    std::cout << "NO SOLUTION";
    return 0;
  }
  else if (n == 4)
  {
    std::cout << "2 4 1 3";
    return 0;
  }

  ll half = n % 2 != 0
                ? (ll)std::ceil((n - 1) / 2)
                : (ll)std::ceil(n / 2);

  for (ll i = 0; i < half; i++)
  {
    if (i == std::ceil(half / 2) && n % 2 != 0)
      std::cout << n << " ";
    std::cout << i + 1 << " ";
    std::cout << half + i + 1 << " ";
  }

  return 0;
}
*/