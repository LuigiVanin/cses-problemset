#include <iostream>
#include <queue>
#include <vector>

bool bfs(const std::vector<std::vector<int>> &graph,
         std::vector<int>                    &teams,
         const int                            src)
{
  std::queue<int> q;
  q.push(src);
  teams[src] = 1;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for (const auto neighbor : graph[current])
    {
      if (teams[neighbor] == 0)
      {
        // paint with the opposite team of current (1 -> 2, 2 -> 1)
        teams[neighbor] = 3 - teams[current];
        q.push(neighbor);
      }
      else if (teams[neighbor] == teams[current])
      {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n, std::vector<int>());
  std::vector<int>              teams(n, 0);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    std::cin >> a >> b;

    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++)
  {
    if (teams[i] == 0 && !bfs(graph, teams, i))
    {
      std::cout << "IMPOSSIBLE" << std::endl;
      return 0;
    }
  }

  for (const auto team : teams) std::cout << team << " ";
  std::cout << "\n";

  return 0;
}
