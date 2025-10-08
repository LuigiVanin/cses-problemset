#include <iostream>
#include <map>
#include <ostream>

#define ll long long

int main() {
  std::map<int, int> m;
  int n, x;

  std::cin >> n >> x;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    if (a > x)
      continue;

    // TRICKY: if you try to access(read) a map using the `m[key]` notation you
    //         will initiate the key you are trying to read
    //         this can make the `m.count` method return `true` for the current
    //         key even so you didnt explicit set any value just read the key.
    //         To reliably access a map information without messing with
    //         `m.count` use `m.at`.
    if (m.count(x - a)) {
      int index = m[x - a];
      std::cout << index + 1 << " " << i + 1 << "\n";
      return 0;
    }

    m[a] = i;
  }

  std::cout << "IMPOSSIBLE\n";

  return 0;
}