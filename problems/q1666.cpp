#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>> &graph,
         std::vector<bool>                   &visited,
         int                                  src)
{
  visited[src]               = true;
  std::vector<int> neighbors = graph[src];

  for (const auto neighbor : neighbors)
    if (!visited[neighbor]) dfs(graph, visited, neighbor);
}

int main()
{
  int n, m;

  std::cin >> n >> m;
  int counter = 0;

  std::vector<std::vector<int>> graph(n, std::vector<int>());
  std::vector<bool>             visited(n, false);
  std::vector<int>              r;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    std::cin >> a >> b;

    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < (int)visited.size(); i++)
  {
    if (!visited[i])
    {
      dfs(graph, visited, i);
      r.push_back(i + 1);
      counter++;
    }
  }

  std::cout << counter - 1 << "\n";

  for (int i = 0; i < (int)r.size() - 1; i++)
    std::cout << r[i] << " " << r[i + 1] << "\n";

  return 0;
}