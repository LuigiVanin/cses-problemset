// Problem "Weird Algorithm": https://cses.fi/problemset/task/1068
#include <iostream>

int main() {

  long long n;

  std::cin >> n;

  while (true) {
    std::cout << n << " ";

    if (n == 1) break;

    if (n % 2 == 0) // When it is even
    {
      n /= 2;
      continue;
    }

    n = (n * 3) + 1;
  }
  std::cout << std::endl;

  return 0;
}