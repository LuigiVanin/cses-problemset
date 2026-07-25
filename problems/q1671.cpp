#include <climits>
#include <iostream>
#include <set>
#include <vector>

#define ll long long

void dijkstra(int                                                 src,
              const std::vector<std::vector<std::pair<int, ll>>> &graph,
              std::vector<bool>                                  &visited,
              std::vector<ll>                                    &distances)
{

  // First Try implementing Dikjstra
  // std::queue<int> q;
  // q.push(src);
  // distances[src] = 0;

  // while (!q.empty())
  // {
  //   auto curr = q.front();
  //   q.pop();

  //   visited[curr] = true;

  //   for (const auto node : graph[curr])
  //   {
  //     if (!visited[node.first])
  //     {
  //       q.push(node.first);
  //     }

  //     auto acc_dist = distances[curr] + node.second;
  //     if (acc_dist < distances[node.first])
  //     {
  //       distances[node.first] = acc_dist;
  //     }
  //   }
  // }

  // Second Try implementing Dikjstra - TIME LIMIT EXCEEDED
  // distances[src] = 0;

  // for (const auto &_ : graph)
  // {
  //   auto min_dist = LONG_LONG_MAX;
  //   auto min_id   = -1;

  //   for (int i = 0; i < (int)graph.size(); i++)
  //   {
  //     if (!visited[i] && distances[i] < min_dist)
  //     {
  //       min_dist = distances[i];
  //       min_id   = i;
  //     }
  //   }

  //   if (min_id == -1) return;
  //   visited[min_id] = true;

  //   auto node = graph[min_id];

  //   for (auto &neighbor : node)
  //   {
  //     auto acc_dist = distances[min_id] + neighbor.second;

  //     if (acc_dist < distances[neighbor.first])
  //     {
  //       distances[neighbor.first] = acc_dist;
  //     }
  //   }
  // }

  // THIRD IMPLEMENTATION and more optimal!
  // PRIORITY QUEUE IMPLEMENTADO COM SET pair<dist, node>
  std::set<std::pair<ll, int>> pq;
  pq.insert({0, src});
  distances[src] = 0;

  while (!pq.empty())
  {
    auto current                      = *pq.begin();
    auto [current_weight, current_id] = current;

    // POP for set structure
    pq.erase(pq.begin());

    visited[current_id] = true;

    for (const auto &neighbor : graph[current_id])
    {
      auto [neighbor_id, neighbor_weight] = neighbor;
      auto acc_weight                     = current_weight + neighbor_weight;

      if (acc_weight < distances[neighbor_id])
      {
        // REMOVENDO CHAVE ANTIGA USANDO VALORES EXATOS DE WEIGHT e ID
        pq.erase({distances[neighbor_id], neighbor_id});

        distances[neighbor_id] = acc_weight;
        pq.insert({acc_weight, neighbor_id});
      }
    }
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  // pair<int, int> = pair<target, weight>
  std::vector<std::vector<std::pair<int, ll>>> graph(
    n, std::vector<std::pair<int, ll>>());
  std::vector<ll> distances(n, LONG_LONG_MAX);
  //                             ^ IT MUST BE LONG_LONG_MAX OTHERWISE "expected
  //                             "x"(x > INT_MAX), got INT_MAX"
  std::vector<bool> visited(n, false);

  for (int i = 0; i < m; i++)
  {
    int a, b, weight;
    std::cin >> a >> b >> weight;

    graph[a - 1].push_back({b - 1, weight});
    // graph[b - 1].push_back({a - 1, weight});
    // ^ MAJOR ERROR HERE - "... Each flight is a one-way flight."
  }

  dijkstra(0, graph, visited, distances);

  for (const auto &d : distances) std::cout << d << " ";
  std::cout << "\n";
}