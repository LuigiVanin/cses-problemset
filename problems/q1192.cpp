#include <iostream>
#include <vector>

const std::pair<int, int> directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(const std::vector<std::vector<char>> &grid, int x, int y)
{
  int n = grid.size();
  int m = grid[0].size();

  return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '.';
}

void dfs(const std::vector<std::vector<char>> &grid,
         std::vector<std::vector<bool>>       &visited,
         const int                             x,
         const int                             y)
{
  visited[x][y] = true;

  for (const auto &dir : directions)
  {
    std::pair<int, int> target = {x + dir.first, y + dir.second};

    if (isValid(grid, target.first, target.second) &&
        !visited[target.first][target.second])

      dfs(grid, visited, target.first, target.second);
  }
}

int main()
{
  int rows, cols;

  std::cin >> rows >> cols;

  std::vector<std::vector<bool>> visited(rows, std::vector(cols, false));
  std::vector<std::vector<char>> grid(rows, std::vector(cols, '#'));
  int                            counter = 0;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) std::cin >> grid[i][j];
  // std::cout << grid[i][j] << "";
  // std::cout << "\n";

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (grid[i][j] == '.' && !visited[i][j])
      {
        counter++;
        dfs(grid, visited, i, j);
      }

  std::cout << counter << "\n";

  return 0;
}