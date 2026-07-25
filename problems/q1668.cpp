#include <iostream>
#include <queue>
#include <vector>

bool bfs(int                                  src,
         const std::vector<std::vector<int>> &graph,
         std::vector<bool>                   &visited,
         std::vector<int>                    &teams)
{
  std::queue<int> q;
  q.push(src);
  if (!teams[src])
  {
    teams[src] = 1;
  }

  while (!q.empty())
  {
    auto curr = q.front();
    q.pop();

    for (auto &neighbor : graph[curr])
    {
      if (!teams[neighbor])
        teams[neighbor] = teams[curr] == 1 ? 2 : 1;
      else if (!!teams[neighbor] && teams[neighbor] == teams[curr])
        return true;

      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }

  return false;
}

int main()
{
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n, std::vector<int>());
  std::vector<bool>             visited(n, false);
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
    if (!visited[i])
    {
      auto impossible = bfs(i, graph, visited, teams);
      if (impossible)
      {
        std::cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }

  for (const auto team : teams) std::cout << team << " ";
  std::cout << std::endl;

  return 0;
}