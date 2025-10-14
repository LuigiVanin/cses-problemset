#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

int main() {
  int n;
  std::cin >> n;
  std::vector<ll> arr(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr.begin(), arr.end());

  ll median = arr[n / 2];
  ll cost = 0;

  for (int i = 0; i < n; i++) {
    cost += std::abs(arr[i] - median);
  }

  std::cout << cost << "\n";
  return 0;
}
