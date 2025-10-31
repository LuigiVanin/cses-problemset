#include <iostream>
#include <vector>

int main()
{
  int n;

  std::cin >> n;
  std::vector<int> towers;

  for (int i = 0; i < n; i++)
  {
    int x;
    std::cin >> x;

    // NOTE:
    //      Linear search is too slow, endup exceding accepted time for the
    //      solution
    // bool used = false;
    // for (int i = 0; i < towers.size(); i++) {
    //   if (towers[i] > x) {
    //     towers[i] = x;
    //     used = true;
    //     break;
    //   }
    // }
    // if (!used) {
    //   towers.push_back(x);
    // }

    int start = 0, end = towers.size();
    while (end > start)
    {
      int mid = (start + end) / 2;
      if (towers[mid] > x)
      {
        end = mid;
      }
      else
      {
        start = mid + 1;
      }
    }

    // In case the x value is the greater value of the list, a new tower should
    // be created
    if (start == (int)towers.size()) towers.push_back(x);
    // Otherwise it should add the x value to the lowest closest tower
    else
      towers[start] = x;
  }

  std::cout << towers.size() << "\n";

  return 0;
}