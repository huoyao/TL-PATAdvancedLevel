#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
vector<vector<int> > follow(N, vector<int>());
int l,cnt,tar;
bool vst[1005];

int main()
{
  int n, num, fol;
  cin >> n >> l;
  for (int i = 1; i <= n; ++i)
  {
    cin >> num;
    for (int j = 0; j < num; ++j)
    {
      cin >> fol;
      follow[fol].push_back(i);
    }
  }
  cin >> num;
  for (int i = 0; i < num; ++i)
  {
    cnt = 0;
    cin >> tar;
    for (int i = 1; i <= n; ++i) vst[i] = false;
    queue<int> qu;
    qu.push(tar);
    vst[tar] = true;
    int end = qu.back(),cur=1;
    while (!qu.empty() && cur<=l)
    {
      int idx = qu.front();
      qu.pop();
      for (int i = 0; i < follow[idx].size(); ++i)
      {
        if (!vst[follow[idx][i]])
        {
          ++cnt;
          vst[follow[idx][i]] = true;
          qu.push(follow[idx][i]);
        }
      }
      if (end == idx)
      {
        end = qu.back();
        ++cur;
      }
    }
    cout << cnt << endl;
  }
  system("pause");
  return 0;
}