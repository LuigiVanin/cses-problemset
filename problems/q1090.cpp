#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

#define ll long long

int main() {
  int n, w;

  std::cin >> n >> w;

  std::vector<int> children(n, 0);

  int i = 0, j = n - 1, counter = 0;

  for (int i = 0; i < n; i++)
    std::cin >> children[i];

  std::sort(children.begin(), children.end());

  while (i <= j) {
    if (children[i] + children[j] <= w)
      i++;

    j--, counter++;
  }

  std::cout << counter << "\n";

  return 0;
}
