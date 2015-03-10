#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <limits>
using namespace std;

const int N = 205, M = 10005;

int main()
{
  int color[N] = { 0 }, allcolor[M],dp[M];
  int n, m,l, cntc = 0,mx=0;
  cin >> n;
  cin >> m;
  for (int i = 1; i <= m; ++i)
  {
    int tmp;
    cin >> tmp;
    color[tmp] = i;
  }
  cin >> l;
  for (int i = 0; i < l; ++i)
  {
    int tmp;
    cin >> tmp;
    if (color[tmp] != 0) allcolor[cntc++] = color[tmp];
  }
  for (int i = 0; i < cntc; ++i)
  {
    dp[i] = 1;
    for (int j = 0; j < i;++j)
      if (allcolor[j] <= allcolor[i] && dp[j] + 1>dp[i]) dp[i] = dp[j] + 1;
    if (dp[i]>mx) mx = dp[i];
  }
  cout << mx << endl;
  system("pause");
  return 0;
}