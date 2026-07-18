#include <cstddef>
#include <iostream>
#include <vector>

bool found = false;

void backtrack(int                     src,
               int                     neighbor,
               const std::vector<int> &parents,
               std::vector<int>       &path)
{

  path.push_back(neighbor);
  auto curr = src;

  while (curr != neighbor)
  {
    path.push_back(curr);
    curr = parents[curr];
  }

  path.push_back(curr);
}

void dfs(const std::vector<std::vector<int>> &graph,
         std::vector<bool>                   &visited,
         std::vector<int>                    &parents,
         std::vector<int>                    &path,
         const int                            src)
{
  visited[src] = 1;
  if (found) return;

  for (size_t i = 0; i < graph[src].size(); i++)
  {
    auto neighbor = graph[src][i];
    if (!visited[neighbor])
    {
      parents[neighbor] = src;
      dfs(graph, visited, parents, path, neighbor);
    }
    else if (visited[neighbor] && neighbor != parents[src] && !found)
    {
      found = true;
      backtrack(src, neighbor, parents, path);
      return;
    }
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n, std::vector<int>());

  for (int i = 0; i < m; i++)
  {
    int a, b;

    std::cin >> a >> b;

    // normalizing relation (-1) graph ID -> vector index
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  // for (int i = 0; i < (int)graph.size(); i++)
  // {
  //   std::cout << i << ": ";
  //   for (int j = 0; j < (int)graph[i].size(); j++)
  //   {
  //     std::cout << graph[i][j] << " ";
  //   }

  //   std::cout << std::endl;
  // }

  std::vector<bool> visited(n);
  std::vector<int>  parents(n, -1);
  std::vector<int>  path;

  for (size_t i = 0; i < graph.size(); i++)
  {
    if (!visited[i] && path.empty()) dfs(graph, visited, parents, path, i);
  }

  if (path.size() == 0)
  {
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
  }

  std::cout << path.size() << std::endl;
  for (const auto item : path) std::cout << item + 1 << " ";
  std::cout << std::endl;

  return 0;
}