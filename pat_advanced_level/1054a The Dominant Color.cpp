#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main()
{
  int m, n;
  cin >> m >> n;
  unordered_map<long long, int > map;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      int tmp;
      scanf("%lld",&tmp);
      ++map[tmp];
    }
  }
  long long maxe = 0;
  int tag;
  for (unordered_map<long long, int>::iterator it = map.begin(); it != map.end();++it)
    if (it->second>maxe) { tag = it->first; maxe = it->second; }
  cout << tag << endl;
  system("pause");
  return 0;
}