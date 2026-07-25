#include <climits>
#include <iostream>
#include <queue>
#include <vector>

void bellman(const int                                            src,
             const std::vector<std::vector<std::pair<int, int>>> &graph,
             std::vector<bool>                                   &affected)
{
  std::queue<int> q;
  q.push(src);

  while (!q.empty())
  {
    auto curr = q.front();
    q.pop();

    for (const auto &[neighbor, weight] : graph[curr])
    {
      if (!affected[neighbor])
      {
        affected[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main()
{
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> graph(
    n, std::vector<std::pair<int, int>>());
  std::vector<std::tuple<int, int, int>> edges;

  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    std::cin >> a >> b >> w;

    graph[a - 1].push_back({b - 1, w});
    edges.push_back({a - 1, b - 1, w});
  }

  std::vector<long long> distances(n, LLONG_MIN);
  distances[0] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    for (const auto &[u, v, w] : edges)
    {
      if (distances[u] != LLONG_MIN && distances[u] + w > distances[v])
        distances[v] = distances[u] + w;
    }
  }

  std::vector<bool> affected(n, false);

  for (const auto &[u, v, w] : edges)
  {
    if (distances[u] != LLONG_MIN && distances[u] + w > distances[v])
      affected[v] = true;
  }

  for (int i = 0; i < n; i++)
    if (affected[i]) bellman(i, graph, affected);

  if (affected[n - 1])
  {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::cout << distances[n - 1] << std::endl;

  return 0;
}
