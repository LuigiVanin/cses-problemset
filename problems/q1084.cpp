// https://cses.fi/problemset/task/1084
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main()
{
  ll n,              // number applicants
      m,             // number apartaments
      k;             // diff
  std::vector<ll> a; // applicants array
  std::vector<ll> b; // apartaments array

  std::cin >> n >> m >> k;

  for (ll i = 0; i < n; i++)
  {
    ll z;
    std::cin >> z;
    a.push_back(z);
  }

  for (ll j = 0; j < m; j++)
  {
    ll x;
    std::cin >> x;
    b.push_back(x);
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  ll i = 0,      // applicants index
      j = 0,     // apartament index
      count = 0; // match count

  while (i < n && j < m)
  {
    if (b[j] >= (a[i] - k) && b[j] <= (a[i] + k))
    {
      count++;
      i++;
      j++;
    }
    else if (b[j] > (a[i] + k))
      i++;
    else
      j++;
  }

  std::cout << count << std::endl;

  return 0;
}