// Problem "NUMBER SPIRAL": https://cses.fi/problemset/task/1071
#include <iostream>
#define ll long long

int main()
{
  ll n;

  std::cin >> n;
  /* Example 1: row(y) = 3; col(x) = 2

        | 1  2  9  10 |
        | 4  3  8  11 |
row=3 ->| 5  6* 7  12 |
        | 16 18 19 20 |
             ⬆️
              col=2

    - Result: 6
________________________________________

    Example 2: row(y) = 2; col(x) = 3

        | 1  2  9  10 |
row=2 ->| 4  3  8* 11 |
        | 5  6  7  12 |
        | 16 18 19 20 |
                ⬆️
                col=3

    - Result: 8
  */

  for (ll i = 0; i < n; i++)
  {
    ll row, col;
    std::cin >> row >> col;

    ll max = std::max(row, col);
    ll min = std::min(row, col);

    ll diff = max - min; // distance between diagonal and target
    ll offset = max - 1; // offset to find diagonal

    ll k = (max * max) - offset; // diagonal
    ll r = 0;                    // result

    if (col > row)
    {
      if (max % 2 == 0)
        r = k - diff;
      else
        r = k + diff;
    }
    else
    {
      if (max % 2 == 0)
        r = k + diff;
      else
        r = k - diff;
    }

    std::cout << r << std::endl;
  }

  return 0;
}
