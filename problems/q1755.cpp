// https://cses.fi/problemset/task/1755
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#define ll long long

int main()
{
  std::string r = "";
  std::string rtmp = ""; // Variable to store the reversed first half of the polindrome
  std::string input;
  std::map<char, int> m{};
  std::pair<char, int> odd;

  std::cin >> input;

  for (const char x : input)
  {
    int count = m[x];

    if (!count)
    {
      m[x] = 1;
      continue;
    }

    m[x] = count + 1;
  }

  for (const auto &pair : m)
  {
    if (pair.second % 2 != 0 && odd.second)
    {
      std::cout << "NO SOLUTION" << std::endl;
      return 0;
    }

    if (pair.second % 2 != 0 && !odd.second)
    {
      odd = pair;
      continue;
    }

    for (int i = 0; i < (pair.second / 2); i++)
      r.push_back(pair.first);
  }

  for (int i = r.length() - 1; i >= 0; i--)
    rtmp.push_back(r[i]);

  for (int i = 0; i < odd.second; i++)
    r.push_back(odd.first);

  r.append(rtmp);

  std::cout << r << std::endl;
  return 0;
}