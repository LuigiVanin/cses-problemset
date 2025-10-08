#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

#define ll long long

int main() {
  ll n;
  std::cin >> n;
  std::vector<ll> darr(n, 0);
  ll r = -LONG_LONG_MAX;

  for (ll i = 0; i < n; i++) {
    ll x;
    std::cin >> x;

    if (i == 0) {
      darr[0] = x;
      r = x;
      continue;
    }

    auto acc = darr[i - 1];

    if (acc < 0) {
      darr[i] = x;
    } else {
      darr[i] = acc + x;
    }
    r = std::max(r, darr[i]);
  }

  std::cout << r << "\n";

  return 0;
}