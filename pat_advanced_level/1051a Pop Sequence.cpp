#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main()
{
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < k; ++i)
  {
    vector<int> vec;
    queue<int> qu;
    for (int j = 1; j <= n; ++j)
    {
      qu.push(j);
    }
    int stsiz = 0;
    stack<int> st;
    bool suc = true;
    for (int j = 0; j < n; ++j)
    {
      int tmp;
      scanf("%d", &tmp);
      if (suc == false) continue;
      while (st.empty() || st.top() != tmp)
      {
        if (stsiz == m || qu.empty()) { suc = false; break; }
        int t = qu.front();
        qu.pop();
        st.push(t);
        ++stsiz;
      }
      if (st.top() == tmp)
      {
        st.pop();
        --stsiz;
      }
    }
    if (suc && st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  system("pause");
  return 0;
}