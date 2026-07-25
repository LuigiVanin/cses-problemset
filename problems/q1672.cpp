#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

const ll INF = 1e18;

void floydwarshall(std::vector<std::vector<ll>> &dist, const int n)
{
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
}

int main()
{
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<std::vector<ll>> dist(n, std::vector<ll>(n, INF));

  for (int i = 0; i < n; i++) dist[i][i] = 0;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    ll  weight;
    std::cin >> a >> b >> weight;

    dist[a - 1][b - 1] = std::min(dist[a - 1][b - 1], weight);
    dist[b - 1][a - 1] = std::min(dist[b - 1][a - 1], weight);
  }

  floydwarshall(dist, n);

  for (int i = 0; i < q; i++)
  {
    int a, b;
    std::cin >> a >> b;

    ll d = dist[a - 1][b - 1];
    std::cout << (d == INF ? -1 : d) << "\n";
  }

  return 0;
}
