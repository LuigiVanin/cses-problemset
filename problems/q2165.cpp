// Tower of Hanoi https://cses.fi/problemset/task/2165
#include <iostream>
#include <vector>

void hanoi(
    std::vector<std::pair<int, int>> *result,
    int disc_count,
    int src,
    int dest,
    int aux)
{

  if (disc_count == 1)
  {
    result->push_back({src, dest});
    return;
  }

  hanoi(result, disc_count - 1, src, aux, dest);
  result->push_back({src, dest});
  hanoi(result, disc_count - 1, aux, dest, src);
  return;
}

int main()
{
  int n;
  std::vector<std::pair<int, int>> r;
  std::cin >> n;

  hanoi(&r, n, 1, 3, 2);
  std::cout << r.size() << std::endl;

  for (const auto &pair : r)
  {
    std::cout << pair.first << " " << pair.second << std::endl;
  }

  return 0;
}