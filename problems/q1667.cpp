#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

void bfs(const std::vector<std::vector<int>> &graph,
         std::vector<bool>                   &visited,
         std::vector<int>                    &distances,
         const int                            src)
{
  std::queue<int> q;
  q.push(src);
  visited[src]   = true;
  distances[src] = 0;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for (const auto neighbor : graph[current])
    {
      if (!visited[neighbor])
      {
        visited[neighbor]   = true;
        distances[neighbor] = distances[current] + 1;
        q.push(neighbor);
      }
    }
  }
}

std::vector<int> traceback(const int                            src,
                           const int                            dest,
                           const std::vector<std::vector<int>> &graph,
                           std::vector<int>                    &distances)
{
  std::vector<int> path(1, dest);

  int target = dest;

  while (target != src)
  {
    int min_d_neighbor = INT_MAX;
    for (const auto neighbor : graph[target])
      if (min_d_neighbor > distances[neighbor])
      {
        min_d_neighbor = distances[neighbor];
        target         = neighbor;
      };

    path.push_back(target);
  }

  std::reverse(path.begin(), path.end());
  return path;
}

int main()
{
  int n, m;

  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n, std::vector<int>());
  std::vector<bool>             visited(n, false);
  std::vector<int>              distances(n, INT_MAX);

  for (int i = 0; i < m; i++)
  {
    int origin, dest;
    std::cin >> origin >> dest;

    graph[origin - 1].push_back(dest - 1);
    graph[dest - 1].push_back(origin - 1);

    // std::cout << origin << " <-> " << dest << std::endl;
  }

  int origin = 0;     // 1
  int target = n - 1; // n

  bfs(graph, visited, distances, origin);

  // std::cout << "\nVISITED: [";
  // for (const auto item : visited) std::cout << item << ", ";
  // std::cout << "]\n";

  // std::cout << "\nDISTANCE: [";
  // for (const auto item : distances) std::cout << item << ", ";
  // std::cout << "]\n";

  if (!visited[target])
  {
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
  }

  auto path = traceback(origin, target, graph, distances);

  std::cout << path.size() << "\n";
  for (const auto item : path) std::cout << item + 1 << " ";
  std::cout << "\n";

  return 0;
}
