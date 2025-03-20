// Problem "Repetition": https://cses.fi/problemset/task/1069
#include <iostream>

int main()
{
  std::string dna;
  char current = 0;
  long long max = 1;
  long long count = 0;

  std::cin >> dna;

  for (const char c : dna)
  {

    if (current != c)
    {
      current = c;
      count = 1;
    }
    else
    {
      count++;
      max = std::max(count, max);
    }
  }

  std::cout << max << std::endl;

  return 0;
}