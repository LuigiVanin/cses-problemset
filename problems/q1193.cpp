#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

const std::pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

std::vector<char>
traceback(const std::vector<std::vector<int>> &distances, int x, int y)
{
  std::vector<char> path;
  int               cur_dist = distances[x][y];

  char moves[] = {'L', 'R', 'U', 'D'};

  while (cur_dist > 0)
  {
    for (int i = 0; i < 4; i++)
    {
      int dx = x + directions[i].first;
      int dy = y + directions[i].second;

      int n = distances.size();
      int m = distances[0].size();

      if (dx >= 0 && dx < n && dy >= 0 && dy < m)
        if (distances[dx][dy] == cur_dist - 1)
        {
          path.push_back(moves[i]);
          x = dx;
          y = dy;
          cur_dist--;
          break;
        }
    }
  }
  std::reverse(path.begin(), path.end());
  return path;
}

bool isValid(const std::vector<std::vector<char>> &grid, int x, int y)
{
  int n = grid.size();
  int m = grid[0].size();

  return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void bfs(const std::vector<std::vector<char>> &grid,
         std::vector<std::vector<bool>>       &visited,
         std::vector<std::vector<int>>        &distances,
         const int                             x,
         const int                             y)
{
  std::queue<std::pair<int, int>> q;

  q.push({x, y});

  while (!q.empty())
  {
    auto current = q.front();

    visited[current.first][current.second] = true;
    q.pop();

    for (const auto &d : directions)
    {
      std::pair<int, int> target = {current.first + d.first,
                                    current.second + d.second};

      if (isValid(grid, target.first, target.second) &&
          !visited[target.first][target.second])
      {
        visited[target.first][target.second] = true;
        auto target_d = distances[current.first][current.second] + 1;
        distances[target.first][target.second] = target_d;
        q.push(target);
      }
    }
  }
}

int main()
{
  int rows, cols;

  std::cin >> rows >> cols;

  std::pair<int, int> start = {0, 0};
  std::pair<int, int> end   = {0, 0};

  std::vector<std::vector<bool>> visited(rows, std::vector(cols, false));
  std::vector<std::vector<char>> grid(rows, std::vector(cols, '#'));

  std::vector<std::vector<int>> distances(rows, std::vector(cols, INT_MAX));

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
    {
      std::cin >> grid[i][j];
      if (grid[i][j] == 'A') start = {i, j};
      if (grid[i][j] == 'B') end = {i, j};
    }

  distances[start.first][start.second] = 0;

  bfs(grid, visited, distances, start.first, start.second);

  if (visited[end.first][end.second])
  {
    std::cout << "YES" << "\n";
    std::cout << distances[end.first][end.second] << "\n";
    auto path = traceback(distances, end.first, end.second);
    for (const auto &c : path) std::cout << c;
    std::cout << "\n";
  }
  else
    std::cout << "NO" << "\n";

  return 0;
}