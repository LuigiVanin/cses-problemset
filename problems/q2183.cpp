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

  // The default value for the result should be the minimun possible subarrat
  // sum, in this case will be always represented by the [1] subarray.
  ll val = 1;

  for (int i = 0; i < n; i++) {

    if (val < arr[i]) {
      std::cout << val << "\n";
      return 0;
    }

    val += arr[i];
  }

  std::cout << val << "\n";
  return 0;
}