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
        continue;

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

/*
CORRECT ANSWER

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  // Use multiset to store ticket prices (allows duplicates and keeps sorted)
  multiset<int> tickets;

  for (int i = 0; i < n; i++) {
    int price;
    cin >> price;
    tickets.insert(price);
  }

  // Process each customer
  for (int i = 0; i < m; i++) {
    int maxPrice;
    cin >> maxPrice;

    // Find the largest ticket price <= maxPrice
    auto it = tickets.upper_bound(maxPrice);

    if (it == tickets.begin()) {
      // No ticket with price <= maxPrice exists
      cout << -1 << "\n";
    } else {
      // Move iterator back to get the largest price <= maxPrice
      --it;
      cout << *it << "\n";
      // Remove this ticket as it's sold
      tickets.erase(it);
    }
  }

  return 0;
}
*/