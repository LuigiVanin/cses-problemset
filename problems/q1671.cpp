#include <iostream>
#include <vector>

int main()
{
  std::cout << "Hello, World!" << std::endl;

  int n, m;

  std::cin >> n >> m;

  // pair<int, int> = pair<target, weight>
  std::vector<std::vector<std::pair<int, int>>> graph(
    n, std::vector<std::pair<int, int>>());

  for (int i = 0; i < m; i++)
  {
    int a, b, weight;
    std::cin >> a >> b >> weight;

    graph[a - 1].push_back({b - 1, weight});
    graph[b - 1].push_back({a - 1, weight});
  }
}