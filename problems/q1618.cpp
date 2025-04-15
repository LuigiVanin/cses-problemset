// https://cses.fi/problemset/task/1618
#include <iostream>
#include <cmath>
#define ll long long

/*
To understand how trailing zeros are generated in a factorial (n!), we need to analyze its prime factorization,
specifically the factors of 5 and 2. A trailing zero is formed by the multiplication of an even number multiplied
by a factor of 5.

In any factorial greater than or equal to 2!, the number of factors of 2 will always be greater than or equal to
the number of factors of 5. Therefore, the number of trailing zeros in n! is determined by the number of times
5 appears as a prime factor in the numbers from 1 to n.

Let's examine some examples:

- 5! = 1 × 2 × 3 × 4 × 5 = 120  ➡️ One trailing zero (one factor of 5).

- 10! = 1 × 2 × 3 × 4 × 5 × 6 × 7 × 8 × 9 × 10 = 3,628,800 ➡️ Two trailing zeros (factors of 5 come from 5 and 10 (2 × 5)).

- 15! will have three trailing zeros (from 5, 10 (2 × 5), and 15 (3 × 5)).

The pattern continues, but we need to be careful with multiples of higher powers of 5:

- 25! = 1 × ... × 5 × ... × (10 = (2 × 5)) × ... × (15 = (3 × 5)) × ... × (20 = (4 × 5)) × ... × 25 (5 × 5)  ➡️ 6 trailing zeros.
Notice that 25 contributes two factors of 5.

- Similarly, 125 (5 × 5 × 5) would contribute three factors of 5, and so on.

Therefore, to find the number of trailing zeros in n!, we need to count the number of multiples of 5 less than
or equal to n, then add the number of multiples of 5^2 (which contribute an additional factor of 5), then add
the number of multiples of 5^3, and so on, until the power of 5 exceeds n.

In this manner we can determine the number of trailing zeros in n! without explicitly computing the factorial
itself.
*/
int main()
{
  ll n;
  ll count = 0;
  ll acc = 5;
  std::cin >> n;

  while (acc <= n)
  {
    count += (ll)(n / acc);
    acc *= 5;
  }

  std::cout << count;
  return 0;
}