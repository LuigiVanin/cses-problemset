// https://cses.fi/problemset/task/1617
#include <iostream>
#define ll long long

/*
Considering that each bit has the chance of being either 1 or 0, you have 2 options for each of the n bit positions.
This creates a total number of combinations equal to the product of the possibilities for each position:

2 × 2 × ⋯ × 2 (multiplied n times) = 2^n


The catch lies in the necessity of printing the output modulo 10^9 + 7. If you were to directly calculate 2^n
and then try to output it using a standard 64-bit integer type (long long in C++), it would likely exceed
the maximum representable value for larger values of n, leading to incorrect results.

To solve this, it's necessary to apply the properties of modular arithmetic. Specifically, we can use the
following property when dealing with multiplication and exponentiation under a modulus:

(a * b) mod m = ((a mod m) * (b mod m)) mod m

Expanding this to the multiplication we have it would like to something like:

(2 × 2 × ⋯ × 2) mod m

(2 × 2^(n-1)) mod m

((2 mod m) * (2^(n-1) mod m) mod m

and if we keep expanding:

((2 mod m) * ((2 * 2^(n-2)) mod m) mod m

((2 mod m) * (((2 mod m) * (2^(n-2) mod m)) mod m) mod m

having in mind, m = 10^9 + 7,  2 mod m = 2, so:

(2 * (2 * (2^(n-2) mod m)) mod m) mod m

(2 * (2 * (2^(n-2) mod m)) mod m) mod m

(2 * (2 * (2 * 2 *⋯ ((2 mod m) * (2 mod m)) mod m  ⋯) mod m) mod m) mod m) mod m
                        ⋯ (2  * (2^1)) mod m ⋯
                        ⋯ 4 mod m ⋯
                      ⋯ (2 *  4) mod m ⋯
                    ⋯ (2 * 8) mod m ⋯

We can simplify to a algorithm:

for (ll i = 0; i < n; i++)
{
  results *= 2 % MOD;
  results %= MOD;
}
*/

const ll MOD = 1000000007; // <-- 10^9+7

int main()
{

  ll n;
  ll results = 1;
  std::cin >> n;

  for (ll i = 0; i < n; i++)
  {
    results *= 2;
    results %= MOD;
  }

  std::cout << results % MOD << std::endl;

  return 0;
}