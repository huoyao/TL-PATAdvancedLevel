#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char str[2005];

int main()
{
  int cnt = 0;
  char c;
  str[cnt++] = '&';
  while (c = getchar())
  {
    str[cnt++] = '#';
    str[cnt++] = c;
    if (c == '\n') break;
  }
  int mx = 0, mxid = 0, mxcnt = 0;
  vector<int> dp(cnt,0);
  for (int i = 1; i < cnt-1; ++i)
  {
    if (mx>i)
      dp[i] = min(dp[2*mxid-i],mx-i);
    else dp[i] = 1;
    while (str[i + dp[i]] == str[i - dp[i]]) ++dp[i];
    if (dp[i] + i > mx)
    {
      mx = dp[i] + i;
      mxid = i;
    }
    mxcnt = max(mxcnt,dp[i]);
  }
  cout << mxcnt-1 << endl;
  system("pause");
  return 0;
}