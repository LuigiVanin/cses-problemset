#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

#define ll long long

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> tickets(n, 0);
  std::vector<int> customers(m, 0);
  std::vector<int> result(m, -1);
  std::map<int, int> map;

  for (int i = 0; i < n; i++) {
    std::cin >> tickets[i];
    auto count = map[tickets[i]];

    map[tickets[i]] = count + 1;
  }

  for (int i = 0; i < m; i++)
    std::cin >> customers[i];

  std::sort(tickets.begin(), tickets.end());

  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      auto count = map[tickets[j]];

      if (!count)
        break;

      if (customers[i] >= tickets[j]) {
        result[i] = tickets[j];
        map[tickets[j]] = count - 1;
        break;
      }
    }
  }

  for (const auto &x : result) {
    std::cout << x << "\n";
  }

  return 0;
}
